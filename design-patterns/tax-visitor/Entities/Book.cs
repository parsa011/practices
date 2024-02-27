namespace tax_visitor.Entities;

public class Book(double price) : IProduct
{
    public double Tax
    {
        get
        {
            return 0.1;
        }
    }
    
    public double Price { get; set; } = price;

    public double Weight { get; set; }

    public void Accept(IVisitor visitor)
    {
        visitor.Visit(this);
    }
}