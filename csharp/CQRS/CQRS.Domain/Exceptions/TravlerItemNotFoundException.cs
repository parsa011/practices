using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class TravlerItemNotFoundException : TravelerChekListException
{
    public TravlerItemNotFoundException(string itemName) : base($"'{itemName}' Not Found in Items")
    {
        
    }
}
