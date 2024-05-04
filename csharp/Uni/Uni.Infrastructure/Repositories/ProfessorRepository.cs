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

    public async Task<Professor?> GetByIdAsync(int id)
    {
        return await context.Professors.FirstOrDefaultAsync(a => a.Id == id);
    }

    public async Task<int> CreateAsync(Professor professor)
    {
        await context.Professors.AddAsync(professor);
        await context.SaveChangesAsync();
        return professor.Id;
    }

    public async Task EditAsync(Professor professor)
    {
        context.Professors.Update(professor);
        await context.SaveChangesAsync();
    }

    public async Task Delete(Professor professor)
    {
        context.Professors.Remove(professor);
        await context.SaveChangesAsync();
    }
}