#include <stdio.h>
#include "setMethodsA.h"
#include <string.h>

int main() {
    GenSet intSet, stringSet;
    initSet(&intSet, 0); // Integer set
    initSet(&stringSet, 1); // String set

    int intElement;
    int choice;
    char stringElement[MAX_STRING_LENGTH];

    printf("Adding elements to the Integer Set:\n");
    printf("Enter integers (press Enter without typing anything to stop): ");

    while (1) {
        char line[MAX_SET_SIZE]; // Adjust the size according to your needs
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


    printf("\nAdding elements to the String Set:\n");
    printf("Enter strings (press 'Enter' to stop): ");
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

    printf("\nInteger Set:\n");
    displaySet(intSet);
    printf("\nString Set:\n");
    displaySet(stringSet);

    do{
        printf("\n\nMenu:");
        printf("\n1. Display integer set");
        printf("\n2. Display string set");
        printf("\n3. Count integer set");
        printf("\n4. Count string set");
        printf("\n5. Check if integer set is empty");
        printf("\n6. Check if string set is empty");
        printf("\n7. Check if integer set is a subset of another integer set");
        printf("\n8. Check if string set is a subset of another string set");
        printf("\n9. Check if integer set is a subset of another string set");
        printf("\n10. Check if string set is a subset of another integer set");
        printf("\n11. Union of integer set and string set");
        printf("\n12. Intersection of integer set and string set");
        printf("\n13. Difference between integer set and string set");
        printf("\n14. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        switch(choice){
            case 1:
                printf("\nInteger Set:\n");
                displaySet(intSet);
                break;
            case 2:
                printf("\nString Set:\n");
                displaySet(stringSet);
                break;
            case 3:
                printf("\nCount of elements in Integer Set: %d", countSet(intSet));
                break;
            case 4:
                printf("\nCount of elements in String Set: %d", countSet(stringSet));
                break;
            case 5:
                printf("\nInteger set is empty: %s", isEmptySet(intSet) ? "Yes" : "No");
                break;
            case 6:
                printf("\nString set is empty: %s", isEmptySet(stringSet) ? "Yes" : "No");
                break;
            case 7:
                printf("\nIs integer set a subset of another integer set: %s", isSubsetSet(intSet, &intElement) ? "Yes" : "No");
                break;
            case 8:
                printf("\nIs string set a subset of another string set: %s", isSubsetSet(stringSet, stringElement) ? "Yes" : "No");
                break;
            case 9:
                printf("\nIs integer set a subset of another string set: %s", isSubsetSet(stringSet, &intElement) ? "Yes" : "No");
                break;
            case 10:
                printf("\nIs string set a subset of another integer set: %s", isSubsetSet(intSet, stringElement) ? "Yes" : "No");
                break;
            case 11:
                printf("\nUnion of Integer Set and String Set: ");
                displaySet(unionSet(intSet, stringSet));
                break;
            case 12:
                printf("\nIntersection of Integer Set and String Set: ");
                displaySet(intersectSet(intSet, stringSet));
                break;
            case 13:
                printf("\nDifference between Integer Set and String Set: ");
                displaySet(diffSet(intSet, stringSet));
                break;
            case 14:
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (choice != 14);

    deinitSet(&intSet);
    deinitSet(&stringSet);

    printf("\nThank you for using this program. Goodbye!\n");

    return 0;
}