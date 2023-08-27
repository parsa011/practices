namespace Data.Entities
{
	public class Address
	{
		public string Id { get; set; }
		public string Street { get; set;}
		public string UserId { get; set; }

		public virtual User User { get; set; }
	}
}
