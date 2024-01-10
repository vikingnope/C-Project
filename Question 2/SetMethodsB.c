#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "setMethodsB.h"

void initSet(GenSet *set, int elementType) {
    set->elementType = elementType;
    set->size = 0;
    set->elements = (void **)malloc(MAX_SET_SIZE * sizeof(void *));
    set->setOfSets = (GenSet **)malloc(MAX_SET_SIZE * sizeof(GenSet *));

    if (set->elements == NULL || set->setOfSets == NULL) {
        printf("Memory allocation failed for elements or set of sets in initSet\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_SET_SIZE; ++i) {
        set->elements[i] = NULL;
        set->setOfSets[i] = NULL;
    }
}

void deinitSet(GenSet *set) {
    if (set == NULL) {
        return; // Do nothing if the set is already NULL
    }

    // Deallocate memory for elements based on the element type
    for (int i = 0; i < set->size; ++i) {
        if (set->elementType == 0 || set->elementType == 1) { // Integer or String type
            free(set->elements[i]);
        } else if (set->elementType == 2) { // Set of sets type
            deinitSet(set->setOfSets[i]); // Recursively deinit nested sets
            free(set->setOfSets[i]);
        }
    }

    // Free memory for the elements and set of sets arrays
    free(set->elements);
    free(set->setOfSets);

    // Reset the set structure
    set->size = 0;
    set->elementType = -1; // Reset element type to an invalid value
}


int addToSet(GenSet *set, void *element) {
    if (set->size == MAX_SET_SIZE) {
        printf("Set is full\n");
        return 0;
    }

    // Check for duplicates
    for (int i = 0; i < set->size; ++i) {
        if (set->elementType == 0) { // Integer type
            if (*((int *)element) == *((int *)(set->elements[i]))) {
                printf("Element '%d' already exists in set.\n", *((int *)element));
                return 0;
            }
        } else if (set->elementType == 1) { // String type
            if (strcmp((char *)element, (char *)(set->elements[i])) == 0) {
                printf("Element '%s' already exists in set.\n", (char *)element);
                return 0;
            }
        }
    }

    // Allocate memory and copy the element
    if (set->elementType == 0) { // Integer type
        int *newElement = (int *)malloc(sizeof(int));
        if (newElement == NULL) {
            printf("Memory allocation failed for new element in addToSet\n");
            return 0;
        }
        *newElement = *((int *)element);
        set->elements[set->size] = newElement;
    } else if (set->elementType == 1) { // String type
        char *newElement = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if (newElement == NULL) {
            printf("Memory allocation failed for new element in addToSet\n");
            return 0;
        }
        strcpy(newElement, (char *)element);
        set->elements[set->size] = newElement;
    } else if (set->elementType == 2) {
        if (set->size == MAX_SET_SIZE) {
            printf("Set of sets is full\n");
            return 0;
        }

        // Ensure the element being added is a GenSet pointer
        if (!element || !((GenSet *)element)) {
            printf("Invalid element for a set of sets\n");
            return 0;
        }

        // Check for duplicates or existing sets within the set of sets
        for (int i = 0; i < set->size; ++i) {
            if (set->setOfSets[i] == (GenSet *)element) {
                printf("Set already exists in set of sets.\n");
                return 0;
            }
        }

        // Add the set to the set of sets
        set->setOfSets[set->size] = (GenSet *)element;
    }

    set->size++;
    return 1;
}


void displaySet(GenSet *set) {
    for (int i = 0; i < set->size; ++i) {
        if (set->elementType == 1) {
            printf("%s ", (char *)(set -> elements[i]));
        } else if (set->elementType == 2) {
            displaySet(set->setOfSets[i]);
        } else {
            printf("%d ", *((int *)(set -> elements[i])));
        }
    }
    printf("\n");
}

GenSet *unionSet(GenSet *set1, GenSet *set2) {
    GenSet *setUnion = (GenSet *)malloc(sizeof(GenSet));

    if (setUnion == NULL) {
        printf("Memory allocation failed for result in setUnion\n");
        return NULL;
    }

    initSet(setUnion, set1->elementType); // Initialize unionSet with the element type of set1

    // Add elements from set1 to unionSet
    for (int i = 0; i < set1->size; ++i) {
        addToSet(setUnion, set1->elements[i]);
    }

    // Add elements from set2 to unionSet
    for (int i = 0; i < set2->size; ++i) {
        if (set2->elementType != 2) {
            addToSet(setUnion, set2->elements[i]); // For non-set of sets elements
        } else {
            // For sets of sets elements
            // If the element is a set of sets, call setUnion instead of unionSet (recursive call)
            GenSet *subSetUnion = unionSet((GenSet *)set2->elements[i], (GenSet *)set2->elements[i]);
            if (subSetUnion != NULL) {
                addToSet(setUnion, subSetUnion);
                free(subSetUnion); // Free the memory allocated for subSetUnion
            } else {
                printf("Error getting setUnion for sets of sets. Exiting.\n");
                // Clean up allocated memory for unionSet and return NULL
                deinitSet(setUnion);
                free(setUnion);
                return NULL;
            }
        }
    }

    return setUnion;
}


GenSet *intersectSet(GenSet *set1, GenSet *set2) {
    GenSet *result = (GenSet *)malloc(sizeof(GenSet));

    if (result == NULL) {
        printf("Memory allocation failed for result in setIntersection\n");
        return NULL;
    }

    initSet(result, set1->elementType);

    for (int i = 0; i < set1->size; ++i) {
        if (set1->elementType != 2 && isSubsetSet(set2, set1->elements[i])) {
            addToSet(result, set1->elements[i]);
        } else if (set1->elementType == 2) {
            // For sets of sets, check intersection by recursively calling setIntersection
            GenSet *subSetIntersection = intersectSet((GenSet *)set1->elements[i], set2);
            if (subSetIntersection != NULL) {
                addToSet(result, subSetIntersection);
                free(subSetIntersection); // Free the memory allocated for subSetIntersection
            } else {
                printf("Error getting setIntersection for sets of sets. Exiting.\n");
                // Clean up allocated memory for result and return NULL
                deinitSet(result);
                free(result);
                return NULL;
            }
        }
    }

    if (countSet(result) == 0) {
        printf("No intersection found.\n");
    }

    return result;
}


GenSet *diffSet(GenSet *set1, GenSet *set2) {
    GenSet *diffSet = (GenSet *)malloc(sizeof(GenSet));

    if (diffSet == NULL) {
        printf("Memory allocation failed for result in setDifference\n");
        return NULL;
    }

    initSet(diffSet, set1->elementType);

    for (int i = 0; i < set1->size; ++i) {
        int isFound = 0;
        if (set1->elementType != 2) {
            // For non-sets of sets elements, check if the element exists in set2
            for (int j = 0; j < set2->size; ++j) {
                if (set1->elementType == 0) { // Integer type
                    if (*((int *)(set1->elements[i])) == *((int *)(set2->elements[j]))) {
                        isFound = 1;
                        break;
                    }
                } else if (set1->elementType == 1) { // String type
                    if (strcmp((char *)(set1->elements[i]), (char *)(set2->elements[j])) == 0) {
                        isFound = 1;
                        break;
                    }
                }
            }
        } else {
            // For sets of sets elements, recursively call setDifference
            if (isSubsetSet(set2, set1->elements[i])) {
                isFound = 1;
            }
        }
        if (!isFound) {
            addToSet(diffSet, set1->elements[i]);
        }
    }
    return diffSet;
}

int countSet(GenSet *set) {
    int count = 0;

    for (int i = 0; i < set->size; ++i) {
        if (set->elementType != 2) {
            count++;
        } else {
            GenSet *subSet = set->setOfSets[i];
            count += countSet(subSet); // Recursively count elements within the set
        }
    }

    return count;
}

void *isSubsetSet(GenSet *set1, void *element) {
    for (int i = 0; i < set1->size; ++i) {
        if (set1->elementType != 2) {
            if (set1->elementType == 0 && *((int *)element) == *((int *)(set1->elements[i]))) {
                return set1->elements[i];
            } else if (set1->elementType == 1 && strcmp((char *)element, (char *)(set1->elements[i])) == 0) {
                return set1->elements[i];
            }
        } else {
            // For sets of sets elements, recursively call isSubsetSet
            void *subsetFound = isSubsetSet((GenSet *)set1->elements[i], element);
            if (subsetFound != 0) {
                return subsetFound;
            }
        }
    }
    return 0;
}

int isEmptySet(GenSet *set) {
    if (set->elementType != 2) {
        // For non-sets of sets elements, check if the set is empty
        return set->size == 0;
    } else {
        // For sets of sets elements, check if all nested sets are empty recursively
        for (int i = 0; i < set->size; ++i) {
            GenSet *subSet = set->setOfSets[i];
            if (!isEmptySet(subSet) || subSet->size > 0) {
                return 0; // Not empty as a non-empty set or set of sets is found
            }
        }
        return 1; // All nested sets are empty
    }
}

void export(GenSet *set, char *filename, int type) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Unable to open file for export\n");
        return;
    }

    if (set->elementType != 2 && type == 1) {
        fprintf(file, "Start of set of sets\n");
    }

    for (int i = 0; i < set->size; ++i) {
        if (set->elementType != 2) {
            if (type == 1) {
                fprintf(file, "\tElement %d: ", i + 1);
            } else {
                fprintf(file, "Element %d: ", i + 1);
            }
            if (set->elementType == 0) { // Integer type
                fprintf(file, "%d\n", *((int *)set->elements[i]));
            } else if (set->elementType == 1) { // String type
                fprintf(file, "%s\n", (char *)set->elements[i]);
            }
        } else {
            export(set->setOfSets[i], filename, 1); // Recursively export nested set
        }
    }

    if (set->elementType != 2 && type == 1) {
        fprintf(file, "End of set of sets\n\n");
    }
    fclose(file); // Close the file after exporting is completed

    fflush(file);
}










