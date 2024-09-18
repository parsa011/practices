using Specifications.Entities;
using Specifications.Specifications;

var invalidOrder = new Order()
{
	Name = "parsa",
	TotalPrice = 10,
	CreationDate = DateTime.Now,
};

var validOrder = new Order()
{
	Name = "ali",
	TotalPrice = 240,
	CreationDate = DateTime.Now,
};

var orderDiscountSpecification = new OrderDiscountSpecification();

if (orderDiscountSpecification.IsSatisfied(validOrder))
{
	Console.WriteLine($"{validOrder.Name} satisfied specification");
}

if (orderDiscountSpecification.IsSatisfied(invalidOrder))
{
	Console.WriteLine($"{invalidOrder.Name} satisfied specification");
}