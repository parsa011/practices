using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Policies.Universal;

internal sealed class BasicPolicy : ITravelerItemsPolicy
{
	private const uint MaximumQuantityOfClothes = 7;

	public bool IsApplicable(PolicyData _)
		=> true;

	public IEnumerable<TravelerItem> GenerateItems(PolicyData data)
	{
		return [
			new("Pants", Math.Min(data.Days, MaximumQuantityOfClothes)),
			new("Socks", Math.Min(data.Days, MaximumQuantityOfClothes)),
			new("T-Shirts", Math.Min(data.Days, MaximumQuantityOfClothes)),
			new("Trousers", data.Days < 7 ? 1u : 2u),
			new("Towel", 1),
			new("Big Pack", 1),
			new("Passpowrt", 1)
		];
	}
}
