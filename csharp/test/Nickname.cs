using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Test
{
    public class Nickname
    {
        [Key]
        public string Id { get; set; }

        [Required]
        public string Title { get; set; }

        public Person Person { get; set; }
    }
}