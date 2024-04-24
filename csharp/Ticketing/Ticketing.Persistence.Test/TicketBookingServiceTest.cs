using Microsoft.EntityFrameworkCore;
using Ticketing.Domain.Domain;
using Ticketing.Persistence.Repositories;
using Xunit;

namespace Ticketing.Persistence.Test
{
    public class TicketBookingServiceTest
    {

        [Fact]
        public void Should_Save_TicketBooking()
        {
            // Arrange
            var dbOptions = new DbContextOptionsBuilder<TicketingDbContext>()
                .UseInMemoryDatabase("ShouldSaveTest", a => a.EnableNullChecks(false))
                .Options;
            var context = new TicketingDbContext(dbOptions);
            var ticketBooking = new TicketBooking() {
                TicketID = 1,
                Date = DateTime.Now.Date
            };

            // Act
            var ticketBookingService = new TicketBookingService(context);
            ticketBookingService.Save(ticketBooking);

            // Assert
            var bookings = context.TicketBookings.ToList();
            var booking = Assert.Single(bookings);
            Assert.Equal(ticketBooking.Date, booking.Date);
            Assert.Equal(ticketBooking.TicketID, booking.TicketID);
        }

        [Fact]
        public void Should_Return_Available_Services()
        {
            // Arrange
            var date = DateTime.Now;

            var dbOptions = new DbContextOptionsBuilder<TicketingDbContext>()
                .UseInMemoryDatabase("AvailableTicketTest", a => a.EnableNullChecks(false))
                .Options;

            using var context = new TicketingDbContext(dbOptions);
            context.Tickets.Add(new Ticket {Id = 1, Name = "Ticket1"});
            context.Tickets.Add(new Ticket {Id = 2, Name = "Ticket2"});
            context.Tickets.Add(new Ticket {Id = 3, Name = "Ticket3"});

            context.TicketBookings.Add(new TicketBooking {
                TicketID = 1,
                Date = DateTime.Now.Date,
            });
            context.TicketBookings.Add(new TicketBooking {
                TicketID = 2,
                Date = DateTime.Now.AddDays(-19).Date,
            });

            context.SaveChanges();

            var ticketBookingService = new TicketBookingService(context);

            // Act
            var availableServices = ticketBookingService.GetAvailableTicket(DateTime.Now.Date);

            // Assert
            Assert.Equal(2, availableServices.Count());
            Assert.Contains(availableServices, q => q.Id == 2);
            Assert.Contains(availableServices, q => q.Id == 3);
            Assert.DoesNotContain(availableServices, q => q.Id == 1);

        }
    }
}
