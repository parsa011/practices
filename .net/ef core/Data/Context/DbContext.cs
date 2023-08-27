using Data.Entities;

namespace Data.Context
{
    public class MyDbContext : DbContext
    {
        public DbContext()
        {

        }

        public DbSet<User> Users { get; set; }
        public DbSet<Address> Addresses { get; set; }
    }
}
