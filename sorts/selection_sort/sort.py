def smallest_number(arr) :
    smallest_index = 0
    smallest = arr[0]
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index

def selection_sort(arr) :
    newArr = []
    for i in range(len(arr)):
        smallest = smallest_number(arr)
        newArr.append(arr.pop(smallest))
    return newArr

print(selection_sort([2, 4, 5, 1, 9, 8, 3, 1]))
