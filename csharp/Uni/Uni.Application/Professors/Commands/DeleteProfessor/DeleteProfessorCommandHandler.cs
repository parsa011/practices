using MediatR;
using Microsoft.Extensions.Logging;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors.Commands.DeleteProfessor;

public class DeleteProfessorCommandHandler(
    ILogger<DeleteProfessorCommand> logger,
    IProfessorRepository professorRepository
) : IRequestHandler<DeleteProfessorCommand, bool>
{
    public async Task<bool> Handle(DeleteProfessorCommand command, CancellationToken cancellationToken)
    {
        logger.LogInformation("Delete professor");
        var professor = await professorRepository.GetByIdAsync(command.Id);
        if (professor is null)
        {
            return false;
        }
        await professorRepository.Delete(professor);
        return true;
    }
}