/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {

	public int ListLen(ListNode l)
	{
		int len = 0;
		while (l != null) {
			len++;
			l = l.next;
		}
		return len;
	}

	public ListNode GetByIndex(ListNode l, int n)
	{
		int len = 0;
		while (l != null) {
			if (++len == n)
				return l;
			l = l.next;
		}
		return null;
	}

	public ListNode RemoveNthFromEnd(ListNode head, int n)
	{
		int len = ListLen(head);
		n = len - n + 1;

		var next = GetByIndex(head, n + 1);
		var prev = GetByIndex(head, n - 1);
		if (prev == null)
			return next;
		if (next == null) {
			prev.next = null;
		} else
			prev.next = next;
		return head;
	}
}
