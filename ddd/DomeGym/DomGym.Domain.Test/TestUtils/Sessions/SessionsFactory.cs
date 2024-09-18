using DomeGym.Domain;
using DomGym.Domain.Test.Constant;

namespace DomGym.Domain.Test.TestUtils.Sessions;

public static class SessionsFactory
{
	public static Session CreateSessions(int maxParticipants)
	{
		return new Session(maxParticipants, Constants.Trainer.Id, Constants.Session.Id);
	}
}
