using System.ComponentModel.DataAnnotations;
using Ticketing.Domain.BaseModels;

namespace Ticketing.Domain.Domain
{
    public class TicketBooking : ServiceBookingBase
    {
        [Key]
        public int Id { get; set; }
        public int TicketID { get; set; }

        public Ticket Ticket { get; set; }
    }
}
