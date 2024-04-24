using Ticketing.Domain.Domain;
using Ticketing.Core.Enums;
using Ticketing.Core.Model;
using Ticketing.Domain.BaseModels;
using Ticketing.Persistence.Interfaces;

namespace Ticketing.Core.Handlers
{
    public class TicketBookingRequestHandler : ITicketBookingRequestHandler
    {
        private readonly ITicketBookingService _ticketBookingService;
        public TicketBookingRequestHandler(ITicketBookingService bookingService)
        {
            _ticketBookingService = bookingService;
        }

        public ServiceBookingResult BookService(TicketBookingRequest request)
        {
            if (request is null)
            {
                throw new ArgumentNullException(nameof(request));
            }

            var availableTickets = _ticketBookingService.GetAvailableTicket(request.Date);
            var result = CreateTicketBookingObject<ServiceBookingResult>(request);
            result.Flag = BookingResultFlag.Failure;
            if (availableTickets.Any())
            {
                var ticket = availableTickets.First();
                var ticketBooking = CreateTicketBookingObject<TicketBooking>(request);
                ticketBooking.TicketID = ticket.Id;
                _ticketBookingService.Save(ticketBooking);
                result.Flag = BookingResultFlag.Success;
                result.TicketBookingId = ticket.Id;
            }
            return result;
        }

        private static TTicketBooking CreateTicketBookingObject<TTicketBooking>(TicketBookingRequest request) 
                where TTicketBooking : ServiceBookingBase , new()
        {
            return new TTicketBooking
            {
                Name = request.Name,
                Family = request.Family,
                Email = request.Email
            };
        }
    }
}
