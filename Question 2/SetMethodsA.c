#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "setMethodsA.h"

void initSet(GenSet *set, int elementType) {
    set->elementType = elementType;
    set->size = 0;
    set->elements = (void **)malloc(MAX_SET_SIZE * sizeof(void *));
    if (set->elements == NULL) {
        printf("Memory allocation failed for elements in initSet\n");
        printf("\n");
        exit(EXIT_FAILURE);
    }
}

void deinitSet(GenSet *set) {
    for (int i = 0; i < set->size; ++i) {
        free(set->elements[i]); // Free each element
    }
    free(set->elements); // Free the array of elements
    free(set); // Free the set
}

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
        int *newElement = (int *)malloc(sizeof(int));
        if (newElement == NULL) {
            printf("Memory allocation failed for newElement in addToSet\n");
            printf("\n");
            exit(EXIT_FAILURE);
        }
        *newElement = *((int *)element);
        set->elements[set->size] = newElement;
    } else if (set->elementType == 1) { // String type
        char *newElement = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if (newElement == NULL) {
            printf("Memory allocation failed for newElement in addToSet\n");
            printf("\n");
            exit(EXIT_FAILURE);
        }
        strcpy(newElement, (char *)element);
        set->elements[set->size] = newElement;
    }
    set->size++;
    return 1;
}


void displaySet(GenSet set) {
    for (int i = 0; i < set.size; ++i) {
        if(isalpha(*((char *)(set.elements[i])))) {
            printf("%s ", (char *)(set.elements[i]));
        } else {
            printf("%d ", * (int *)(set.elements[i]));
        }
    }
    printf("\n");
}

GenSet *unionSet(GenSet set1, GenSet set2) {
    GenSet *unionSet = (GenSet*)malloc(sizeof(GenSet));

    if (unionSet == NULL) {
        printf("Memory allocation failed for result in intersectSet\n");
        return NULL;
    }

    initSet(unionSet, set2.elementType);

    for (int i = 0; i < set1.size; ++i) {
        addToSet(unionSet, set1.elements[i]);
    }
    for (int i = 0; i < set2.size; ++i) {
        addToSet(unionSet, set2.elements[i]);
    }
    return unionSet;
}

GenSet *intersectSet(GenSet set1, GenSet set2) {
    GenSet *result = (GenSet*)malloc(sizeof(GenSet));

    if (result == NULL) {
        printf("Memory allocation failed for result in intersectSet\n");
        return NULL;
    }

    initSet(result, set1.elementType);

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

GenSet *diffSet(GenSet set1, GenSet set2) {
    GenSet *diffSet = (GenSet*)malloc(sizeof(GenSet));

    if (diffSet == NULL) {
        printf("Memory allocation failed for result in intersectSet\n");
        return NULL;
    }

    initSet(diffSet, set1.elementType);

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

int countSet(GenSet set) {
    return set.size;
}

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

int isEmptySet(GenSet set) {
    return set.size == 0;
}