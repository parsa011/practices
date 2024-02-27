using System.Numerics;
using tax_visitor.Entities;

namespace tax_visitor;

public class TaxVisitor : IVisitor
{
    public void Visit(Book book)
    {
        var tax = book.Price * book.Tax;
        Console.WriteLine($"Book tax is ${tax}");
    }

    public void Visit(Laptop laptop)
    {
        var tax = laptop.Price * laptop.Tax;
        Console.WriteLine($"Laptop tax is : ${tax}");
    }
}