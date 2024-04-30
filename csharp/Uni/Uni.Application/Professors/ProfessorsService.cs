using Microsoft.Extensions.Logging;
using Uni.Domain.Entities;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors;

public class ProfessorsService(
    IProfessorRepository professorRepository,
    ILogger<ProfessorsService> logger
) : IProfessorsService
{
    public async Task<IEnumerable<Professor>> GetAllAsync()
    {
        logger.LogInformation("Getting all Professors");
        return await professorRepository.GetAllAsync();
    }
}