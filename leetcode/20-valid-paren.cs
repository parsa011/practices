public class Solution {
	public bool IsValid(string s) {
		if (s.Length % 2 != 0)
			return false;
		var stack = new Stack<char>();
		foreach (var item in s) {
			if (item == '(' ||  item == '{' || item == '[') {
				stack.Push(item);
			}
			else if (item == ')') {
				if (stack.Count == 0 || stack.Pop() != '(')
					return false;
			}
			else if (item == ']') {
				if (stack.Count == 0 || stack.Pop() != '[')
					return false;
			} else if (item == '}') {
				if (stack.Count == 0 || stack.Pop() != '{')
					return false;
			}
		}
		return stack.Count == 0;
	}
}
