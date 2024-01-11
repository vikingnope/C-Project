#ifndef ASSIGNMENT_QUESTION_2_TESTINGSTRUCTFILEB_H
#define ASSIGNMENT_QUESTION_2_TESTINGSTRUCTFILEB_H

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 64

// Structs for Planes
typedef struct Planes {
    char name[MAX_STRING_LENGTH];
    int capacity;
} Planes;

// Structs for Planets
typedef struct Planets {
    char name[MAX_STRING_LENGTH];
    int circumference;
} Planets;

// Returns the size of Planes
size_t getSizeOfPlanes(){
    return sizeof(Planes);
}

// Returns the size of Planets
size_t getSizeOfPlanets(){
    return sizeof(Planets);
}

// Compares Plane sets
int comparePlanes(void *element1, void *element2){
    Planes *plane1 = (Planes *)element1;
    Planes *plane2 = (Planes *)element2;

    if (plane1->capacity > plane2->capacity){
        return 1;
    } else if (plane1->capacity < plane2->capacity){
        return -1;
    } else {
        return 0;
    }
}

// Compares Planet sets
int comparePlanets(void *element1, void *element2){
    Planets *planet1 = (Planets *)element1;
    Planets *planet2 = (Planets *)element2;

    if (planet1->circumference > planet2->circumference){
        return 1;
    } else if (planet1->circumference < planet2->circumference){
        return -1;
    } else {
        return 0;
    }
}

// Adds Plane sets to the set
int addPlanesToSet(void *element1, void *element2){
    Planes *plane1 = (Planes *)element1;
    Planes *plane2 = (Planes *)element2;

    strcpy(plane1->name, plane2->name);

    plane1->capacity += plane2->capacity;

    return 1;
}

// Adds Planet sets to the set
int addPlanetsToSet(void *element1, void *element2){
    Planets *planet1 = (Planets *)element1;
    Planets *planet2 = (Planets *)element2;

    strcpy(planet1->name, planet2->name);

    planet1->circumference += planet2->circumference;

    return 1;
}

// Displays Plane sets
void displayPlanes(void *element){
    Planes *plane = (Planes *)element;

    printf("Plane name: %s\n", plane->name);
    printf("Plane capacity: %d\n\n", plane->capacity);
}

// Displays Planet sets
void displayPlanets(void *element){
    Planets *planet = (Planets *)element;

    printf("Planet name: %s\n", planet->name);
    printf("Planet circumference: %d\n\n", planet->circumference);
}

// Exports Plane sets
void exportPlanes(void *element, char *filename, int index){
    Planes *plane = (Planes *)element;

    FILE *file = fopen(filename, "a");

    if (file == NULL){
        printf("Unable to open file %s\n", filename);
        return;
    }

    if (index == 0){
        fprintf(file, "Plane Set:\n\n");
    }

    fprintf(file, "%d.\tName: %s\n", index + 1, plane->name);
    fprintf(file, "\tCapacity: %d\n\n", plane->capacity);

    fclose(file);
}

// Exports Planet sets
void exportPlanets(void *element, char *filename, int index){
    Planets *planet = (Planets *)element;

    FILE *file = fopen(filename, "a");

    if (file == NULL){
        printf("Unable to open file %s\n", filename);
        return;
    }

    if (index == 0){
        fprintf(file, "Planet Set:\n\n");
    }

    fprintf(file, "%d.\tName: %s\n", index + 1, planet->name);
    fprintf(file, "\tCircumference: %d\n\n", planet->circumference);

    fclose(file);
}

#endif //ASSIGNMENT_QUESTION_2_TESTINGSTRUCTFILEB_H
