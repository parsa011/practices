// See https://aka.ms/new-console-template for more information
using System.Numerics;

Console.WriteLine("Hello, World!");

BigInteger a = 1;


string res = "1";
for (int i = 0; i < 5120; i++)
{
    a *= 2;
    res = BigMultiply(res, 2);
}

Console.WriteLine(a);

Console.WriteLine(res);

string BigMultiply(string str,int n)
{
    var results = new List<string>();
    string n_str = n.ToString();
    string temp;
    int carry;
    int zero_index = 0;
    for (int i = n_str.Length - 1;i >= 0;i--) 
    {
        temp = "";
        carry = 0;
        for (int x = 0;x < zero_index;x++)
            temp += "0";
        for (int j = str.Length - 1; j >= 0; j--)
        {
            int res = (n_str[i] - '0') * (str[j] - '0') + carry;
            carry = 0;
            if (res > 9)
            {
                carry = res / 10;
                res %= 10;
            }
            temp += res.ToString();
        }
        if (carry != 0)
            temp += carry.ToString();
        temp = strrev(temp);
        results.Add(temp);
        zero_index++;
    }
    return BigSum(results);
}
string BigSum(List<string> list)
{
    string res = "";
    foreach (var item in list)
    {
        res = string_sum(res,item);
    }
    return res;
}

string string_sum(string a, string b)
{
    string res = "";
    string bigger = "";
    string less = "";
    if (a.Length > b.Length) {
        bigger = a;
        less = b;
    } else {
        bigger = b;
        less =a;
    }
    int carry = 0;
    int temp = 0;
    for (int j = bigger.Length - 1,i = less.Length - 1;j >= 0;j--,i--) {
        if (i < 0) {
            temp = (bigger[j] - '0') + carry;
        } else {
            temp = (bigger[j] - '0') + (less[i] - '0') + carry;
        }
        carry = 0;
        if (temp >= 10) {
            carry = 1;
            temp -= 10;
        }
        res += temp.ToString();
    }
    if (carry > 0){
        res += "1";
    }
    res = strrev(res);
    if (res[0] == '0')
        res = res.Substring(1);
    return res;
}

string strrev(string str)
{
    char[] charArray = str.ToCharArray();
    Array.Reverse( charArray );
    return new string( charArray );
}