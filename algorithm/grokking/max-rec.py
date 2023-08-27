def find_max(arr) :
    if len(arr) == 0:
        return 0
    n = arr[0]
    del arr[0]
    return max(n, find_max(arr))

print(find_max([1, 2, 9, 4, 0, 10, 2, 3, 4]))
