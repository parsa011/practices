#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int buf_len = 5;
    int **buf = calloc(buf_len, sizeof(int *));
	int *buf_col = calloc(buf_len, sizeof(int));
    int ptr = 0;
#define CHECK_BUF() {													\
		if (ptr == buf_len - 1) {										\
			buf = realloc(buf, (buf_len += buf_len) * sizeof(int *));	\
			buf_col = realloc(buf_col, buf_len * sizeof(int));			\
		}																\
}
			
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
					CHECK_BUF();
					buf[ptr] = calloc(3, sizeof(int));
                    buf[ptr] = ((int[]) {nums[i], nums[j], nums[k]});
					buf_col[ptr++] = 3;
                }
            }
        }
    }
    *returnSize = ptr;
	*returnColumnSizes = buf_col;
#undef CHECK_BUF
    return buf;
}

int main()
{
	int arr[] = {-1,0,1,2,-1,-4};
	int ret_size;
	int *cols;
	int **res = threeSum(arr, 6, &ret_size, &cols);
	for (int i = 0; i < ret_size; i++) {
		for (int j = 0; j < cols[i]; j++) {
			printf( "%d ", res[i][j]);
		}
	}
	printf("hello\n");
	return 0;
}
