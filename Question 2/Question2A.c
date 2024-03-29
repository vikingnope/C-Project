#include <stdio.h>
#include "setMethodsA.h"
#include <string.h>

void userDefinedSets(); // User defined sets
void predefinedSets(); // Predefined sets

int main() {
    int mainChoice;

    printf("Welcome to the Set Operations Program!\n");

    // Menu
    do {
        printf("\n1.Enter your own sets");
        printf("\n2.Use the predefined sets");
        printf("\n3.Exit");
        printf("\n\nEnter your choice: ");

        while (scanf("%d", &mainChoice) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            printf("\n\nEnter your choice: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        while (getchar() != '\n'); // Clear input buffer
        // Switch case for main menu
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
    GenSet intSet, stringSet, stringSet2, intSet2;
    initSet(&intSet, 0); // Integer set
    initSet(&intSet2, 0); // Integer set
    initSet(&stringSet, 1); // String set
    initSet(&stringSet2, 1); // String set

    int intElement;
    int choice;
    char stringElement[MAX_STRING_LENGTH];

    printf("Adding elements to the First Integer Set:\n");
    printf("Enter integers (press Enter without typing anything to stop): ");

    // While loop to get user input
    while (1) {
        char line[MAX_SET_SIZE];
        if (!fgets(line, sizeof(line), stdin)) {
            // Error reading input
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline character, if present
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0') {
            // Stop loop if the user presses Enter without typing anything
            break;
        }

        // Convert the input to an integer
        if (sscanf(line, "%d", &intElement) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            continue; // Skip adding to the set if input is not an integer
        }

        addToSet(&intSet, &intElement);
    }


    printf("\nAdding elements to the First String Set:\n");
    printf("Enter strings (press 'Enter' to stop): ");
    // While loop to get user input
    while (1) {
        if (!fgets(stringElement, sizeof(stringElement), stdin)) {
            // Error reading input
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline character, if present
        stringElement[strcspn(stringElement, "\n")] = '\0';

        if (stringElement[0] == '\0') {
            // Stop loop if the user presses Enter without typing anything
            break;
        }

        addToSet(&stringSet, stringElement);

        // Check for end-of-file
        if (feof(stdin)) {
            break;
        }
    }

    printf("Adding elements to the Second Integer Set:\n");
    printf("Enter integers (press Enter without typing anything to stop): ");

    // While loop to get user input
    while (1) {
        char line[MAX_SET_SIZE];
        if (!fgets(line, sizeof(line), stdin)) {
            // Error reading input
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline character, if present
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0') {
            // Stop loop if the user presses Enter without typing anything
            break;
        }

        // Convert the input to an integer
        if (sscanf(line, "%d", &intElement) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            continue; // Skip adding to the set if input is not an integer
        }

        addToSet(&intSet2, &intElement);
    }

    printf("\nAdding elements to the Second String Set:\n");
    printf("Enter strings (press 'Enter' to stop): ");
    // While loop to get user input
    while (1) {
        if (!fgets(stringElement, sizeof(stringElement), stdin)) {
            // Error reading input
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline character, if present
        stringElement[strcspn(stringElement, "\n")] = '\0';

        if (stringElement[0] == '\0') {
            // Stop loop if the user presses Enter without typing anything
            break;
        }

        addToSet(&stringSet2, stringElement);

        // Check for end-of-file
        if (feof(stdin)) {
            break;
        }
    }

    printf("\nInteger Set:\n");
    displaySet(intSet);
    printf("\nString Set:\n");
    displaySet(stringSet);
    printf("\nInt Set 2:\n");
    displaySet(intSet2);
    printf("\nString Set 2:\n");
    displaySet(stringSet2);

    // Menu
    do{
        printf("\n\nMenu:");
        printf("\n1. Display integer set");
        printf("\n2. Display string set");
        printf("\n3. Display integer set 2");
        printf("\n4. Display string set 2");
        printf("\n5. Count integer set");
        printf("\n6. Count string set");
        printf("\n7. Check if integer set is empty");
        printf("\n8. Check if string set is empty");
        printf("\n9. Check if integer element is a subset of the integer set");
        printf("\n10. Check if string element is a subset of the string set");
        printf("\n11. Union of integer set and integer set 2");
        printf("\n12. Intersection of string set and string set 2");
        printf("\n13. Difference between integer set and integer set 2");
        printf("\n14. Exit");
        printf("\n\nEnter your choice: ");

        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            printf("\n\nEnter your choice: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        switch(choice){
            case 1:
                printf("\nInteger Set:\n");
                displaySet(intSet); // Display integer set
                break;
            case 2:
                printf("\nString Set:\n");
                displaySet(stringSet); // Display string set
                break;
            case 3:
                printf("\nInteger Set 2:\n");
                displaySet(intSet2); // Display integer set 2
                break;
            case 4:
                printf("\nString Set 2:\n");
                displaySet(stringSet2); // Display string set 2
                break;
            case 5:
                printf("\nCount of elements in Integer Set: %d", countSet(intSet)); // Count of elements in integer set
                break;
            case 6:
                printf("\nCount of elements in String Set: %d", countSet(stringSet)); // Count of elements in string set
                break;
            case 7:
                printf("\nInteger set is empty: %s", isEmptySet(intSet) ? "Yes" : "No"); // Check if integer set is empty
                break;
            case 8:
                printf("\nString set is empty: %s", isEmptySet(stringSet) ? "Yes" : "No"); // Check if string set is empty
                break;
            case 9:
                printf("\nEnter an integer: ");

                while (scanf("%d", &intElement) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    printf("\nEnter an integer: ");
                    while (getchar() != '\n'); // Clear input buffer
                }
                printf("\nIs '%d' a found in the integer set: %s", intElement, isSubsetSet(intSet, &intElement) ? "Yes" : "No"); // Check if integer set is a subset of another integer set
                break;
            case 10:
                printf("\nEnter a string: ");
                while (scanf("%s", stringElement) != 1) {
                    printf("Invalid input. Please enter a string.\n");
                    printf("\nEnter a string: ");
                    while (getchar() != '\n'); // Clear input buffer
                }
                printf("\nIs '%s' found in the string set: %s", stringElement, isSubsetSet(stringSet, stringElement) ? "Yes" : "No"); // Check if string set is a subset of another string set
                break;
            case 11:
                printf("\n");

                GenSet *unionResult = unionSet(intSet, intSet2); // Get union of integer set and string set

                // Check if result is NULL
                if (unionResult != NULL) {
                    printf("\nUnion of Integer Set and Integer Set 2: ");
                    displaySet(*unionResult);
                    deinitSet(unionResult);
                } else {
                    printf("Error getting unionSet result.\n");
                }

                break;
            case 12:
                printf("\n");

                GenSet *intersectResult = intersectSet(stringSet, stringSet2); // Get intersection of integer set and string set

                // Check if result is NULL
                if(intersectResult != NULL) {
                    printf("\nIntersection of String Set and String Set 2: ");
                    displaySet(*intersectResult);
                    deinitSet(intersectResult);
                } else {
                    printf("Error getting intersectSet result.\n");
                }

                break;
            case 13:
                printf("\n");

                GenSet *diffResult = diffSet(intSet, intSet2); // Get difference between integer set and string set

                // Check if result is NULL
                if(diffResult != NULL) {
                    printf("\nDifference between Integer Set and Integer Set 2: ");
                    displaySet(*diffResult);
                    deinitSet(diffResult);
                } else {
                    printf("Error getting diffSet result.\n");
                }

                break;
            case 14:
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (choice != 14);

    deinitSet(&intSet); // Deinitialize integer set
    deinitSet(&stringSet); // Deinitialize string set
}

void predefinedSets(){
    GenSet intSet, stringSet, stringSet2, intSet2;
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

    printf("\nInteger Set:\n");
    displaySet(intSet);
    printf("\nString Set:\n");
    displaySet(stringSet);

    printf("\nCount of elements in Integer Set: %d", countSet(intSet)); // Count of elements in integer set
    printf("\nCount of elements in String Set: %d", countSet(stringSet)); // Count of elements in string set

    printf("\n\nChecking if Integer Set is empty: %s", isEmptySet(intSet) ? "Yes" : "No"); // Check if integer set is empty
    printf("\nChecking if String Set is empty: %s", isEmptySet(stringSet) ? "Yes" : "No"); // Check if string set is empty

    printf("\n\nIs 20 a subset of Integer Set: %s", isSubsetSet(intSet, &(int){20}) ? "Yes" : "No"); // Check if 20 is a subset of integer set
    printf("\nIs 'apple' a subset of String Set: %s", isSubsetSet(stringSet, "apple") ? "Yes" : "No"); // Check if 'apple' is a subset of string set
    printf("\nIs 'kiwi' a subset of String Set: %s", isSubsetSet(stringSet, "kiwi") ? "Yes" : "No"); // Check if 'kiwi' is a subset of string set

    printf("\n");

    GenSet *intStringUnion = unionSet(intSet, stringSet); // Get union of integer set and string set

    // Check if result is NULL
    if(intStringUnion != NULL) {
        printf("\n\nUnion of Integer Set and String Set: ");
        displaySet(*intStringUnion);
        deinitSet(intStringUnion);
    } else {
        printf("Error getting unionSet result.\n");
    }

    printf("\n");

    GenSet *intStringIntersect = intersectSet(intSet, stringSet); // Get intersection of integer set and string set

    // Check if result is NULL
    if(intStringIntersect != NULL) {
        printf("\nIntersection of Integer Set and String Set: ");
        displaySet(*intStringIntersect);
        deinitSet(intStringIntersect);
    } else {
        printf("Error getting intersectSet result.\n");
    }

    printf("\n");

    GenSet *stringSetIntersection = intersectSet(stringSet, stringSet2); // Get intersection of string set and string set 2

    // Check if result is NULL
    if(stringSetIntersection != NULL) {
        printf("\nIntersection of String Set and String Set 2: ");
        displaySet(*stringSetIntersection);
        deinitSet(stringSetIntersection);
    } else {
        printf("Error getting intersectSet result.\n");
    }

    printf("\n");

    GenSet *intSetIntersection = intersectSet(intSet, intSet2); // Get intersection of integer set and integer set 2

    // Check if result is NULL
    if(intSetIntersection != NULL) {
        printf("\nIntersection of Int Set and Int Set 2: ");
        displaySet(*intSetIntersection);
        deinitSet(intSetIntersection);
    } else {
        printf("Error getting intersectSet result.\n");
    }

    printf("\n");

    GenSet *intStringDiff = diffSet(intSet, stringSet); // Get difference between integer set and string set

    // Check if result is NULL
    if(intStringDiff != NULL) {
        printf("\nDifference between Integer Set and String Set: ");
        displaySet(*intStringDiff);
        deinitSet(intStringDiff);
    } else {
        printf("Error getting diffSet result.\n");
    }

    deinitSet(&intSet); // Deinitialize integer set
    deinitSet(&stringSet); // Deinitialize string set
    deinitSet(&stringSet2); // Deinitialize string set 2
    deinitSet(&intSet2); // Deinitialize integer set 2
}