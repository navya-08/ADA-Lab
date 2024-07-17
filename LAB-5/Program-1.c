#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int value;
    bool direction; // true for left, false for right
} Element;
void printPermutation(Element* elements, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", elements[i].value);
    }
    printf("\n");
}
int getMobileElementIndex(Element* elements, int n) {
    int mobileIndex = -1;
    for (int i = 0; i < n; i++) {
        if ((elements[i].direction && i != 0 && elements[i].value > elements[i-1].value) ||
            (!elements[i].direction && i != n-1 && elements[i].value > elements[i+1].value)) {
            if (mobileIndex == -1 || elements[i].value > elements[mobileIndex].value) {
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}
void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}
void generatePermutations(Element* elements, int n) {
    printPermutation(elements, n);
    while (true) {
        int mobileIndex = getMobileElementIndex(elements, n);
        if (mobileIndex == -1) break;
        if (elements[mobileIndex].direction) {
            swap(&elements[mobileIndex], &elements[mobileIndex - 1]);
            mobileIndex--;
        } else {
            swap(&elements[mobileIndex], &elements[mobileIndex + 1]);
            mobileIndex++;
        }
        for (int i = 0; i < n; i++) {
            if (elements[i].value > elements[mobileIndex].value) {
                elements[i].direction = !elements[i].direction;
            }
        }
        printPermutation(elements, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    Element* elements = (Element*)malloc(n * sizeof(Element));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i].value);
        elements[i].direction = true; // initially all elements are moving to the left
    }
    generatePermutations(elements, n);
    free(elements);
    return 0;
}

