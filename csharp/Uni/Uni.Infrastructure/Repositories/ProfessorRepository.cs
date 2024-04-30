using Microsoft.EntityFrameworkCore;
using Uni.Domain.Entities;
using Uni.Domain.Repositories;
using Uni.Infrastructure.Context;

namespace Uni.Infrastructure.Repositories;

internal class ProfessorRepository(UniContext context) : IProfessorRepository
{
    public async Task<IEnumerable<Professor>> GetAllAsync()
    {
        return await context.Professors.ToListAsync();
    }
}