namespace Test.Core.Test;

public class MorningDateTimeProvider : IDateTimeProvider
{
    public DateTime GetNow()
    {
        return new DateTime(2024, 8, 11, 6, 0, 0);
    }
}

public class EveningDateTimeProvider : IDateTimeProvider
{
    public DateTime GetNow()
    {
        return new DateTime(2024, 8, 11, 13, 0, 0);
    }
}

public class UnitTest1
{

    [Fact]
    public void Greeting_ShouldReturn_GoodMorning()
    {
        var greeting = new Greeting(new MorningDateTimeProvider());

        var message = greeting.GetGreetingMessage();

        Assert.Equal("Good Morning", message);
    }

    [Fact]
    public void Greeting_ShouldReturn_GoodEvening()
    {
        var greeting = new Greeting(new EveningDateTimeProvider());

        var message = greeting.GetGreetingMessage();

        Assert.Equal("Good Evening", message);
    }
}
