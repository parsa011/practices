using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Uni.Domain.Repositories;
using Uni.Infrastructure.Context;
using Uni.Infrastructure.Repositories;
using Uni.Infrastructure.Seeders;

namespace uni.Infrastructure.Extenstions;

public static class ServiceCollectionExtenstion
{
    public static void AddInfrastructure(this IServiceCollection services, IConfiguration configuration)
    {
        var connectionString = configuration.GetConnectionString("DefaultConnection");
        services.AddDbContext<UniContext>(options => {
            options
                .UseSqlServer(connectionString, config => {
                    config.EnableRetryOnFailure();
                })
                .EnableDetailedErrors();
            options.EnableSensitiveDataLogging();
        });

        services.AddScoped<IUniSeeder, UniSeeder>();
        services.AddScoped<IProfessorRepository, ProfessorRepository>();
    }
}