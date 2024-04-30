using Microsoft.Extensions.DependencyInjection;
using Uni.Application.Professors;

namespace Uni.Application.Extension;

public static class ServiceCollectionExtenstion
{
    public static IServiceCollection AddApplication(this IServiceCollection services)
    {
        services.AddScoped<IProfessorsService, ProfessorsService>();
        return services;
    }
}