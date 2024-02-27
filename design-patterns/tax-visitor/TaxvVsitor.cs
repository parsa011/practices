using tax_visitor.Entities;

namespace tax_visitor;

public class TaxVisitor : IVisitor
{
    public void Visit(Book book)
    {
        var tax = book.Price * 0.1;
        Console.WriteLine($"Book tax is ${tax}");
    }

    public void Visit(Laptop laptop)
    {
        var tax = laptop.Price * 0.2;
        Console.WriteLine($"Laptop tax is : ${tax}");
    }
}