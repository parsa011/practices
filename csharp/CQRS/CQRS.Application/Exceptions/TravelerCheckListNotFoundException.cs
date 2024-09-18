using CQRS.Domain.ValueObjects;
using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Application.Exceptions;

public class TravelerCheckListNotFoundException(TravelerCheckListId id) : TravelerCheckListException($"TravelerCheck List With Id $'{id}' not found")
{
}
