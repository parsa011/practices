using CQRS.Domain.Consts;
using CQRS.Domain.Entities;
using CQRS.Domain.Policies;
using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Factories;

public class TravelerCheckListFactory : ITravelCheckListFactory
{
	private readonly IEnumerable<ITravelerItemsPolicy> _policies;

	public TravelerCheckListFactory(IEnumerable<ITravelerItemsPolicy> policies)
		=> _policies = policies;

	public TravelerCheckList Create(TravelerCheckListId id, TravelerCheckListName name, Destination destination)
		=> new(id, name, destination);

	public TravelerCheckList CreateWithDefaultItems(
		TravelerCheckListId id,
		TravelerCheckListName name,
		TravelDays days,
		Gender gender,
		Tempreature tempreature,
		Destination destination
	)
	{
		var data = new PolicyData(days, gender, tempreature, destination);
		var applicablePolicies = _policies.Where(a => a.IsApplicable(data));

		var items = applicablePolicies.SelectMany(p => p.GenerateItems(data));
		var travelerCheckingList = Create(id, name, destination);

		travelerCheckingList.AddItems(items);

		return travelerCheckingList;
	}
}
