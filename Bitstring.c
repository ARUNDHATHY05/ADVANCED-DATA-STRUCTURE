#include <stdio.h>

#define MAX_SIZE 64

// Function to initialize a set
void initializeSet(unsigned long long int set[], int size) {
    for (int i = 0; i < size; i++) {
        set[i] = 0;
    }
}

// Function to add an element to the set
void addElement(unsigned long long int set[], int element) {
    set[element / 64] |= (1ULL << (element % 64));
}

// Function to remove an element from the set
void removeElement(unsigned long long int set[], int element) {
    set[element / 64] &= ~(1ULL << (element % 64));
}

// Function to display the set as a bit string
void displaySet(unsigned long long int set[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 63; j >= 0; j--) {
            if (set[i] & (1ULL << j)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf(" ");
    }
    printf("\n");
}

// Function to perform union of two sets
void unionSets(unsigned long long int set1[], unsigned long long int set2[], unsigned long long int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = set1[i] | set2[i];
    }
}

// Function to perform intersection of two sets
void intersectSets(unsigned long long int set1[], unsigned long long int set2[], unsigned long long int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = set1[i] & set2[i];
    }
}

// Function to perform complement of a set
void complementSet(unsigned long long int set[], unsigned long long int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = ~set[i];
    }
}

int main() {
    int size;
    printf("Enter the size of the sets: ");
    scanf("%d", &size);

    unsigned long long int set1[MAX_SIZE], set2[MAX_SIZE], result[MAX_SIZE];
    initializeSet(set1, size);
    initializeSet(set2, size);
    initializeSet(result, size);

    int choice, element;

    do {
        printf("\nSet Operations Menu:\n");
        printf("1. Add element to set 1\n");
        printf("2. Remove element from set 1\n");
        printf("3. Add element to set 2\n");
        printf("4. Remove element from set 2\n");
        printf("5. Display sets\n");
        printf("6. Perform union\n");
        printf("7. Perform intersection\n");
        printf("8. Perform complement\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add to set 1: ");
                scanf("%d", &element);
                addElement(set1, element);
                break;
            case 2:
                printf("Enter element to remove from set 1: ");
                scanf("%d", &element);
                removeElement(set1, element);
                break;
            case 3:
                printf("Enter element to add to set 2: ");
                scanf("%d", &element);
                addElement(set2, element);
                break;
            case 4:
                printf("Enter element to remove from set 2: ");
                scanf("%d", &element);
                removeElement(set2, element);
                break;
            case 5:
                printf("Set 1: ");
                displaySet(set1, size);
                printf("Set 2: ");
                displaySet(set2, size);
                break;
            case 6:
                unionSets(set1, set2, result, size);
                printf("Union: ");
                displaySet(result, size);
                break;
            case 7:
                intersectSets(set1, set2, result, size);
                printf("Intersection: ");
                displaySet(result, size);
                break;
            case 8:
                complementSet(set1, result, size);
                printf("Complement of set 1: ");
                displaySet(result, size);
                break;
        }
    } while (choice != 0);

    return 0;
}
