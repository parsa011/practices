using Microsoft.EntityFrameworkCore;
using Ticketing.Domain.Domain;

namespace Ticketing.Persistence
{
    public class TicketingDbContext : DbContext
    {
        public TicketingDbContext(DbContextOptions<TicketingDbContext> options) : base(options)
        {
            
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<Ticket>().HasData(
                new Ticket() {Id = 1, Name = "Metallica"},
                new Ticket() {Id = 2, Name = "Gorgoroth"},
                new Ticket() {Id = 3, Name = "Slipknot"}
            );
        }

        public DbSet<Ticket> Tickets { get; set; }
        public DbSet<TicketBooking> TicketBookings { get; set; }
    }
}