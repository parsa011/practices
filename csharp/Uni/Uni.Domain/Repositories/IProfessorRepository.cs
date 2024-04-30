using Uni.Domain.Entities;

namespace Uni.Domain.Repositories;

public interface IProfessorRepository
{
    Task<IEnumerable<Professor>> GetAllAsync();
}