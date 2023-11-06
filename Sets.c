#include <stdio.h>
#include <stdlib.h>

// Define a structure for the set element
struct SetElement {
    int data;
    struct SetElement* next;
};

typedef struct SetElement SetElement;

// Function to create a new set
SetElement* createSet() {
    return NULL;
}

// Function to check if an element is in the set
int isElementInSet(SetElement* set, int element) {
    while (set != NULL) {
        if (set->data == element) {
            return 1; // Element is in the set
        }
        set = set->next;
    }
    return 0; // Element is not in the set
}

// Function to insert an element into the set
SetElement* insertElement(SetElement* set, int element) {
    if (!isElementInSet(set, element)) {
        SetElement* newElement = (SetElement*)malloc(sizeof(SetElement));
        newElement->data = element;
        newElement->next = set;
        return newElement;
    }
    return set;
}

// Function to remove an element from the set
SetElement* removeElement(SetElement* set, int element) {
    if (isElementInSet(set, element)) {
        SetElement* current = set;
        SetElement* previous = NULL;

        while (current != NULL) {
            if (current->data == element) {
                if (previous == NULL) {
                    set = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                break;
            }

            previous = current;
            current = current->next;
        }
    }
    return set;
}

// Function to display the elements of a set
void displaySet(SetElement* set) {
    SetElement* current = set;
    printf("Set elements: {");
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    SetElement* setA = createSet();
    SetElement* setB = createSet();
    SetElement* resultSet = createSet();
    int choice, element;

    while (1) {
        printf("\nSet Operations Menu:\n");
        printf("1. Insert element into Set A\n");
        printf("2. Insert element into Set B\n");
        printf("3. Remove element from Set A\n");
        printf("4. Remove element from Set B\n");
        printf("5. Display Set A\n");
        printf("6. Display Set B\n");
        printf("7. Union of Sets A and B\n");
        printf("8. Intersection of Sets A and B\n");
        printf("9. Difference of Set A - Set B\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert into Set A: ");
                scanf("%d", &element);
                setA = insertElement(setA, element);
                break;
            case 2:
                printf("Enter element to insert into Set B: ");
                scanf("%d", &element);
                setB = insertElement(setB, element);
                break;
            case 3:
                printf("Enter element to remove from Set A: ");
                scanf("%d", &element);
                setA = removeElement(setA, element);
                break;
            case 4:
                printf("Enter element to remove from Set B: ");
                scanf("%d", &element);
                setB = removeElement(setB, element);
                break;
            case 5:
                displaySet(setA);
                break;
            case 6:
                displaySet(setB);
                break;
            case 7:
                // Perform the union operation
                // (you can implement this)
                break;
            case 8:
                // Perform the intersection operation
                // (you can implement this)
                break;
            case 9:
                // Perform the difference operation
                // (you can implement this)
                break;
            case 10:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Free memory for sets before exiting
    // (you can implement this)

    return 0;
}
