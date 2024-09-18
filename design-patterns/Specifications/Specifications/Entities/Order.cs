namespace Specifications.Entities;

internal class Order
{
	public string Name { get; set; } = default!;
	public decimal TotalPrice { get; set; }
	public DateTime CreationDate { get; set; }
}
