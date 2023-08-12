def binary_search(arr, target) :
    if not arr :
        return -1

    low = 0
    high = len(arr) - 1
    mid = (low + high) // 2

    if arr[mid] == target : 
        return target
    elif  arr[mid] > target : 
        return binary_search(arr[:mid], target)
    else : 
        return binary_search(arr[mid + 1:], target)

print(binary_search([1, 2, 3, 4], 4))
