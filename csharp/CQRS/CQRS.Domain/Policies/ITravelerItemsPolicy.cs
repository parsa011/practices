using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Policies;

public interface ITravelerItemsPolicy
{
	bool IsApplicable(PolicyData policyData);
	IEnumerable<TravelerItem> GenerateItems(PolicyData policyData);
}
