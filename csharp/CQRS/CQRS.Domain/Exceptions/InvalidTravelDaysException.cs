using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class InvalidTravelDaysException(ushort days) : TravelerChekListException($"Value '{days} is invalid for Travel Days")
{
	public ushort Days { get; } = days;
}
