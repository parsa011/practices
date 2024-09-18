using CQRS.Domain.Consts;
using CQRS.Shared.Abstractions.Commands;

namespace CQRS.Application.Commands;

public record CreateTravelerCheckListWithItems(Guid Id, string Name, ushort Days, Gender Gender, DestinationWriteModel Destination) : ICommand;

public record DestinationWriteModel(string City, string Country);
