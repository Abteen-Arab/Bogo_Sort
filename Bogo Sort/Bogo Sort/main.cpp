//This is meant to be a joke code, not for real use.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Checks to see if the array is sorted
bool is_sorted(int *arr, int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        //Checks to see if the array is sorted
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

//Random sorting of the array
void shuffle(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        //randomly switches i with int in position j
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//Potential Infinite  loop until sorted is reached.
void bogosort(int *arr, int n) {
    srand(time(NULL));
    //Loop to keep sorted
    while (!is_sorted(arr, n)) {
        shuffle(arr, n);
    }
}

int main() {
    double start_time = time(NULL);
    double end_time;
    int arr[] = {5, 3, 8, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bogosort(arr, n);
    
    printf("\nSorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    end_time = time(NULL);
    printf("\nThe total time for the sort was %.2lf seconds.\n",start_time-end_time);
    
    return 0;
}
