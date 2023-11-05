# Deterministic Quick Sort
def deterministic_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    

    pivot = arr[0]
    left = []
    right = []
    equal = []
    for num in arr:
        if num < pivot:
            left.append(num)
        elif num == pivot:
            equal.append(num)
        else:
            right.append(num)
    return deterministic_quick_sort(left) + equal + deterministic_quick_sort(right)

a=[3,4,6,1,9,5]
print(deterministic_quick_sort(a))