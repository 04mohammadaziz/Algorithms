import random

# Constants
N = 10

# Globals
from array import array
x = array('i', [0] * N)

# Merge subroutine 
def merge(A, p, q, r):
    left = list(A[p: q+1])
    right = list(A[q+1: r+1])

    i = 0
    j = 0
    k = p

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            A[k] = left[i]
            i += 1
        else:
            A[k] = right[j]
            j += 1
        k += 1

    # Replacing with loops for array compatibility
    for m in range(i, len(left)):
        A[k] = left[m]
        k += 1
    
    for m in range(j, len(right)):
        A[k] = right[m]
        k += 1

# Merge_sort subroutine 
def merge_sort(A, p=0, r=None):
    if r is None:
        r = len(A) - 1
    if p >= r:
        return
    q = (p + r) // 2
    merge_sort(A, p, q)
    merge_sort(A, q + 1, r)
    merge(A, p, q, r)

# Subroutine to print the list
def print_list(arr):
    for item in arr:
        print(item, end=' ')
    print()

# Main routine
def main():
    print("Lab 1 - merge sort")
    
    # Populate array with random integers
    for i in range(N):
        x[i] = random.randint(0, 99)
    
    print("List before sorting:")
    print_list(x)
    
    # Sort the array
    merge_sort(x)
    
    print("List after sorting:")
    print_list(x)

# Script start-up
if __name__ == "__main__":
    main()
