
var keys = new string[,] {
    { "1", "2", "3"},
    { "4", "5", "6"},
    { "7", "8", "9"},
    { "-1", "0", "-1"},
};

var pins = GetPINs("5");
foreach (var item in pins)
    Console.WriteLine(item);

List<string> GetPINs(string observed)
{
    var numbers = GetPossibleNumbers(observed);
    var res = new List<string>();
    return numbers;
}

List<string> GetPossibleNumbers(string s)
{
    var res = new List<string>();
    foreach (var item in s.Split())
    {
        var neighbours = GetNeighbours(item);
        foreach (var elem in neighbours)
            if (!res.Contains(elem))
                res.Add(elem);
    }
    return res;
}

List<string> GetNeighbours(string s)
{
    var res = new List<string>();
    (int x, int y) = Get2DObjectInfo(s, keys);
    if (x - 1 >= 0)
    {
        res.Add(keys[x - 1, y]);
    }
    if (x + 1 < 4)
    {
        if (keys[x + 1, y] != "-1")
        {
            res.Add(keys[x + 1, y]);
        }
    }
    if (x != 3)
    {
        if (y + 1 < 3)
            res.Add(keys[x, y + 1]);
        if (y - 1 >= 0)
            res.Add(keys[x, y - 1]);
    }
    res.Add(s);
    return res;
}

(int x, int y) Get2DObjectInfo(string s, string[,] obj)
{
    int x = 0,y = 0;
    for (; x < 4; x++)
    {
        y = 0;
        for (; y < 3; y++)
        {
            if (obj[x,y] == s)
                return (x,y);
        }
    }
    return (-1,-1);
}