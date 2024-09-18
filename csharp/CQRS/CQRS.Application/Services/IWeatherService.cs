using CQRS.Application.DTO.External;
using CQRS.Domain.ValueObjects;

namespace CQRS.Application.Services;

public interface IWeatherService
{
	Task<WeatherDto> GetWeatherAsync(Destination destination);
}
