namespace HandsOnDDD.Domain;

public static class Events
{
	public class ClassifiedAdCreated
	{
		public Guid Id { get; set; }
		public Guid OwnerId { get; set; }
	}

	public class ClassifiedAdTitleChanged
	{
		public Guid Id { get; set; }
		public string Title { get; set; } = default!;
	}
	public class ClassifiedAdTextUpdated
	{
		public Guid Id { get; set; }
		public string AdText { get; set; } = default!;
	}
	public class ClassifiedAdPriceUpdated
	{
		public Guid Id { get; set; }
		public decimal Price { get; set; }
		public string CurrencyCode { get; set; } = default!;
	}
	public class ClassifiedAdSentForReview
	{
		public Guid Id { get; set; }
	}
	public class ClassidiedAdSentForReview
	{
		public Guid Id { get; set; }
	}
}
