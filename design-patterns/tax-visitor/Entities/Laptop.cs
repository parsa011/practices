namespace tax_visitor.Entities;

public class Laptop(double price) : IProduct
{
    public double Tax
    {
        get
        {
            return 0.2;
        }
    }
    
    public double Price { get; set; } = price;
    public string Cpu { get; set; } = default!;

    public void Accept(IVisitor visitor)
    {
        visitor.Visit(this);
    }
}