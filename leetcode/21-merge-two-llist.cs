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

	public void SortList(ListNode l)
	{
		for (ListNode n = l; n.next != null;) {
			if (n.next != null && n.next.val < n.val) {
				int temp = n.next.val;
				n.next.val = n.val;
				n.val = temp;
				n = l;
			} else
				n = n.next;
		}
	}

	public ListNode ListLast(ListNode head)
	{
		while (head.next != null) {
			head = head.next;
		}
		return head;
	}

	public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
		if (list1 == null && list2 == null)
			return null;
		var res = list1;
		if (list1 == null)
			res = list2;
		else
			ListLast(res).next = list2;
		SortList(res);
		return res;
	}
}
