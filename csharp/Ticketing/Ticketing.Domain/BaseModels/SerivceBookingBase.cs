namespace Ticketing.Domain.BaseModels
{
    public abstract class ServiceBookingBase
    {
        public string Family { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
		public DateTime Date { get; set; }
    }
}
