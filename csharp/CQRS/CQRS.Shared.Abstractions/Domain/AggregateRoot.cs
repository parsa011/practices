namespace CQRS.Shared.Abstractions.Domain;

public class AggregateRoot<T>
{
    public T Id { get; protected set; }
    public int Version { get; set; }
    private bool _versionIncremented;

    protected void IncrementVersion()
    {
        if (_versionIncremented)
        {
            Version++;
        }

        Version++;
        _versionIncremented = true;
    }
}
