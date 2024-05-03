using FluentValidation;
using FluentValidation.AspNetCore;
using Microsoft.Extensions.DependencyInjection;
using Uni.Application.Professors;

namespace Uni.Application.Extension;

public static class ServiceCollectionExtenstion
{
    public static IServiceCollection AddApplication(this IServiceCollection services)
    {
        services.AddScoped<IProfessorsService, ProfessorsService>();
        var applicationAssembly = typeof(ServiceCollectionExtenstion).Assembly;
        services.AddAutoMapper(applicationAssembly);
        services
            .AddValidatorsFromAssembly(applicationAssembly)
            .AddFluentValidationAutoValidation();
        return services;
    }
}