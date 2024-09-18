using CQRS.Domain.Exceptions;

namespace CQRS.Domain.ValueObjects;

public class TravelerCheckListName
{
    public string Name { get; }

    public TravelerCheckListName(string value)
    {
		if (string.IsNullOrWhiteSpace(value))
        {
            throw new TravelerCheckListNameException();
        }

        Name = value.Trim();
    }

	public static implicit operator string(TravelerCheckListName name)
			=> name.Name;

	public static implicit operator TravelerCheckListName(string name)
		=> new(name);
}
