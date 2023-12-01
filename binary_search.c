#include <stdio.h>
int binarySearch(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] > target) {
        return binarySearch(arr, target, left, mid - 1);
    }
    return binarySearch(arr, target, mid + 1, right);
}

int main() {
    int arr[] = {12, 23, 34, 45, 67, 89};
    int target = 45;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, target, 0, size - 1);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}