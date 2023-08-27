namespace Flight.Domain.Test
{
    public class Flight
    {
        public Flight(int seatCapacity)
        {
            RemainingOfSeats = seatCapacity;
        }

        public int RemainingOfSeats
        {
            get;
            internal set;
        }

        public void Book(string email, int numberOfSeats)
        {
            _numberOfSeats -= numberOfSeats;
        }
    }
}