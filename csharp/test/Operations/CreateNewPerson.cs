namespace Test.Operations
{
    public static class CreateNewPerson
    {
        public static async Task<(int affected, string personId)> CreateAsync(Person person)
        {
            var context = new MyDbContext();

            await context.Persons.AddAsync(person);

            return (await context.SaveChangesAsync(), person.Id);
        }
    }
}