#include <stdio.h>
#include "Question2A.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        free(set->elements[i]); // Free allocated memory for each element
    }
    free(set->elements);
    set->size = 0;
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
        printf("\n");
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

GenSet unionSet(GenSet set1, GenSet set2) {
    GenSet unionSet;
    initSet(&unionSet, set2.elementType);
    for (int i = 0; i < set1.size; ++i) {
        addToSet(&unionSet, set1.elements[i]);
    }
    for (int i = 0; i < set2.size; ++i) {
        addToSet(&unionSet, set2.elements[i]);
    }
    return unionSet;
}

GenSet intersectSet(GenSet set1, GenSet set2) {
    GenSet result;
    initSet(&result, set1.elementType);

    for (int i = 0; i < set1.size; ++i) {
        if (isSubsetSet(set2, set1.elements[i])) {
            addToSet(&result, set1.elements[i]);
        }
    }

    if (countSet(result) == 0) {
        printf("No intersection found.");
    }

    return result;
}

GenSet diffSet(GenSet set1, GenSet set2) {
    GenSet diffSet;
    initSet(&diffSet, set1.elementType);
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
            addToSet(&diffSet, set1.elements[i]);
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

int main() {
    GenSet intSet, stringSet, intStringUnion, intStringIntersect, intStringDiff, stringSet2, stringSetIntersection, intSet2, intSetIntersection;
    initSet(&intSet, 0); // Integer set
    initSet(&stringSet, 1); // String set
    initSet(&stringSet2, 1); // String set
    initSet(&intSet2, 0); // Integer set

    // Adding elements to integer set
    addToSet(&intSet, &(int){10});
    addToSet(&intSet, &(int){20});
    addToSet(&intSet, &(int){30});
    addToSet(&intSet, &(int){40});

    // Adding of elements to integer set 2
    addToSet(&intSet2, &(int){10});

    // Adding elements to string set
    addToSet(&stringSet, "apple");
    addToSet(&stringSet, "orange");
    addToSet(&stringSet, "banana");
    addToSet(&stringSet, "apple"); // Duplicate

    // Adding elements to string set 2
    addToSet(&stringSet2, "apple");

    printf("Integer Set:\n");
    displaySet(intSet);
    printf("\nString Set:\n");
    displaySet(stringSet);

    printf("\nCount of elements in Integer Set: %d", countSet(intSet));
    printf("\nCount of elements in String Set: %d", countSet(stringSet));

    printf("\n\nChecking if Integer Set is empty: %s", isEmptySet(intSet) ? "Yes" : "No");
    printf("\nChecking if String Set is empty: %s", isEmptySet(stringSet) ? "Yes" : "No");

    printf("\n\nIs 20 a subset of Integer Set: %s", isSubsetSet(intSet, &(int){20}) ? "Yes" : "No");
    printf("\nIs 'apple' a subset of String Set: %s", isSubsetSet(stringSet, "apple") ? "Yes" : "No");
    printf("\nIs 'kiwi' a subset of String Set: %s", isSubsetSet(stringSet, "kiwi") ? "Yes" : "No");

    printf("\n\nUnion of Integer Set and String Set: ");
    intStringUnion = unionSet(intSet, stringSet);
    displaySet(intStringUnion);

    printf("\nIntersection of Integer Set and String Set: ");
    intStringIntersect = intersectSet(intSet, stringSet);
    displaySet(intStringIntersect);

    printf("\nIntersection of String Set and String Set 2: ");
    stringSetIntersection = intersectSet(stringSet, stringSet2);
    displaySet(stringSetIntersection);

    printf("\nIntersection of Int Set and Int Set 2: ");
    intSetIntersection = intersectSet(intSet, intSet2);
    displaySet(intSetIntersection);

    printf("\nDifference between Integer Set and String Set: ");
    intStringDiff = diffSet(intSet, stringSet);
    displaySet(intStringDiff);

    deinitSet(&intSet);
    deinitSet(&stringSet);
    deinitSet(&intStringUnion);
    deinitSet(&intStringIntersect);
    deinitSet(&intStringDiff);
    deinitSet(&stringSet2);
    deinitSet(&stringSetIntersection);
    deinitSet(&intSet2);
    deinitSet(&intSetIntersection);

    printf("\nThank you for using this program. Goodbye!\n");

    return 0;
}