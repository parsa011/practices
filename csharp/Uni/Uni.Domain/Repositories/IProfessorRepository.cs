using Uni.Domain.Entities;

namespace Uni.Domain.Repositories;

public interface IProfessorRepository
{
    Task<IEnumerable<Professor>> GetAllAsync();
    Task<Professor?> GetByIdAsync(int id);
}