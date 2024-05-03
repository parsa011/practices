namespace Uni.Application.Professors.Dtos;

public class ProfessorCreateDto
{
    public string Name { get; set; } = default!;
    public string LastName { get; set; } = default!;
    public string Email { get; set; } = default!;
    public string? City { get ; set; }
    public string? Street { get ; set; }
}