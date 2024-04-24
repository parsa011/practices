using System.ComponentModel.DataAnnotations;

namespace Test
{
    public class Person
    {
        [Key]
        public string Id { get; set; }

        [MaxLength(128)]
        [Required]
        public string Name { get; set; }

        [MaxLength(64)]
        public string Email { get; set; }

        public IEnumerable<Nickname> Nicknames { get; set; }

        public void Print()
        {
            Console.Write($"{Id} -- {Name} -- {Email}\n");
        }
    }
}