namespace tax_visitor;

public interface IProduct
{
    public double Tax { get; }
    public double Price { get; set; }
}