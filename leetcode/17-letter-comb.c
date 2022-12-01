public class Solution {
	public string[] map = new string[] {
		"",
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
	};
	public IList<string> LetterCombinations(string digits)
	{
		var res = new List<string>();
		if (string.IsNullOrEmpty(digits))
			return res;
		res.Add("");
		foreach (var item in digits) {
			var temp = new List<string>();
			foreach (var ch in map[int.Parse(item.ToString())]) {
				foreach (var new_s in res)
					temp.Add(new_s + ch.ToString());
			}
			res = temp;
		}
		return res;
	}
}
