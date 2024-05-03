using AutoMapper;
using MediatR;
using Microsoft.Extensions.Logging;
using Uni.Application.Professors.Dtos;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors.Queries.GetAllProfessorsQuery;

public class GetAllProfessorsQueryHandler(
    ILogger<GetAllProfessorsQueryHandler> logger,
    IProfessorRepository professorRepository,
    IMapper mapper
) : IRequestHandler<GetAllProfessorsQuery, IEnumerable<ProfessorDto>>
{
    public async Task<IEnumerable<ProfessorDto>> Handle(GetAllProfessorsQuery query, CancellationToken cancellationToken)
    {
        logger.LogInformation("Getting all Professors");
        return (await professorRepository.GetAllAsync()).Select(a => mapper.Map<ProfessorDto>(a))!;
    }
}