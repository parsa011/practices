using Uni.Domain.Entities;

namespace Uni.Application.Professors;

public interface IProfessorsService
{
    Task<IEnumerable<Professor>> GetAllAsync();
}