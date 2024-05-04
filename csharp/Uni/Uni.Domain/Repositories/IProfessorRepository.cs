using Uni.Domain.Entities;

namespace Uni.Domain.Repositories;

public interface IProfessorRepository
{
    Task<IEnumerable<Professor>> GetAllAsync();
    Task<Professor?> GetByIdAsync(int id);
    Task<int> CreateAsync(Professor professor);
    Task EditAsync(Professor professor);
    Task Delete(Professor professor);
}