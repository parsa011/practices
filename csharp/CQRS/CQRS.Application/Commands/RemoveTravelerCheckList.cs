using CQRS.Shared.Abstractions.Commands;

namespace CQRS.Application.Commands;

public record RemoveTravelerCheckList(Guid Id) : ICommand;
