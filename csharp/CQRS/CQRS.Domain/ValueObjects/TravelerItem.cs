using CQRS.Domain.Exceptions;

namespace CQRS.Domain.ValueObjects;

public record TravelerItem
{
    public string Name { get; }
    public uint Quantity { get; }

    public bool IsTaken { get; init; }

    public TravelerItem(string name, uint quantity, bool isTaken = false)
    {
        if (string.IsNullOrWhiteSpace(name))
        {
            throw new TravelerItemNameException();
        }
        Name = name.Trim();
        Quantity = quantity;
        IsTaken = isTaken;
    }
}
