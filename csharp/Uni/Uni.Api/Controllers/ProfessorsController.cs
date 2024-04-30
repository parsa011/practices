using Microsoft.AspNetCore.Mvc;
using Uni.Application.Professors;

namespace Uni.Api;

[ApiController]
[Route("api/Professors")]
public class RestaurantController(IProfessorsService professorsService) : ControllerBase
{
    [HttpGet]
    public async Task<IActionResult> GetAll()
    {
        return Ok(await professorsService.GetAllAsync());
    }
}