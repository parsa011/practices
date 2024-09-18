using DomGym.Domain.Test.TestUtils.Participants;
using DomGym.Domain.Test.TestUtils.Sessions;
using FluentAssertions;

namespace DomGym.Domain.Test;

public class SessionTests
{

	[Fact]
	public void ReserverSpot_WhenNoMoreRoom_ShouldFailReservation()
	{
		// Arrange
		var session = SessionsFactory.CreateSessions(maxParticipants: 1);
		var participant1 = ParticipantFactory.CreateParticipant(userId: Guid.NewGuid(), id: Guid.NewGuid());
		var participant2 = ParticipantFactory.CreateParticipant(userId: Guid.NewGuid(), id: Guid.NewGuid());

		// Act
		session.ReserveSpot(participant1);
		var action = () => session.ReserveSpot(participant2);

		// Assert
		action.Should().ThrowExactly<Exception>();
	}
}
