using Ticketing.Domain.BaseModels;

namespace Ticketing.Domain.Domain
{
    public class TicketBooking : ServiceBookingBase
    {
        public int Id { get; set; }
        public int TicketId { get; set; }

        public Ticket Ticket { get; set; }
    }
}