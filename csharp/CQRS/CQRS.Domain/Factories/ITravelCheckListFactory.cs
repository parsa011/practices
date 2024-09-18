using CQRS.Domain.Consts;
using CQRS.Domain.Entities;
using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Factories;

public interface ITravelCheckListFactory
{
	TravelerCheckList Create(
		TravelerCheckListId id,
		TravelerCheckListName name,
		Destination destination
	);

	TravelerCheckList CreateWithDefaultItems(
		TravelerCheckListId id,
		TravelerCheckListName name,
		TravelDays travelDays,
		Gender gender,
		Tempreature tempreature,
		Destination destination
	);
}
