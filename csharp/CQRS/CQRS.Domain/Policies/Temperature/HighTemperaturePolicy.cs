using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Policies.Temperature;

internal sealed class HighTemperaturePolicy : ITravelerItemsPolicy
{
	public bool IsApplicable(PolicyData policyData)
		=> policyData.Tempreature.Value > 25D;

	public IEnumerable<TravelerItem> GenerateItems(PolicyData policyData)
	{
		return [
			new("Hat", 1),
			new("Sunglassed", 1),
			new("Create With UV filter", 1)
		];
	}
}
