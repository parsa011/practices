namespace Uni.Domain.Entities;

public class Field
{
    public int Id { get; set; }
    public string Title { get; set; } = default!;
    public int ProfessorId { get; set; } = default!;

    public Professor Professor { get; set; } = new();
}