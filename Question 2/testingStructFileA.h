#ifndef ASSIGNMENT_QUESTION_2_TESTINGSTRUCTFILEA_H
#define ASSIGNMENT_QUESTION_2_TESTINGSTRUCTFILEA_H

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 64

// Structs for Friends Names
typedef struct FriendNames {
    char name[MAX_STRING_LENGTH];
} FriendNames;

// Structs for Friends Numbers
typedef struct FriendNumbers {
    int number;
} FriendNumbers;

// Returns the size of FriendNames
size_t getSizeOfFriendNames(){
    return sizeof(FriendNames);
}

// Returns the size of FriendNumbers
size_t getSizeOfFriendNumbers(){
    return sizeof(FriendNumbers);
}

// Compares FriendNames sets
int compareFriendNames(void *element1, void *element2){
    FriendNames *friendName1 = (FriendNames *)element1;
    FriendNames *friendName2 = (FriendNames *)element2;

    return strcmp(friendName1->name, friendName2->name);
}

// Compares FriendNumbers sets
int compareFriendNumbers(void *element1, void *element2){
    FriendNumbers *friendNumber1 = (FriendNumbers *)element1;
    FriendNumbers *friendNumber2 = (FriendNumbers *)element2;

    if (friendNumber1->number > friendNumber2->number){
        return 1;
    } else if (friendNumber1->number < friendNumber2->number){
        return -1;
    } else {
        return 0;
    }
}

// Adds FriendNames sets to the set
int addFriendNamesToSet(void *element1, void *element2){
    FriendNames *friendName1 = (FriendNames *)element1;
    FriendNames *friendName2 = (FriendNames *)element2;

    return strcmp(friendName1->name, friendName2->name);
}

// Adds FriendNumbers sets to the set
int addFriendNumbersToSet(void *element1, void *element2){
    FriendNumbers *friendNumber1 = (FriendNumbers *)element1;
    FriendNumbers *friendNumber2 = (FriendNumbers *)element2;

    if (friendNumber1->number > friendNumber2->number){
        return 1;
    } else if (friendNumber1->number < friendNumber2->number){
        return -1;
    } else {
        return 0;
    }
}

// Displays FriendNames sets
void displayFriendNames(void *element){
    FriendNames *friendName = (FriendNames *)element;

    printf("Friend Name: %s\n", friendName->name);
}

// Displays FriendNumbers sets
void displayFriendNumbers(void *element){
    FriendNumbers *friendNumber = (FriendNumbers *)element;

    printf("Friend Number: %d\n", friendNumber->number);
}

#endif //ASSIGNMENT_QUESTION_2_TESTINGSTRUCTFILEA_H
