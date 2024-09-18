using DomeGym.Domain;
using DomGym.Domain.Test.Constant;

namespace DomGym.Domain.Test.TestUtils.Participants;

public static class ParticipantFactory
{
	public static Participant CreateParticipant(Guid? userId = null, Guid? id = null)
	{
		return new Participant(userId ?? Constants.User.Id, id ?? Guid.NewGuid());
	}
}
