using Ticketing.Core.Handlers;
using Shouldly;
using Moq;
using Ticketing.Domain;
using Ticketing.Core.Model;
using Ticketing.Core.Enums;
using Ticketing.Domain.Domain;
using Ticketing.Persistence.Interfaces;

namespace Ticketing.Core.Test
{
    public class TicketBookingRequestHandlerTest
    {
        private readonly TicketBookingRequestHandler _handler;
        private readonly TicketBookingRequest _request;
        private readonly Mock<ITicketBookingService> _ticketBookingServiceMock;
        private List<Ticket> _availableTickets;

        public TicketBookingRequestHandlerTest()
        {
            _request = new TicketBookingRequest
            {
                Name = "Parsa",
                Family = "Mahmoudy",
                Email = "parsa32569@gmail.com",
				Date = DateTime.Now
            };
            _availableTickets = new List<Ticket> { new() { Id = 1 } };
            _ticketBookingServiceMock = new Mock<ITicketBookingService>();
            _ticketBookingServiceMock.Setup(q => q.GetAvailableTicket(_request.Date))
				.Returns(_availableTickets);
            _handler = new TicketBookingRequestHandler(_ticketBookingServiceMock.Object);
        }

        [Fact]
        public void Should_Return_Ticket_Booking_Response_With_Request_Values()
        {
            // Act
            ServiceBookingResult result = _handler.BookService(_request);

            // Assert
            Assert.NotNull(result);
            Assert.Equal(result.Name, _request.Name);
            Assert.Equal(result.Family, _request.Family);
            Assert.Equal(result.Email, _request.Email);
        }

        [Fact]
        public void Sould_Throw_Exception_For_Null_Request()
        {
            var exception = Should.Throw<ArgumentNullException>(() => _handler.BookService(null));
            exception.ParamName.ShouldBe("request");            
        }

        [Fact]
        public void Should_Save_Ticket_Booking_Request()
        {
            TicketBooking savedBooking = null;
            _ticketBookingServiceMock
                .Setup(x => x.Save(It.IsAny<TicketBooking>()))
                .Callback<TicketBooking>(booking => {
                    savedBooking = booking;
                });
            _handler.BookService(_request);
            _ticketBookingServiceMock.Verify(x => x.Save(It.IsAny<TicketBooking>()), Times.Once);

            Assert.NotNull(savedBooking);
            Assert.Equal(savedBooking.Name, _request.Name);
            Assert.Equal(savedBooking.Family, _request.Family);
            Assert.Equal(savedBooking.Email, _request.Email);
            Assert.Equal(savedBooking.TicketId, _availableTickets.First().Id);
        }

        [Fact]
        public void Should_Not_Save_Ticket_Booking_Request_If_None_Avaiable()
        {
			_availableTickets.Clear();
			_handler.BookService(_request);
			_ticketBookingServiceMock.Verify(x => x.Save(It.IsAny<TicketBooking>()), Times.Never);
		}

        [Theory]
        [InlineData(BookingResultFlag.Failure, false)]
        [InlineData(BookingResultFlag.Success, true)]
        public void Should_Return_SuccesOrFailure_Flag_In_Result(BookingResultFlag bookingSuccessFlag, bool isAvailable)
        {
            if (!isAvailable)
            {
                _availableTickets.Clear();
            }

            var request = _handler.BookService(_request);
            Assert.Equal(request.Flag, bookingSuccessFlag);
        }
 
        [Theory]
        [InlineData(1, true)]
        [InlineData(null, false)]
        public void Should_Retur_TicketBookingId_In_Result(int? ticketBookingId, bool isAvailable)
        {
            if (!isAvailable)
            {
                _availableTickets.Clear();
            }
            else
            {
                _ticketBookingServiceMock
                    .Setup(x => x.Save(It.IsAny<TicketBooking>()))
                    .Callback<TicketBooking>(booking => {
                        booking.TicketId = ticketBookingId.Value;
                    });
            }
            var request = _handler.BookService(_request);
            Assert.Equal(request.TicketBookingId, ticketBookingId);
        }
    }
}
 
