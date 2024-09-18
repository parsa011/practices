using Test.Core;

public class DateTimeProvider : IDateTimeProvider
{
    public DateTime GetNow()
    {
        return DateTime.Now;
    }
}
