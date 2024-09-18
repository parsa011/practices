namespace Test.Core;

public interface IDateTimeProvider
{
    DateTime GetNow();
}

public class Greeting
{
    private readonly IDateTimeProvider _dateTimeProvider;
    public Greeting(IDateTimeProvider dateTimeProvider)
    {
        _dateTimeProvider = dateTimeProvider;
    }

    public string GetGreetingMessage()
    {
        var dateTime = _dateTimeProvider.GetNow();
        return dateTime.Hour switch {
            >= 5 and < 12 => "Good Morning",
            >= 12 and < 18 => "Good Evening",
            _ => "Good Night"
        };
    }
}