using CQRS.Domain.Exceptions;

namespace CQRS.Domain.ValueObjects;

public record TravelDays
{
	public ushort Value { get; }

	public TravelDays(ushort value)
	{
		if (value is 0 or > 100)
		{
			throw new InvalidTravelDaysException(value);
		}
	}

	public static implicit operator TravelDays(ushort value)
		=> new(value);

	public static implicit operator ushort(TravelDays tempreature)
		=> tempreature.Value;
}
