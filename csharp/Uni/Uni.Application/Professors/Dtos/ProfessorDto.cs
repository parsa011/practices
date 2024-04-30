using Uni.Domain.Entities;

namespace Uni.Application.Professors.Dtos;

public class ProfessorDto
{
    public string Name { get; set; } = default!;
    public string LastName { get; set; } = default!;
    public string? City { get ; set; }
    public string? Street { get ; set; }

    public static ProfessorDto? FromEntity(Professor? professor)
    {
        return professor == null ? null : new ProfessorDto {
            Name = professor.Name,
            LastName = professor.LastName,
            City = professor.Address.City,
            Street = professor.Address.Street
        };
    }
}