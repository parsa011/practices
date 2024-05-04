using MediatR;

namespace Uni.Application.Professors.Commands.EditProfessor;

public class EditProfessorCommand : IRequest<bool>
{
    public int Id { get; set; }
    public string Name { get; set; } = default!;
    public string LastName { get; set; } = default!;
    public string Email { get; set; } = default!;
    public string? City { get ; set; }
    public string? Street { get ; set; }
}