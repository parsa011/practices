using Microsoft.EntityFrameworkCore;
using Uni.Domain.Entities;

namespace Uni.Infrastructure.Context;

internal class UniContext(DbContextOptions options) : DbContext(options)
{
    internal DbSet<Professor> Professors { get; set; }
    internal DbSet<Field> Fields { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<Professor>()
            .OwnsOne(a => a.Address);
    }
}