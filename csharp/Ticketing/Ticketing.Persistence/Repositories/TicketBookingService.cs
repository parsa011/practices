using Ticketing.Domain.Domain;
using Ticketing.Persistence.Interfaces;

namespace Ticketing.Persistence.Repositories
{
    public class TicketBookingService : ITicketBookingService
    {
        private readonly TicketingDbContext _context;

        public TicketBookingService(TicketingDbContext context)
        {
            _context = context;
        }

        public IEnumerable<Ticket> GetAvailableTicket(DateTime date)
        {
            return _context.Tickets.Where(a => !a.TicketBooking.Any(b => b.Date == date)).ToList();
        }

        public void Save(TicketBooking ticketBooking)
        {
            _context.Add(ticketBooking);
            _context.SaveChanges();
        }
    }
}
