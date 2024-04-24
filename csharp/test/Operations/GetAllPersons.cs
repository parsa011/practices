using Microsoft.EntityFrameworkCore;

namespace Test.Operations
{
    public class GetAllPersons
    {
        public static async Task<IEnumerable<Person>> GetAllAsync()
        {
            var context = new MyDbContext();

            return await context.Persons.ToListAsync();
        }
    }
}