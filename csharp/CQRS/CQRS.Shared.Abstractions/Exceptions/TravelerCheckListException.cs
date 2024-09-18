namespace CQRS.Shared.Abstractions.Exceptions;

public class TravelerCheckListException : Exception
{
    protected TravelerChekListException(string message) : base(message)
    {
    }
}
