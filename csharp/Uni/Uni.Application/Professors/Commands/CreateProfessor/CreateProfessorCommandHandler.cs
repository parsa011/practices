using AutoMapper;
using MediatR;
using Microsoft.Extensions.Logging;
using Uni.Domain.Entities;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors.Commands.CreateProfessor;

public class CreateProfessorCommandHandler(
    ILogger<CreateProfessorCommandHandler> logger,
    IProfessorRepository professorRepository,
    IMapper mapper
) : IRequestHandler<CreateProfessorCommand, int>
{
    public async Task<int> Handle(CreateProfessorCommand request, CancellationToken cancellationToken)
    {
        logger.LogInformation("Creating new Professor");
        return await professorRepository.CreateAsync(mapper.Map<Professor>(request));
    }
}