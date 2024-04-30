using System.Net.Mime;
using Microsoft.EntityFrameworkCore;
using Uni.Domain.Entities;
using Uni.Infrastructure.Context;

namespace Uni.Infrastructure.Seeders;

internal class UniSeeder(UniContext context) : IUniSeeder
{
    public async Task Seed()
    {
        if (await context.Database.CanConnectAsync())
        {
            if (!await context.Professors.AnyAsync())
            {
                var professors = GetProfessors();
                context.Professors.AddRange(professors);
                await context.SaveChangesAsync();
            }
        }
    }

    private IEnumerable<Professor> GetProfessors()
    {
        return [
            new() {
                Name = "Parsa",
                LastName = "Mahmoudy",
                Email = "parsa32569@gmail.com",
                Fields = [
                    new Field () {
                        Title = "CS"
                    }
                ]
            },
            new() {
                Name = "Ali",
                LastName = "Hassani",
                Email = "ali@gmail.com",
                Fields = [
                    new Field () {
                        Title = "SF"
                    }
                ]
            }
        ];
    }
}