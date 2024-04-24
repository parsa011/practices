using System.ComponentModel.DataAnnotations;

namespace Ticketing.Domain.BaseModels
{
    public abstract class ServiceBookingBase
    {
        public string Family { get; set; }

        [Required]
        [MaxLength(80)]
        public string Name { get; set; }

        [Required]
        [EmailAddress]
        public string Email { get; set; }

        [DataType(DataType.EmailAddress)]
		public DateTime Date { get; set; }

        public  IEnumerable<ValidationResult> Validate(ValidationContext context)
        {
            if (Date <= DateTime.Now.Date)
            {
                yield return new ValidationResult("Data Must Be in the future", new [] { nameof(Date) });
            }
        }
    }
}
