IList<int> FindAnagrams(string s, string p)
{
    var res = new List<int>();
    for (int i = 0; i < s.Length; i++)
    {
        if (p.Contains(s[i]))
        {
            var temp = p.ToCharArray().ToList();
            temp.RemoveAt(p.IndexOf(s[i]));
            for (int j = i + 1; j < s.Length; j++)
            {
                if (temp.Contains(s[j]))
                {
                    temp.RemoveAt(temp.IndexOf(s[j]));
                }
                else
                    break;
            }

            if (temp.Count == 0)
                res.Add(i);
        }
    }
    return res;
}

bool CheckInclusion(string s1, string s2)
{
    var as_arr = s1.ToCharArray().ToList();
    return as_arr.Count == 0;
}

var res = FindAnagrams("abab", "ab");
foreach (var item in res)
{
    Console.WriteLine(item);
}