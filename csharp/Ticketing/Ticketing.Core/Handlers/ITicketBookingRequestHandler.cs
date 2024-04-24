using Ticketing.Core.Model;

namespace Ticketing.Core.Handlers
{
    public interface ITicketBookingRequestHandler
    {
        ServiceBookingResult BookService(TicketBookingRequest request);
    }
}
