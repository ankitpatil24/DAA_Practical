#include <stdio.h>
int linearSearch(int arr[], int target, int index, int size) {
    if (index == size) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }

    return linearSearch(arr, target, index + 1, size);
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 23};
    int target = 89;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, target, 0, size);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

