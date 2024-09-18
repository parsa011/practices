using CQRS.Shared.Abstractions.Commands;

namespace CQRS.Application.Commands;

public record RemoveTraveleritem(Guid TravelerCheckListId, string Name) : ICommand;
