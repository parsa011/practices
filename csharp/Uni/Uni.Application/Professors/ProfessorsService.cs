using AutoMapper;
using Microsoft.Extensions.Logging;
using Uni.Application.Professors.Dtos;
using Uni.Domain.Entities;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors;

public class ProfessorsService(
    IProfessorRepository professorRepository,
    ILogger<ProfessorsService> logger,
    IMapper mapper
) : IProfessorsService
{
    public async Task<IEnumerable<ProfessorDto>> GetAllAsync()
    {
        logger.LogInformation("Getting all Professors");
        return (await professorRepository.GetAllAsync()).Select(a => mapper.Map<ProfessorDto>(a))!;
    }

    public async Task<ProfessorDto?> GetByIdAsync(int id)
    {
        logger.LogInformation("Get Professor By Id");
        return mapper.Map<ProfessorDto>(await professorRepository.GetByIdAsync(id));
    }

    public async Task<int> CreateAsync(ProfessorCreateDto professor)
    {
        logger.LogInformation("Creating new Professor");
        return await professorRepository.CreateAsync(mapper.Map<Professor>(professor));
    }
}