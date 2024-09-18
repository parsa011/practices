using CQRS.Shared.Abstractions.Commands;

namespace CQRS.Application.Commands;

public record AddTravelerItem(Guid TravelerCheckListId, string Name, uint Quantity) : ICommand;
