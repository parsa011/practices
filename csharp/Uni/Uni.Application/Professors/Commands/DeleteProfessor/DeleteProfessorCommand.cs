using MediatR;

namespace Uni.Application.Professors.Commands.DeleteProfessor;

public class DeleteProfessorCommand(int id) : IRequest<bool>
{
    public int Id { get; set; } = id;
}