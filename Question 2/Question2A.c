#include <stdio.h>
#include <stdlib.h>
#include "setMethodsA.h"
#include "testingStructFileA.h"

int main() {
    // Removes files from previous runs

    // Clears buffer in cases where terminal does not output anything
    setbuf(stdout, 0);

    printf("Welcome to the Set Operations Program!\n\n");

    // Initialises the set
    GenSet *nameSet1 = ((GenSet *) malloc(sizeof(GenSet)));
    initSet(nameSet1, 1, 5, &getSizeOfFriendNames, &compareFriendNames, &addFriendNamesToSet, &displayFriendNames);

    // Adds elements to the set
    addToSet(nameSet1, &(FriendNames){"John"});
    addToSet(nameSet1, &(FriendNames){"Mary"});
    addToSet(nameSet1, &(FriendNames){"Peter"});

    // Displays the set
    printf("\nThe name set 1 contains:\n");
    displaySet(nameSet1);

    // Initialises the set
    GenSet *numberSet = ((GenSet *) malloc(sizeof(GenSet)));
    initSet(numberSet, 2, 5, &getSizeOfFriendNumbers, &compareFriendNumbers, &addFriendNumbersToSet, &displayFriendNumbers);

    addToSet(numberSet, &(FriendNumbers){123});
    addToSet(numberSet, &(FriendNumbers){456});
    addToSet(numberSet, &(FriendNumbers){789});

    // Displays the set
    printf("\nThe number set contains:\n");
    displaySet(numberSet);

    GenSet *nameSet2 = ((GenSet *) malloc(sizeof(GenSet)));
    initSet(nameSet2, 1, 5, &getSizeOfFriendNames, &compareFriendNames, &addFriendNamesToSet, &displayFriendNames);

    // Adds elements to the set
    addToSet(nameSet2, &(FriendNames){"Aiden"});
    addToSet(nameSet2, &(FriendNames){"Kate"});
    addToSet(nameSet2, &(FriendNames){"Liam"});

    // Displays the set
    printf("\nThe name set 2 contains:\n");
    displaySet(nameSet2);

    GenSet *nameSet3 = ((GenSet *) malloc(sizeof(GenSet)));
    initSet(nameSet3, 1, 5, &getSizeOfFriendNames, &compareFriendNames, &addFriendNamesToSet, &displayFriendNames);

    // Union of nameSet1 and nameSet2
    GenSet *unionSetNamesResult = unionSet(nameSet1, nameSet2);

    if (unionSetNamesResult != NULL) {
        printf("\nThe union of nameSet1 and nameSet2 contains:\n");
        displaySet(unionSetNamesResult);
        deinitSet(unionSetNamesResult);
    }

    // Union of nameSet1 and numberSet
    GenSet *unionSetNamesNumbersResult = unionSet(nameSet1, numberSet);

    if (unionSetNamesNumbersResult != NULL) {
        printf("\nThe union of nameSet1 and numberSet contains:\n");
        displaySet(unionSetNamesNumbersResult);
        deinitSet(unionSetNamesNumbersResult);
    }

    // Intersection of nameSet1 and nameSet2
    GenSet *intersectionSetNamesResult = intersectSet(nameSet1, nameSet2);

    if (intersectionSetNamesResult != NULL) {
        printf("\nThe intersection of nameSet1 and nameSet2 contains:\n");
        displaySet(intersectionSetNamesResult);
        deinitSet(intersectionSetNamesResult);
    }

    // Intersection of nameSet1 and numberSet
    GenSet *intersectionSetNamesNumbersResult = intersectSet(nameSet1, numberSet);

    if (intersectionSetNamesNumbersResult != NULL) {
        printf("\nThe intersection of nameSet1 and numberSet contains:\n");
        displaySet(intersectionSetNamesNumbersResult);
        deinitSet(intersectionSetNamesNumbersResult);
    }

    // Difference of nameSet1 and nameSet2
    GenSet *differenceSetNamesResult = diffSet(nameSet1, nameSet2);

    if (differenceSetNamesResult != NULL) {
        printf("\nThe difference of nameSet1 and nameSet2 contains:\n");
        displaySet(differenceSetNamesResult);
        deinitSet(differenceSetNamesResult);
    }

    // Difference of nameSet1 and numberSet
    GenSet *differenceSetNamesNumbersResult = diffSet(nameSet1, numberSet);

    if (differenceSetNamesNumbersResult != NULL) {
        printf("\nThe difference of nameSet1 and numberSet contains:\n");
        displaySet(differenceSetNamesNumbersResult);
        deinitSet(differenceSetNamesNumbersResult);
    }

    // Is subset of nameSet1
    GenSet *isSubsetSetNamesResult = isSubsetSet(nameSet1, &(FriendNames){"John"});

    if (isSubsetSetNamesResult != NULL) {
        printf("\nThe element John is a subset of nameSet1\n");
    } else {
        printf("\nThe element John is not a subset of nameSet1\n");
    }

    // Is empty set nameSet1
    int isEmptySetResult = isEmptySet(nameSet1);

    if (isEmptySetResult != 1) {
        printf("\nThe set 'nameSet1' is not empty\n");
    } else {
        printf("\nThe set 'nameSet1' is empty\n");
    }

    // Is empty set nameSet3
    isEmptySetResult = isEmptySet(nameSet3);

    if (isEmptySetResult != 1) {
        printf("\nThe set 'nameSet3' is not empty\n");
    } else {
        printf("\nThe set 'nameSet3' is empty\n");
    }

    // Counts the number of elements in the set
    int countSetResult = countSet(nameSet1);

    printf("\nThe number of elements in the set 'nameSet1' is %d\n", countSetResult);

    // Deinitialises the set
    deinitSet(nameSet1);
    deinitSet(numberSet);
    deinitSet(nameSet2);
    deinitSet(nameSet3);

    printf("\nThank you for using this program. Goodbye!\n");

    return 0;
}