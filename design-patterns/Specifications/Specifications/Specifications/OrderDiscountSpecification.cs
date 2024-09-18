using Specifications.Entities;

namespace Specifications.Specifications;

internal class OrderDiscountSpecification : ISpecification<Order>
{
	public bool IsSatisfied(Order entity)
	{
		if (entity is null || entity.TotalPrice < 100)
		{
			return true;
		}
		return false;
	}
}
