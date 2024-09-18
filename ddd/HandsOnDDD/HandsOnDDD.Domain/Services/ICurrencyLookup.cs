using HandsOnDDD.Framework;

namespace HandsOnDDD.Domain.Services;

public interface ICurrencyLookup
{
	CurrencyDetails FindCurrency(string currencyCode);
}

public class CurrencyDetails : Value<CurrencyDetails>
{
	public string CurrencyCode { get; set; } = default!;
	public bool InUse { get; set; }
	public int DecimalPlaces { get; set; }
	public static CurrencyDetails None = new()
	{
		InUse = false
	};
}
