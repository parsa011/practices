using Uni.Application.Professors.Dtos;

namespace Uni.Application.Professors;

public interface IProfessorsService
{
    Task<IEnumerable<ProfessorDto>> GetAllAsync();
    Task<ProfessorDto?> GetByIdAsync(int id);
    Task<int> CreateAsync(ProfessorCreateDto professor);
}