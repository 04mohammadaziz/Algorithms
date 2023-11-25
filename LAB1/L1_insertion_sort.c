#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define N 10

// Function Declarations
void print_list(int arr[], int n);
void insertion_sort(int arr[], int n);

int main() {
    srand(time(NULL));  // Seed the random number generator
    printf("Lab 1 - insertion sort\n");

    int x[N];  // Array to be sorted

    // Populate array with random integers between 0 and 127
    for (int i = 0; i < N; ++i) {
        int random_num;
        do {
            random_num = rand();
        } while (random_num < (1 << 24));
        x[i] = random_num >> 24;
    }

    printf("List before sorting:\n");
    print_list(x, N);

    // Sort the array
    insertion_sort(x, N);

    printf("List after sorting:\n");
    print_list(x, N);

    return 0;
}

void print_list(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
