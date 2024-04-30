using Microsoft.AspNetCore.Mvc;

namespace Uni.Api;

[ApiController]
[Route("api/Professors")]
public class RestaurantController : ControllerBase
{
    [HttpGet]
    public IActionResult GetAll()
    {
        
    }
}