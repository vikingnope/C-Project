#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "setMethodsA.h"

/**
 * Initializes a set with the given element type
 */
void initSet(GenSet *set, int elementType) {
    set->elementType = elementType;
    set->size = 0;
    set->elements = (void **)malloc(MAX_SET_SIZE * sizeof(void *)); // Allocate memory for the array of elements
    if (set->elements == NULL) {
        printf("Memory allocation failed for elements in initSet\n");
        printf("\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Deinitializes a set
 */
void deinitSet(GenSet *set) {
    for (int i = 0; i < set->size; ++i) {
        free(set->elements[i]); // Free each element
    }
    free(set->elements); // Free the array of elements
    free(set); // Free the set
}

/**
 * Adds an element to the set
 */
int addToSet(GenSet *set, void *element) {
    if (set->size == MAX_SET_SIZE) {
        printf("Set is full\n");
        printf("\n");
        return 0;
    } else if (isSubsetSet(*set, element) != 0) {
        if(isalpha(*((char *)(element)))) {
            printf("Element '%s' already exists in set.\n", (char *)(element));
        } else {
            printf("Element '%d' already exists in set.\n", *(int *)(element));
        }
        return 0;
    } else if (set->elementType == 0) { // Integer type
        int *newElement = (int *)malloc(sizeof(int)); // Allocate memory for the new element
        if (newElement == NULL) {
            printf("Memory allocation failed for newElement in addToSet\n");
            printf("\n");
            exit(EXIT_FAILURE);
        }
        *newElement = *((int *)element); // Copy the value of the element to the new element
        set->elements[set->size] = newElement; // Add the new element to the set
    } else if (set->elementType == 1) { // String type
        char *newElement = (char *)malloc(MAX_STRING_LENGTH * sizeof(char)); // Allocate memory for the new element
        if (newElement == NULL) {
            printf("Memory allocation failed for newElement in addToSet\n");
            printf("\n");
            exit(EXIT_FAILURE);
        }
        strcpy(newElement, (char *)element); // Copy the value of the element to the new element
        set->elements[set->size] = newElement; // Add the new element to the set
    }
    set->size++;
    return 1;
}

/**
 * Displays the set
 */
void displaySet(GenSet set) {
    for (int i = 0; i < set.size; ++i) {
        // Check if element is of type string
        if(isalpha(*((char *)(set.elements[i])))) {
            printf("%s ", (char *)(set.elements[i]));
        } else {
            printf("%d ", * (int *)(set.elements[i]));
        }
    }
    printf("\n");
}

/**
 * Unions two sets if they are of the same type
 */
GenSet *unionSet(GenSet set1, GenSet set2) {
    // Check if sets are of the same type
    if (set1.elementType != set2.elementType) {
        printf("\nCannot perform union on sets of different types.\n");
        return NULL;
    }

    GenSet *unionSet = (GenSet*)malloc(sizeof(GenSet)); // Allocate memory for the union set

    if (unionSet == NULL) {
        printf("Memory allocation failed for result in intersectSet\n");
        return NULL;
    }

    initSet(unionSet, set2.elementType);

    // Add elements of set1 to unionSet
    for (int i = 0; i < set1.size; ++i) {
        addToSet(unionSet, set1.elements[i]);
    }
    // Add elements of set2 to unionSet
    for (int i = 0; i < set2.size; ++i) {
        addToSet(unionSet, set2.elements[i]);
    }
    return unionSet;
}

/**
 * Intersects two sets if they are of the same type
 */
GenSet *intersectSet(GenSet set1, GenSet set2) {
    // Check if sets are of the same type
    if (set1.elementType != set2.elementType) {
        printf("Cannot perform union on sets of different types.\n");
        return NULL;
    }

    GenSet *result = (GenSet*)malloc(sizeof(GenSet)); // Allocate memory for the intersection set

    if (result == NULL) {
        printf("Memory allocation failed for result in intersectSet\n");
        return NULL;
    }

    initSet(result, set1.elementType);

    // Add elements of set1 to result if they are also in set2
    for (int i = 0; i < set1.size; ++i) {
        if (isSubsetSet(set2, set1.elements[i])) {
            addToSet(result, set1.elements[i]);
        }
    }

    if (countSet(*result) == 0) {
        printf("No intersection found.");
    }

    return result;
}

/**
 * Finds the difference between two sets if they are of the same type
 */
GenSet *diffSet(GenSet set1, GenSet set2) {
    // Check if sets are of the same type
    if (set1.elementType != set2.elementType) {
        printf("Cannot perform union on sets of different types.\n");
        return NULL;
    }

    GenSet *diffSet = (GenSet*)malloc(sizeof(GenSet)); // Allocate memory for the difference set

    if (diffSet == NULL) {
        printf("Memory allocation failed for result in intersectSet\n");
        return NULL;
    }

    initSet(diffSet, set1.elementType);

    // Add elements of set1 to result if they are not in set2
    for (int i = 0; i < set1.size; ++i) {
        int isFound = 0;
        for (int j = 0; j < set2.size; ++j) {
            if (set1.elementType == 0) { // Integer type
                if (*((int *)(set1.elements[i])) == *((int *)(set2.elements[j]))) {
                    isFound = 1;
                    break;
                }
            } else if (set1.elementType == 1) { // String type
                if (strcmp((char *)(set1.elements[i]), (char *)(set2.elements[j])) == 0) {
                    isFound = 1;
                    break;
                }
            }
        }
        if (!isFound) {
            addToSet(diffSet, set1.elements[i]);
        }
    }
    return diffSet;
}

/**
 * Counts the number of elements in the set
 */
int countSet(GenSet set) {
    return set.size;
}

/**
 * Checks if the given element is a subset of the set
 */
void *isSubsetSet(GenSet set1, void *element) {
    for (int i = 0; i < set1.size; ++i) {
        if (set1.elementType == 0) {
            if (*((int *)element) == *((int *)(set1.elements[i]))) {
                return set1.elements[i];
            }
        } else if (set1.elementType == 1) {
            if (strcmp((char *)element, (char *)(set1.elements[i])) == 0) {
                return set1.elements[i];
            }
        }
    }
    return 0;
}

/**
 * Checks if the set is empty
 */
int isEmptySet(GenSet set) {
    return set.size == 0;
}