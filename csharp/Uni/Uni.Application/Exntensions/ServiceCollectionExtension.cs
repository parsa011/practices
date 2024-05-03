using FluentValidation;
using FluentValidation.AspNetCore;
using Microsoft.Extensions.DependencyInjection;
using Uni.Application.Professors;

namespace Uni.Application.Extension;

public static class ServiceCollectionExtenstion
{
    public static IServiceCollection AddApplication(this IServiceCollection services)
    {
        var applicationAssembly = typeof(ServiceCollectionExtenstion).Assembly;
        services.AddMediatR(options => {
            options.RegisterServicesFromAssembly(applicationAssembly);
        });
        services.AddAutoMapper(applicationAssembly);
        services
            .AddValidatorsFromAssembly(applicationAssembly)
            .AddFluentValidationAutoValidation();
        return services;
    }
}