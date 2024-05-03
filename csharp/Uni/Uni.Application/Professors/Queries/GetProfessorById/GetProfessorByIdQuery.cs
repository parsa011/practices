using MediatR;
using Uni.Application.Professors.Dtos;

namespace Uni.Application.Professors.Queries.GetProfessorById;

public class GetProfessorByIdQuery(int id) : IRequest<ProfessorDto?>
{
    public int Id { get; set; } = id;
}