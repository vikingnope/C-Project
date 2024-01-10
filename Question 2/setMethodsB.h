#ifndef ASSIGNMENT_QUESTION_2_SETMETHODSB_H
#define ASSIGNMENT_QUESTION_2_SETMETHODSB_H

#define MAX_STRING_LENGTH 64
#define MAX_SET_SIZE 100

typedef struct GenSet {
    int elementType;
    void **elements;
    struct GenSet **setOfSets;
    int size;
} GenSet;

void initSet(GenSet *set, int elementType);
void deinitSet(GenSet *set);
int addToSet(GenSet *set, void *element);
void displaySet(GenSet *set);
GenSet *unionSet(GenSet *set1, GenSet *set2);
GenSet *intersectSet(GenSet *set1, GenSet *set2);
GenSet *diffSet(GenSet *set1, GenSet *set2);
int countSet(GenSet *set);
void *isSubsetSet(GenSet *set1, void *element);
int isEmptySet(GenSet *set);
void export(GenSet *set, char *filename, int type);

#endif //ASSIGNMENT_QUESTION_2_SETMETHODSB_H
