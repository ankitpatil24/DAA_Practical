#include <stdio.h>
#include <stdlib.h>
struct Item {
    int weight;
    int value;
};
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    double ratio2 = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    if (ratio1 < ratio2) return -1;
    if (ratio1 > ratio2) return 1;
    return 0;
}
void fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;  
    double currentWeight = 0.0;  

    for (int i = 0; i < n; i++) {
        result[i] = 0.0;
    }

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            result[i] = 1.0;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double remainingCapacity = capacity - currentWeight;
            result[i] = remainingCapacity / items[i].weight;
            totalValue += result[i] * items[i].value;
            break; 
        }
    }

    printf("Maximum total value: %.2lf\n", totalValue);

    printf("Fraction of each item taken:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2lf\n", i + 1, result[i]);
    }
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    fractionalKnapsack(items, n, capacity);
    return 0;
}
