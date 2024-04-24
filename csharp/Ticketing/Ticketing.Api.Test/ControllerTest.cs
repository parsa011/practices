using Moq;
using Xunit;
using Microsoft.Extensions.Logging;
using Ticketing.Api.Controllers;
using Shouldly;

namespace Ticketing.Api.Test
{
    public class ControllerTest
    {
        [Fact]
        public void Should_Return_Forecast_Results()
        {
            // Arrange
            var logger = new Mock<ILogger<WeatherForecastController>>();
            var controller = new WeatherForecastController(logger.Object);

            // Act
            var result = controller.Get();

            // Assert
            result.ShouldNotBeNull();
            result.Count().ShouldBeGreaterThan(1);
        }
    }
}
