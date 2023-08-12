def array_len(arr):
    if len(arr) == 0:
        return 0
    del arr[0]
    return 1 + array_len(arr)

print(array_len([1, 2, 3, 4]))
