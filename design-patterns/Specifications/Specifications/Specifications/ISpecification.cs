namespace Specifications.Specifications;

internal interface ISpecification<T> where T : class
{
	bool IsSatisfied(T entity);
}
