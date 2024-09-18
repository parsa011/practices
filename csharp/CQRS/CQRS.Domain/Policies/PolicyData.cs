using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Policies;

public record PolicyData(
	TravelDays Days,
	Consts.Gender Gender,
	Tempreature Tempreature,
	Destination Destination
)
{
}
