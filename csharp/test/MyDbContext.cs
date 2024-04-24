
using Microsoft.EntityFrameworkCore;

namespace Test
{
    public class MyDbContext : DbContext
    {
        public MyDbContext()
        {
            
        }

        public MyDbContext(DbContextOptions options) : base(options)
        {
            
        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            base.OnConfiguring(optionsBuilder);
            optionsBuilder.UseSqlServer(
                "Server = . ; Database = TestDb; Trusted_Connection = False; TrustServerCertificate = True; User Id = sa; Password = Parsa@011",
                options => {
                    options.EnableRetryOnFailure();
                }
            );
        }

        public DbSet<Person> Persons { get; set; }
    }
}