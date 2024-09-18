using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class TravelerItemNameException : TravelerChekListException
{
    public TravelerItemNameException() : base("Traveler Item Can not be null")
    {
    }
}
