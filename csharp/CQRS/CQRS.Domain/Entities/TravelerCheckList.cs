using CQRS.Domain.Exceptions;
using CQRS.Domain.ValueObjects;
using CQRS.Shared.Abstractions.Domain;

namespace CQRS.Domain.Entities;

public class TravelerCheckList : AggregateRoot<TravelerCheckListId>
{
    public new TravelerCheckListId Id { get; private set; }
    private TravelerCheckListName _name;
    private Destination _destination;
	private readonly LinkedList<TravelerItem> _items = new();

	#region Constructors
	public TravelerCheckList()
    {
    }

    internal TravelerCheckList(
		TravelerCheckListId id,
		TravelerCheckListName name,
		Destination destination
	)
	{
		Id = id;
		_name = name;
		_destination = destination;
	}


	internal TravelerCheckList(
		TravelerCheckListId id,
		TravelerCheckListName name,
		Destination destination,
		LinkedList<TravelerItem> items
	) : this(id, name, destination)
	{
		_items = items;
	}
	#endregion

	#region Operations
	public void AddItem(TravelerItem item)
	{
		var alreadyExists = _items.Any(a => a.Name == item.Name);

		if (alreadyExists)
		{
			throw new TravelerItemAlreadyExistsException(_name, item.Name);
		}

		_items.AddLast(item);
	}

	public void AddItems(IEnumerable<TravelerItem> items)
	{
		foreach (var item in items)
		{
			AddItem(item);
		}
	}

	public void TakeItem(string itemName)
	{
		var item = GetItem(itemName);
		var travelerItem = item with { IsTaken = true };
		_items.Find(item)!.Value = travelerItem;
	}

	public TravelerItem GetItem(string itemName)
	{
		var item = _items.SingleOrDefault(a => a.Name == itemName);
		return item is null ? throw new TravlerItemNotFoundException(itemName) : item;
	}

	public void RemoveItem(string itemName)
	{
		var item = GetItem(itemName);
		_items.Remove(item);
	}
	#endregion
}
