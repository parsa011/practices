using Microsoft.AspNetCore.Mvc;
using Uni.Api.Attribtues;
using Uni.Application.Professors;
using Uni.Application.Professors.Dtos;

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

    [HttpGet("{id}")]
    public async Task<IActionResult> GetById([FromRoute] int id)
    {
        return Ok(await professorsService.GetByIdAsync(id));
    }

    [HttpPost]
    [ValidationFilter]
    public async Task<IActionResult> Create([FromBody] ProfessorCreateDto professor)
    {
        var id = await professorsService.CreateAsync(professor);
        return CreatedAtAction(nameof(GetById), new { id }, null);
    }
}