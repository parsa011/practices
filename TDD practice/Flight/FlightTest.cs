using Flight.Domain.Test;
using FluentAssertions;

namespace FlightTest
{
    public class UnitTest
    {
        [Fact]
        public void Test1()
        {
            var flight = new Flight.Domain.Test.Flight(seatCapacity: 3);
            flight.Book("parsa@gmail.com", 1);
            flight.RemainingOfSeats.Should().Be(2);
        }
    }
}