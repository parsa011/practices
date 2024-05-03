using MediatR;

namespace Uni.Application.Professors.Commands.CreateProfessor;

public class CreateProfessorCommand : IRequest<int>
{
    public string Name { get; set; } = default!;
    public string LastName { get; set; } = default!;
    public string Email { get; set; } = default!;
    public string? City { get ; set; }
    public string? Street { get ; set; }
}