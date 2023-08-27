void Merge(int[] num1, int m, int[] num2, int n)
{
	int x = m - 1, y = n - 1, k = n + m - 1;
	while (y >= 0) {
		if (x >= 0 && num1[x] > num2[y])
			num1[k--] = num1[x--]; 
		else
			num1[k--] = num2[y--];
	}
}

int[] num1 = new int[]{
	1,2,3,0,0,0
};
int[] num2 = new int[]{
	2,5,6
};
Merge(num1, 3, num2, 3);
foreach (var item in num1)
	Console.WriteLine(item);
