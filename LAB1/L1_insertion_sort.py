import random 

# constants
N = 10

# globals
from array import array
x = array('i', [0] * N)

# subroutines
def print_list(arr):
    for item in arr:
        print(item, end=' ')
    print()

def insertion_sort(A, n):
	for i in range(1, n):
		key = A[i]
		j = i - 1
		while j >= 0 and A[j] > key:
			A[j + 1] = A[j]
			j -= 1
		A[j + 1] = key
		
# main routine
def main():
    print("Lab 1 - insertion sort")
    
    # Populate array with random integers
    for i in range(N):
        x[i] = random.randint(0, 99)
    
    print("List before sorting:")
    print_list(x)
    
    # Sort the array
    insertion_sort(x, N)
    
    print("List after sorting:")
    print_list(x)


# script start-up

if __name__ == "__main__":
    main()
    
