using CQRS.Shared.Abstractions.Exceptions;

namespace CQRS.Domain.Exceptions;

public class InvalidTemperatureException(double temperature) : Exception($"Temperature '{temperature}' is Invalid") 
{
}
