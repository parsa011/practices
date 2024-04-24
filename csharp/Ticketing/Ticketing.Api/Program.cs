using Microsoft.Data.Sqlite;
using Microsoft.EntityFrameworkCore;
using Ticketing.Core.Handlers;
using Ticketing.Persistence;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();

var connectionString = "DataSource=: memory:";
var conn = new SqliteConnection(connectionString);
conn.Open();

builder.Services.AddDbContext<TicketingDbContext>(options => {
    options.UseSqlite(conn);
});

builder.Services.AddScoped<ITicketBookingRequestHandler, TicketBookingRequestHandler>();

// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
