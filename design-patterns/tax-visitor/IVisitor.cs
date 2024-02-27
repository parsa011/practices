using tax_visitor.Entities;

namespace tax_visitor;

public interface IVisitor
{
    void Visit(Book book);
    void Visit(Laptop laptop);
}