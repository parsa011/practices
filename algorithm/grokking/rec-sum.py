def sum(arr):
    if len(arr) == 0:
        return 0
    n = arr[0]
    del arr[0]
    return n + sum(arr)

print(sum([1, 2, 3, 4, 5]))
