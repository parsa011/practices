using MediatR;
using Uni.Application.Professors.Dtos;

namespace Uni.Application.Professors.Queries.GetAllProfessorsQuery;

public class GetAllProfessorsQuery : IRequest<IEnumerable<ProfessorDto>>
{

}