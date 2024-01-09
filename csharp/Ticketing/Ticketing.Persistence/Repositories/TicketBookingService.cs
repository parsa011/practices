using Ticketing.Domain.Domain;
using Ticketing.Persistence.Interfaces;

namespace Ticketing.Persistence.Repositories
{
    public class TicketBookingService : ITicketBookingService
    {
        public IEnumerable<Ticket> GetAvailableTicket(DateTime date)
        {
            throw new NotImplementedException();
        }

        public void Save(TicketBooking ticketBooking)
        {
            throw new NotImplementedException();
        }
    }
}