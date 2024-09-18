int c = int.Parse(Console.ReadLine()!);
var names = new Dictionary<string, int>();

for (int i = 0; i < c; i++)
{
	string name = Console.ReadLine()!.Split(' ')[0];
	if (names.Any(a => a.Key == name))
	{
		names[name]++;
	}
	else
	{
		names.Add(name, 1);
	}
}

Console.WriteLine(names.OrderByDescending(a => a.Value).First().Value);
