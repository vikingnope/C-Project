#include <stdio.h>
#include "setMethodsB.h"
#include <string.h>

void userDefinedSets();
void predefinedSets();

int main() {
    int mainChoice;

    // Clears buffer in cases where terminal does not output anything
    setbuf(stdout, 0);

    printf("Welcome to the Set Operations Program!\n");

    do {
        printf("\n1.Enter your own sets");
        printf("\n2.Use the predefined sets");
        printf("\n3.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &mainChoice);
        while (getchar() != '\n'); // Clear input buffer

        switch (mainChoice) {
            case 1:
                printf("\n");
                userDefinedSets();
                break;
            case 2:
                printf("\n");
                predefinedSets();
                break;
            case 3:
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }while(mainChoice != 3);

    printf("\nThank you for using this program. Goodbye!\n");

    return 0;
}


void userDefinedSets(){
    GenSet intSet, stringSet;
    initSet(&intSet, 0); // Integer set
    initSet(&stringSet, 1); // String set

    int intElement;
    int choice;
    char stringElement[MAX_STRING_LENGTH];

    do{
        printf("\n\nMenu:");
        printf("\n1. Add element to integer set");
        printf("\n2. Add element to string set");
        printf("\n3. Display integer set");
        printf("\n4. Display string set");
        printf("\n5. Count integer set");
        printf("\n6. Count string set");
        printf("\n7. Check if integer set is empty");
        printf("\n8. Check if string set is empty");
        printf("\n9. Check if integer set is a subset of another integer set");
        printf("\n10. Check if string set is a subset of another string set");
        printf("\n11. Check if integer set is a subset of another string set");
        printf("\n12. Check if string set is a subset of another integer set");
        printf("\n13. Union of integer set and string set");
        printf("\n14. Intersection of integer set and string set");
        printf("\n15. Difference between integer set and string set");
        printf("\n16. Export set to file");
        printf("\n17. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        switch(choice){
            case 1:
                printf("\nEnter integer element to add: ");
                scanf("%d", &intElement);
                while (getchar() != '\n'); // Clear input buffer
                addToSet(&intSet, &intElement);
                break;
            case 2:
                printf("\nEnter string element to add: ");
                scanf("%s", stringElement);
                while (getchar() != '\n'); // Clear input buffer
                addToSet(&stringSet, stringElement);
                break;
            case 3:
                printf("\nInteger Set:\n");
                displaySet(&intSet);
                break;
            case 4:
                printf("\nString Set:\n");
                displaySet(&stringSet);
                break;
            case 5:
                printf("\nCount of elements in Integer Set: %d", countSet(&intSet));
                break;
            case 6:
                printf("\nCount of elements in String Set: %d", countSet(&stringSet));
                break;
            case 7:
                printf("\nInteger set is empty: %s", isEmptySet(&intSet) ? "Yes" : "No");
                break;
            case 8:
                printf("\nString set is empty: %s", isEmptySet(&stringSet) ? "Yes" : "No");
                break;
            case 9:
                printf("\nIs integer set a subset of another integer set: %s", isSubsetSet(&intSet, &intElement) ? "Yes" : "No");
                break;
            case 10:
                printf("\nIs string set a subset of another string set: %s", isSubsetSet(&stringSet, stringElement) ? "Yes" : "No");
                break;
            case 11:
                printf("\nIs integer set a subset of another string set: %s", isSubsetSet(&stringSet, &intElement) ? "Yes" : "No");
                break;
            case 12:
                printf("\nIs string set a subset of another integer set: %s", isSubsetSet(&intSet, stringElement) ? "Yes" : "No");
                break;
            case 13:
                printf("\nUnion of Integer Set and String Set: ");
                GenSet *unionResult = unionSet(&intSet, &stringSet);

                if (unionResult != NULL) {
                    displaySet(unionResult);
                    deinitSet(unionResult);
                } else {
                    printf("Error getting unionSet result. Exiting.\n");
                }

                break;
            case 14:
                printf("\nIntersection of Integer Set and String Set: ");

                GenSet *intersectResult = intersectSet(&intSet, &stringSet);

                if(intersectResult != NULL) {
                    displaySet(intersectResult);
                    deinitSet(intersectResult);
                } else {
                    printf("Error getting intersectSet result. Exiting.\n");
                }

                break;
            case 15:
                printf("\nDifference between Integer Set and String Set: ");

                GenSet *diffResult = diffSet(&intSet, &stringSet);

                if(diffResult != NULL) {
                    displaySet(diffResult);
                    deinitSet(diffResult);
                } else {
                    printf("Error getting diffSet result. Exiting.\n");
                }

                break;
            case 16:
                printf("\nExporting Integer Set to file...\n");
                export(&intSet, "intSet.txt", 0);
                printf("\nExporting String Set to file...\n");
                export(&stringSet, "stringSet.txt", 0);
                break;
            case 17:
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (choice != 17);

    deinitSet(&intSet);
    deinitSet(&stringSet);
}

void predefinedSets(){
    GenSet intSet, stringSet, stringSet2, intSet2;

    char *filenameInt = "intSet.txt";
    char *filenameString = "stringSet.txt";
    char *filenameSets = "setOfSets.txt";


    if (remove(filenameInt) == 0) {
        printf("%s file deleted successfully.\n", filenameInt);
    } else {
        printf("Unable to delete the file: %s\n", filenameInt);
    }


    if (remove(filenameString) == 0) {
        printf("%s file deleted successfully.\n", filenameString);
    } else {
        printf("Unable to delete the file: %s\n", filenameString);
    }

    if (remove(filenameSets) == 0) {
        printf("%s file deleted successfully.\n", filenameSets);
    } else {
        printf("Unable to delete the file: %s\n", filenameSets);
    }

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
    addToSet(&stringSet, "apple"); // Duplicate element

    // Adding elements to string set 2
    addToSet(&stringSet2, "apple");

    GenSet setOfSets;
    initSet(&setOfSets, 2);

    addToSet(&setOfSets, &intSet);
    addToSet(&setOfSets, &stringSet);
    addToSet(&setOfSets, &stringSet2);
    addToSet(&setOfSets, &intSet2);

    printf("\nInteger Set:\n");
    displaySet(&intSet);
    printf("\nString Set:\n");
    displaySet(&stringSet);
    printf("\nSet of Sets:\n");
    displaySet(&setOfSets);

    printf("\nCount of elements in Integer Set: %d", countSet(&intSet));
    printf("\nCount of elements in String Set: %d", countSet(&stringSet));
    printf("\nCount of elements in Set of Sets: %d", countSet(&setOfSets));

    printf("\n\nChecking if Integer Set is empty: %s", isEmptySet(&intSet) ? "Yes" : "No");
    printf("\nChecking if String Set is empty: %s", isEmptySet(&stringSet) ? "Yes" : "No");
    printf("\nChecking if Set of Sets is empty: %s", isEmptySet(&setOfSets) ? "Yes" : "No");

    printf("\n\nIs 20 a subset of Integer Set: %s", isSubsetSet(&intSet, &(int){20}) ? "Yes" : "No");
    printf("\nIs 'apple' a subset of String Set: %s", isSubsetSet(&stringSet, "apple") ? "Yes" : "No");
    printf("\nIs 'kiwi' a subset of String Set: %s", isSubsetSet(&stringSet, "kiwi") ? "Yes" : "No");

    printf("\n\nUnion of Integer Set and String Set: ");
    GenSet *intStringUnion = unionSet(&intSet, &stringSet);

    if(intStringUnion != NULL) {
        displaySet(intStringUnion);
        deinitSet(intStringUnion);
    } else {
        printf("Error getting unionSet result. Exiting.\n");
    }

    printf("\nIntersection of Integer Set and String Set: ");
    GenSet *intStringIntersect = intersectSet(&intSet, &stringSet);

    if(intStringIntersect != NULL) {
        displaySet(intStringIntersect);
        deinitSet(intStringIntersect);
    } else {
        printf("Error getting intersectSet result. Exiting.\n");
    }

    printf("\nIntersection of String Set and String Set 2: ");
    GenSet *stringSetIntersection = intersectSet(&stringSet, &stringSet2);

    if(stringSetIntersection != NULL) {
        displaySet(stringSetIntersection);
        deinitSet(stringSetIntersection);
    } else {
        printf("Error getting intersectSet result. Exiting.\n");
    }

    printf("\nIntersection of Int Set and Int Set 2: ");
    GenSet *intSetIntersection = intersectSet(&intSet, &intSet2);

    if(intSetIntersection != NULL) {
        displaySet(intSetIntersection);
        deinitSet(intSetIntersection);
    } else {
        printf("Error getting intersectSet result. Exiting.\n");
    }

    printf("\nDifference between Integer Set and String Set: ");
    GenSet *intStringDiff = diffSet(&intSet, &stringSet);

    if(intStringDiff != NULL) {
        displaySet(intStringDiff);
        deinitSet(intStringDiff);
    } else {
        printf("Error getting diffSet result. Exiting.\n");
    }

    printf("\nExporting Integer Set to file...\n");
    export(&intSet, filenameInt, 0);
    printf("\nExporting String Set to file...\n");
    export(&stringSet, filenameString, 0);
    printf("\nExporting Set of Sets to file...\n");
    export(&setOfSets, filenameSets, 1);
}