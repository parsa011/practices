using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class TravelerItemAlreadyExistsException(
	string listName,
	string itemName
	) : TravelerChekListException($"Traveler Check List : '{listName} already defined item '{itemName}'")
{
	public string ListName { get; } = listName;
	public string ItemName { get; } = itemName;
}
