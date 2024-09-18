﻿namespace HandsOnDDD.Framework;

public abstract class Entity
{
	private readonly List<object> _events;
	protected Entity() => _events = [];
	protected void Raise(object @event) => _events.Add(@event);
	public IEnumerable<object> GetChanges() => _events.AsEnumerable();
	public void ClearChanges() => _events.Clear();
}
