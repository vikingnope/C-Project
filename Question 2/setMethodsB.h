#ifndef ASSIGNMENT_QUESTION_2_SETMETHODSB_H
#define ASSIGNMENT_QUESTION_2_SETMETHODSB_H

typedef size_t (*getSizeOfFP)(); // Function pointer to getSizeOf
typedef int (*compareFP)(void *element1, void *element2); // Function pointer to compare
typedef int (*addToSetFP)(void *element1, void *element2); // Function pointer to addToSet
typedef void (*displayFP)(void *element); // Function pointer to display
typedef void (*exportFP)(void *element, char *filename, int index); // Function pointer to export

// Function pointer struct
typedef struct FP {
    getSizeOfFP getSizeOfFP;
    compareFP compareFP;
    addToSetFP addToSetFP;
    displayFP displayFP;
    exportFP exportFP;
} FP;

// Generic Set struct
typedef struct GenSet {
    int elementType;
    void *elements;
    int memorySize;
    int usedSize;
    FP FunctionPointers;
} GenSet;

void initSet(GenSet *set, int elementType, int initSize, getSizeOfFP getSizeOfFP, compareFP compareFP, addToSetFP addToSetFP, displayFP displayFP, exportFP exportFP); // Initialises the set
void deinitSet(GenSet *set); // Deinitialises the set
int addToSet(GenSet *set, void *element); // Adds an element to the set
void displaySet(GenSet *set); // Displays the set
GenSet *unionSet(GenSet *set1, GenSet *set2); // Performs union
GenSet *intersectSet(GenSet *set1, GenSet *set2); // Performs intersection
GenSet *diffSet(GenSet *set1, GenSet *set2); // Performs difference
int countSet(GenSet *set); // Counts the number of elements in the set
void *isSubsetSet(GenSet *set1, void *element); // Checks if the element is a subset of the set
int isEmptySet(GenSet *set); // Checks if the set is empty
void export(GenSet *set, char *filename); // Exports the set to a file

#endif //ASSIGNMENT_QUESTION_2_SETMETHODSB_H
