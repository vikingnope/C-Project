#ifndef ASSIGNMENT_QUESTION_2_QUESTION2B_H
#define ASSIGNMENT_QUESTION_2_QUESTION2B_H

typedef struct GenSet GenSet;

GenSet* initSet(int elementSize, int (*compare)(const void*, const void*), void (*print)(const void*));

void deinitSet(GenSet* set);
int addToSet(GenSet* set, const void* element);
void displaySet(GenSet* set);
void exportSet(GenSet* set, const char* filename);
int isEmptySet(GenSet* set);

#endif //ASSIGNMENT_QUESTION_2_QUESTION2B_H
