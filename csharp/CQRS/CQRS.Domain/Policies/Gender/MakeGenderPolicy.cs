using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Policies.Gender;

internal sealed class MakeGenderPolicy : ITravelerItemsPolicy
{
	public bool IsApplicable(PolicyData policyData)
		=> policyData.Gender is Consts.Gender.Male;

	public IEnumerable<TravelerItem> GenerateItems(PolicyData policyData)
	{
		return [
			new("Laptop", 1),
			new("Drink", 1),
			new("Book", 1)
		];
	}
}
