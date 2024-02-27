using tax_visitor;
using tax_visitor.Entities;

IVisitor visitor = new TaxVisitor();

var book = new Book(price: 100);

var laptop = new Laptop(price: 1000);

book.Accept(visitor);
laptop.Accept(visitor);