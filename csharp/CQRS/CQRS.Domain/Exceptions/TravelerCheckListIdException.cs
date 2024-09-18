using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class TravelerCheckListIdException : TravelerChekListException
{
    public TravelerCheckListIdException() : base("Id Cannot be null")
    {
        
    }
}
