namespace DomeGym.Domain;

public class Session
{
	private readonly Guid _id;
	private readonly Guid _trainerId;
	private readonly Guid _roomId;
	private readonly List<Guid> _participantsIds = [];
	private readonly int _maxParticipants;

	public Session(
		int maxParticipants,
		Guid trainerId,
		Guid? id = null
	)
    {
		_maxParticipants = maxParticipants;
		_trainerId = trainerId;
		_id = id ?? Guid.NewGuid();
	}

	public void ReserveSpot(Participant participant)
	{
		if (_participantsIds.Count >= _maxParticipants)
		{
			throw new Exception("Cannot have more reservations than participants");
		}
		_participantsIds.Add(participant.Id);
	}
}
