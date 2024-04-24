using Test.Operations;

namespace Test
{
	public class MyLinkedList
	{
		public int Value { get; set; }
		public MyLinkedList Next { get; set; }
		public MyLinkedList(int val, MyLinkedList next)
		{
			Value = val;
			Next = next;
		}
	}

	public class Program
	{
		public static void DeleteFromList(MyLinkedList root, IEnumerable<int> valuesToDelete, List<int> deletedValues)
		{
			if (root == null)
			{
				return;
			}
			if (root.Next != null && valuesToDelete.Contains(root.Next.Value) && !deletedValues.Contains(root.Next.Value))
			{
				deletedValues.Add(root.Next.Value);
				root.Next = root.Next.Next;
			}
			DeleteFromList(root.Next, valuesToDelete, deletedValues);
		}

		public static void Main()
		{
			var first = new MyLinkedList(1,
			new MyLinkedList(2, new MyLinkedList(3, new MyLinkedList(4, new MyLinkedList(5, new MyLinkedList(2, null))))));

			DeleteFromList(
				first,
				new List<int>(){
					2,
					4
				},
				new List<int>()
			);

			var f = first;
			while (f != null)
			{
				Console.WriteLine(f.Value);
				f = f.Next;
			}
		}
	}
}
