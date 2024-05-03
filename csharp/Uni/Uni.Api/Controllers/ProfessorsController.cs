using MediatR;
using Microsoft.AspNetCore.Mvc;
using Uni.Api.Attribtues;
using Uni.Application.Professors;
using Uni.Application.Professors.Commands.CreateProfessor;
using Uni.Application.Professors.Dtos;
using Uni.Application.Professors.Queries.GetAllProfessorsQuery;
using Uni.Application.Professors.Queries.GetProfessorById;

namespace Uni.Api;

[ApiController]
[Route("api/Professors")]
public class RestaurantController(IMediator mediator) : ControllerBase
{
    [HttpGet]
    public async Task<IActionResult> GetAll()
    {
        return Ok(await mediator.Send(new GetAllProfessorsQuery()));
    }

    [HttpGet("{id}")]
    public async Task<IActionResult> GetById([FromRoute] int id)
    {
        var query = new GetProfessorByIdQuery(id);
        return Ok(await mediator.Send(query));
    }

    [HttpPost]
    [ValidationFilter]
    public async Task<IActionResult> Create([FromBody] CreateProfessorCommand professor)
    {
        var id = await mediator.Send(professor);
        return CreatedAtAction(nameof(GetById), new { id }, null);
    }
}