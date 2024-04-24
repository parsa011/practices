using Microsoft.AspNetCore.Mvc;
using Ticketing.Core.Handlers;
using Ticketing.Core.Model;

namespace Ticketing.Api.Controllers
{
    public class BookingController : ControllerBase
    {
        private ITicketBookingRequestHandler _bookingRequestHandler;

        public BookingController(ITicketBookingRequestHandler bookingRequestHandler)
        {
            this._bookingRequestHandler = bookingRequestHandler;
        }

        public async Task<IActionResult> Book(TicketBookingRequest request)
        {
            if (ModelState.IsValid)
            {
                var result = _bookingRequestHandler.BookService(request);
                if (result.Flag == Core.Enums.BookingResultFlag.Success)
                {
                    return Ok(result);
                }
                ModelState.AddModelError(nameof(TicketBookingRequest.Date), "No Ticket Available For Given Date");
            }
            return BadRequest(ModelState);
        }
    }
}