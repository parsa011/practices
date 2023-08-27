"""

 |   0     |    1    |    2    |     3
    low                             high

worst time is : lon n
"""
import math
def binary_search(list, item):
    # we have to track that where we want to search everytime
    # the beggining and the end of array
    low = 0
    high = len(list) - 1
    while low <= high:
        mid = math.floor((low + high) / 2)
        guess = list[mid]
        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None

my_list = [1, 3, 5, 7, 9]
print(binary_search(my_list, 3))
print(binary_search(my_list, -1))
