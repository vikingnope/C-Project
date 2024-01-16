#ifndef ASSIGNMENT_QUESTION_2_SETMETHODSA_H
#define ASSIGNMENT_QUESTION_2_SETMETHODSA_H

#define MAX_STRING_LENGTH 64 // Maximum length of a string
#define MAX_SET_SIZE 100 // Maximum number of elements in a set

typedef struct {
    int elementType;
    void **elements;
    int size;
} GenSet; // Generic set

void initSet(GenSet *set, int elementType); // Initializes a set
void deinitSet(GenSet *set); // Deinitializes a set
int addToSet(GenSet *set, void *element); // Adds an element to the set
void displaySet(GenSet set); // Displays the set
GenSet *unionSet(GenSet set1, GenSet set2); // Returns the union of two sets
GenSet *intersectSet(GenSet set1, GenSet set2); // Returns the intersection of two sets
GenSet *diffSet(GenSet set1, GenSet set2);  // Returns the difference of two sets
int countSet(GenSet set); // Returns the number of elements in the set
void *isSubsetSet(GenSet set1, void *element); // Checks if an element is a subset of a set
int isEmptySet(GenSet set); // Checks if the set is empty

#endif //ASSIGNMENT_QUESTION_2_SETMETHODSA_H