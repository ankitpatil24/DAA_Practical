#include <stdio.h>
#include <stdbool.h>
void printSubset(int set[], int n, bool subset[]) {
    printf("Subset with the target sum: { ");
    for (int i = 0; i < n; i++) {
        if (subset[i]) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}
bool isSubsetSum(int set[], int n, int sum, bool subset[], int currentIndex) {
    if (sum == 0) {
        printSubset(set, n, subset);
        return true;
    }

    if (currentIndex >= n || sum < 0) {
        return false;
    }
    subset[currentIndex] = true;
    if (isSubsetSum(set, n, sum - set[currentIndex], subset, currentIndex + 1)) {
        return true;
    }
    subset[currentIndex] = false;
    return isSubsetSum(set, n, sum, subset, currentIndex + 1);
}

int main() {
    int set[] = {1, 3, 4, 5, 7};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 10;
    bool subset[n];

    if (!isSubsetSum(set, n, sum, subset, 0)) {
        printf("No subset with the target sum found.\n");
    }

    return 0;
}
