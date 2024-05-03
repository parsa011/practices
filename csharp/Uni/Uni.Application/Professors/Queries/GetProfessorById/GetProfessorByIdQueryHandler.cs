using AutoMapper;
using MediatR;
using Microsoft.Extensions.Logging;
using Uni.Application.Professors.Dtos;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors.Queries.GetProfessorById;

public class GetProfessorByIdQueryHandler (
    ILogger<GetProfessorByIdQueryHandler> logger,
    IProfessorRepository professorRepository,
    IMapper mapper
) : IRequestHandler<GetProfessorByIdQuery, ProfessorDto?>
{
    public async Task<ProfessorDto?> Handle(GetProfessorByIdQuery query, CancellationToken cancellationToken)
    {
        logger.LogInformation("Get Professor By Id");
        return mapper.Map<ProfessorDto?>(await professorRepository.GetByIdAsync(query.Id));
    }
}