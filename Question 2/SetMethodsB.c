#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "setMethodsB.h"

/**
  * This function initialises the set with the following parameters
 */
void initSet(GenSet *set, int elementType, int initSize, getSizeOfFP getSizeOfFP, compareFP compareFP, addToSetFP addToSetFP, displayFP displayFP, exportFP exportFP){
    set->FunctionPointers.getSizeOfFP = getSizeOfFP; // getSizeOfFP is a function pointer
    set->FunctionPointers.compareFP = compareFP; // compareFP is a function pointer
    set->FunctionPointers.addToSetFP = addToSetFP; // addToSetFP is a function pointer
    set->FunctionPointers.displayFP = displayFP; // displayFP is a function pointer
    set->FunctionPointers.exportFP = exportFP; // exportFP is a function pointer
    set->elementType = elementType; // elementType is an integer
    set->memorySize = initSize; // initSize is an integer
    set->usedSize = 0; // usedSize is an integer
    set->elements = (void *)malloc( initSize * (*set->FunctionPointers.getSizeOfFP)()); // getSizeOfFP is a function pointer

    // Check if memory allocation failed
    if (set->elements == NULL) {
        printf("Memory allocation failed for elements or set of sets in initSet\n");
        exit(EXIT_FAILURE);
    }
}

/**
  * This function deinitialises the set
 */
void deinitSet(GenSet *set) {
    free(set->elements); // free elements
    free(set); // free the set
}

/**
  * This function adds an element to the set
 */
int addToSet(GenSet *set, void *element) {
    // Check if set is full
    if (set -> usedSize == set -> memorySize) {
        printf("Set is full, adding more memory...\n");
        if((set->elements = (void *)realloc(set->elements, (set-> memorySize + 5) * (*set->FunctionPointers.getSizeOfFP)())) == NULL){
            printf("Memory allocation failed for elements or set of sets in addToSet\n");
            exit(EXIT_FAILURE);
        }
        set-> memorySize += 5;
    }

    // Check for duplicates
    for (int i = 0; i < set->usedSize; i++) {
        if ((*set->FunctionPointers.compareFP)((&((char *)set->elements)[i * (*set->FunctionPointers.getSizeOfFP)()]), element) == 1) {
            if(isalpha(*(char *)(element))) {
                printf("\nElement '%s' already exists in set.\n\n", (char *)(element));
            } else {
                printf("\nElement '%d' already exists in set.\n\n", *(int *)(element));
            }
            return 0;
        }
    }

    // Add element to set
    if ((*set->FunctionPointers.addToSetFP)((&((char *)set->elements)[set->usedSize * (*set->FunctionPointers.getSizeOfFP)()]), element) == 0) {
        printf("Unable to add element %s to set\n", (char *)element);
        return 0;
    } else {

        if (set->elementType == 1 || set->elementType == 2) {
            if (isalpha(*((char *) (element)))) {
                printf("Element '%s' added to set\n", (char *) element);
            } else {
                printf("Element '%d' added to set\n", *(int *) (element));
            }
        }
    }

    set->usedSize++;

    return 1;
}

/**
  * This function displays the set
 */
void displaySet(GenSet *set) {
    for (int i = 0; i < set->usedSize; i++) {
        (*set->FunctionPointers.displayFP)(&((char *)set->elements)[i * (*set->FunctionPointers.getSizeOfFP)()]);
    }
    printf("\n");
}

/**
  * This function performs union
 */
GenSet *unionSet(GenSet *set1, GenSet *set2) {
    // Check if the sets have different element types
    if (set1->elementType != set2->elementType) {
        printf("Error in Union: The sets have different element types\n");
        return NULL; // Return NULL if the sets have different element types
    }

    GenSet *result = (GenSet *)malloc(sizeof(GenSet));

    if (result == NULL) {
        printf("Memory allocation failed for result in setUnion\n");
        return NULL;
    }

    initSet(result, 3, set1->memorySize + set2->memorySize, set1->FunctionPointers.getSizeOfFP, set1->FunctionPointers.compareFP, set1->FunctionPointers.addToSetFP, set1->FunctionPointers.displayFP, set1->FunctionPointers.exportFP);

    for (int i = 0; i < set1->usedSize; i++) {
        addToSet(result, &((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()]);
    }

    for (int i = 0; i < set2->usedSize; i++) {
        addToSet(result, &((char *)set2->elements)[i * (*set2->FunctionPointers.getSizeOfFP)()]);
    }

    return result;
}

/**
  * This function performs intersection
 */
GenSet *intersectSet(GenSet *set1, GenSet *set2) {
    // Check if the sets have different element types
    if (set1->elementType != set2->elementType) {
        printf("Error in Intersection: The sets have different element types\n");
        return NULL; // Return NULL if the sets have different element types
    }

    GenSet *result = (GenSet *)malloc(sizeof(GenSet));

    if (result == NULL) {
        printf("Memory allocation failed for result in setIntersection\n");
        return NULL;
    }

    initSet(result, 4, set1->memorySize, set1->FunctionPointers.getSizeOfFP, set1->FunctionPointers.compareFP, set1->FunctionPointers.addToSetFP, set1->FunctionPointers.displayFP, set1->FunctionPointers.exportFP);

    for (int i = 0; i < set1->usedSize; i++) {
        for (int j = 0; j < set2->usedSize; j++) {
            if ((*set1->FunctionPointers.compareFP)(&((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()], &((char *)set2->elements)[j * (*set2->FunctionPointers.getSizeOfFP)()]) == 0) {
                addToSet(result, &((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()]);
            }
        }
    }

    return result;
}

/**
  * This function performs difference
 */
GenSet *diffSet(GenSet *set1, GenSet *set2) {
    // Check if the sets have different element types
    if (set1->elementType != set2->elementType) {
        printf("Error in Difference: The sets have different element types\n");
        return NULL; // Return NULL if the sets have different element types
    }

    GenSet *result = (GenSet *)malloc(sizeof(GenSet));

    if (result == NULL) {
        printf("Memory allocation failed for result in setDifference\n");
        return NULL;
    }

    initSet(result, 5, set1->memorySize, set1->FunctionPointers.getSizeOfFP, set1->FunctionPointers.compareFP, set1->FunctionPointers.addToSetFP, set1->FunctionPointers.displayFP, set1->FunctionPointers.exportFP);

    for (int i = 0; i < set1->usedSize; i++) {
        int found = 0;
        for (int j = 0; j < set2->usedSize; j++) {
            if ((*set1->FunctionPointers.compareFP)(&((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()], &((char *)set2->elements)[j * (*set2->FunctionPointers.getSizeOfFP)()]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            addToSet(result, &((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()]);
        }
    }

    return result;
}

/**
  * This function counts the number of elements in the set
 */
int countSet(GenSet *set) {
    return set->usedSize;
}

/**
  * This function checks if the element is a subset of the set
 */
void *isSubsetSet(GenSet *set1, void *element) {
    for (int i = 0; i < set1->usedSize; i++) {
        if ((*set1->FunctionPointers.compareFP)(&((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()], element) == 0) {
            return &((char *)set1->elements)[i * (*set1->FunctionPointers.getSizeOfFP)()];
        }
    }

    return NULL;
}

/**
  * This function checks if the set is empty
 */
int isEmptySet(GenSet *set) {
    return set->usedSize == 0;
}

/**
  * This function exports the set to a file
 */
void export(GenSet *set, char *filename) {
    for (int i = 0; i < set->usedSize; i++) {
        (*set->FunctionPointers.exportFP)(&((char *)set->elements)[i * (*set->FunctionPointers.getSizeOfFP)()], filename, i);
    }
}
