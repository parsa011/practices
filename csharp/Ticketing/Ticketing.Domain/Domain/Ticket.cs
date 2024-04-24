using System.ComponentModel.DataAnnotations;

namespace Ticketing.Domain.Domain
{
    public class Ticket
    {
        [Key]
        public int Id { get; set; }
        public string Name { get; set; }

        public List<TicketBooking> TicketBooking { get; set; }
    }
}
