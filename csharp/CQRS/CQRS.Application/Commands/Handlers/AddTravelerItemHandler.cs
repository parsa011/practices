using CQRS.Application.Exceptions;
using CQRS.Domain.Repositories;
using CQRS.Domain.ValueObjects;
using CQRS.Shared.Abstractions.Commands;

namespace CQRS.Application.Commands.Handlers;

public class AddTravelerItemHandler(
	ITravelerCheckListRepository travelerCheckListRepository
) : ICommandHandler<AddTravelerItem>
{
	public async Task HandleAsync(AddTravelerItem command)
	{
		var travelerCheckingList = await travelerCheckListRepository.GetAsync(command.TravelerCheckListId);

		if (travelerCheckingList is null)
		{
			throw new TravelerCheckListNotFoundException(command.TravelerCheckListId);
		}

		var travelerItem = new TravelerItem(command.Name, command.Quantity);
		travelerCheckingList.AddItem(travelerItem);

		await travelerCheckListRepository.UpdateAsync(travelerCheckingList);
	}
}
