using CQRS.Shared.Abstractions.Commands;

namespace CQRS.Application.Commands;

public record TakeItem(Guid TravelerCheckListId, string Name) : ICommand;
