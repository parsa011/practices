using AutoMapper;
using MediatR;
using Microsoft.Extensions.Logging;
using Uni.Domain.Repositories;

namespace Uni.Application.Professors.Commands.EditProfessor;

public class EditProfessorCommandHandler(
    ILogger<EditProfessorCommand> logger,
    IProfessorRepository professorRepository,
    IMapper mapper
) : IRequestHandler<EditProfessorCommand, bool>
{
    public async Task<bool> Handle(EditProfessorCommand command, CancellationToken cancellationToken)
    {
        logger.LogInformation($"Editing Professor with Id : '{command.Id}'");
        var professor = await professorRepository.GetByIdAsync(command.Id);
        if (professor is null)
        {
            return false;
        }
        mapper.Map(command, professor);
        await professorRepository.EditAsync(professor);
        return true;
    }
}