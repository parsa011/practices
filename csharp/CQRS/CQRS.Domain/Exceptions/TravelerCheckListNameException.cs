using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class TravelerCheckListNameException : TravelerChekListException 
{
    public TravelerCheckListNameException() : base("Traverler CheckList Name Can not be null")
    {
    }
}
