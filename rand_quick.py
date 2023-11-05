import random

# Deterministic Quick Sort
def deterministic_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = random.choice(arr)
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
a=[]
n=int(input('Enter no'))
for i in range (n):
    a.append(random.randint(1,20))
print(a)

# a=[3,2,6,4,8,1]
print(deterministic_quick_sort(a))