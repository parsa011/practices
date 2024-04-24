using Microsoft.AspNetCore.Mvc;
using Moq;
using Shouldly;
using Ticketing.Api.Controllers;
using Ticketing.Core.Enums;
using Ticketing.Core.Handlers;
using Ticketing.Core.Model;

namespace Ticketing.Api.Test
{
    public class BookingControllerTest
    {
        private Mock<ITicketBookingRequestHandler> _ticketBookingRequestHandler;
        private BookingController _controller;
        private TicketBookingRequest _requset;
        private ServiceBookingResult _result;

        public BookingControllerTest()
        {
            _ticketBookingRequestHandler = new Mock<ITicketBookingRequestHandler>();
            _controller = new BookingController(_ticketBookingRequestHandler.Object);
            _requset = new TicketBookingRequest();
            _result = new ServiceBookingResult();

            _ticketBookingRequestHandler.Setup(x => x.BookService(_requset)).Returns(_result);
        }

        [Theory]
        [InlineData(1, true, typeof(OkObjectResult), BookingResultFlag.Success)]
        [InlineData(0, false, typeof(BadRequestObjectResult), BookingResultFlag.Failure)]
        public async Task Should_Call_Booking_Method_When_Valid(int expectedMethodCalls, bool isModelValid,
            Type expectedActionResultType, BookingResultFlag flag)
        {
            if (!isModelValid)
            {
                _controller.ModelState.AddModelError("Key", "Message");
            }
            _result.Flag = flag;

            // Act
            var result = await _controller.Book(_requset);

            // Assert
            result.ShouldBeOfType(expectedActionResultType);
            _ticketBookingRequestHandler.Verify(x => x.BookService(_requset), Times.Exactly(expectedMethodCalls));
        }
    }
}