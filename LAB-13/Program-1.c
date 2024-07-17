#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
    double ratio; 
};
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }        }    }    double totalValue = 0.0; 
    int currentWeight = 0; 
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }
    return totalValue;}
int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    double totalValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
