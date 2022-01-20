var table = new Dictionary<string,int>()
{
    {"I",1},
    {"IV",4},
    {"V",5},
    {"X",10},
    {"L",50},
    {"C",100},
    {"D",500},
    {"M",1000}
};

string ToRoman(int n)
{
    string res = "";
    return res;
}
Console.WriteLine(ToRoman(943));

int FromRoman(string romanNumeral)
{
    int res = 0;
    for (int i = 0; i <= romanNumeral.Length - 1;i++) 
    {
        if (i < romanNumeral.Length - 1 && table[romanNumeral[i + 1].ToString()] > table[romanNumeral[i].ToString()]) {
            res += table[romanNumeral[i + 1].ToString()] - table[romanNumeral[i].ToString()];
            i++;
        } else {
            res += table[romanNumeral[i].ToString()];
        }
    }
    return res;
}