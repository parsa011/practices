using CQRS.Domain.Entities;
using CQRS.Domain.ValueObjects;

namespace CQRS.Domain.Repositories;

public interface ITravelerCheckListRepository
{
	Task<TravelerCheckList> GetAsync(TravelerCheckListId id);
	Task AddAsync(TravelerCheckList travelerCheckList);
	Task UpdateAsync(TravelerCheckList travelerCheckList);
	Task DeleteAsync(TravelerCheckList travelerCheckList);
}
