namespace Uni.Domain.Entities;

public class Professor
{
    public int Id { get; set ;}
    public string Name { get; set; } = default!;
    public string LastName { get; set; } = default!;
    public string Email { get; set; } = default!;
    public Address Address { get; set; } = new();
    public IEnumerable<Field> Fields { get; set; } = [];
}