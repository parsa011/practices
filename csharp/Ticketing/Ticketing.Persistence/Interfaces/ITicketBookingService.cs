using Ticketing.Domain.Domain;

namespace Ticketing.Persistence.Interfaces
{
    public interface ITicketBookingService
    {
        void Save(TicketBooking ticketBooking);

        IEnumerable<Ticket> GetAvailableTicket(DateTime date);
    }
}
