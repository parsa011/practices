using Ticketing.Core.Enums;
using Ticketing.Domain.BaseModels;

namespace Ticketing.Core.Model
{
    public class ServiceBookingResult : ServiceBookingBase
    {
        public BookingResultFlag Flag { get; set; }
        public int? TicketBookingId { get; set; }
    }
}
