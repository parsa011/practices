using Microsoft.Data.Sqlite;
using Northwind.EntityModels;


var context = new NorthwindDb();

Console.WriteLine(context.Database.CurrentTransaction);