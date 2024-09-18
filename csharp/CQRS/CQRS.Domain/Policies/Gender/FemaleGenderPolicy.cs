using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Policies.Gender;

internal sealed class FemaleGenderPolicy : ITravelerItemsPolicy
{
	public bool IsApplicable(PolicyData policyData)
		=> policyData.Gender is Consts.Gender.Female;

	public IEnumerable<TravelerItem> GenerateItems(PolicyData policyData)
	{
		return [
			new("LipStick", 1),
			new("Powder", 1),
			new("Eyeliner", 1)
		];
	}
}
