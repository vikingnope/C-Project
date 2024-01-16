#include <stdio.h>
#include <stdlib.h>
#include "setMethodsB.h"
#include "testingStructFileB.h"

int main() {
    // Removes files from previous runs
    remove("planeSet.txt");
    remove("planetSet.txt");

    // Clears buffer in cases where terminal does not output anything
    setbuf(stdout, 0);

    printf("Welcome to the Set Operations Program!\n\n");

    // Creates a set of Planes
    GenSet *planeSet1 = ((GenSet *) malloc(sizeof(GenSet)));

    // Initialises set with the following parameters:
    initSet(planeSet1,1, 20, &getSizeOfPlanes, &comparePlanes, &addPlanesToSet, &displayPlanes, &exportPlanes);

    // Adds the following elements to the set:
    addToSet(planeSet1, &(Planes){"Boeing 747", 416});
    addToSet(planeSet1, &(Planes){"Boeing 777", 300});
    addToSet(planeSet1, &(Planes){"Boeing 747", 416}); // Duplicate element

    // Displays the set
    displaySet(planeSet1);

    // Creates a set of Planets
    GenSet *planetSet1 = ((GenSet *) malloc(sizeof(GenSet)));

    // Initialises set with the following parameters:
    initSet(planetSet1,2, 20, &getSizeOfPlanets, &comparePlanets, &addPlanetsToSet, &displayPlanets, &exportPlanets);

    // Adds the following elements to the set:
    addToSet(planetSet1, &(Planets){"Earth", 40075});
    addToSet(planetSet1, &(Planets){"Jupiter", 439264});

    // Displays the set
    displaySet(planetSet1);

    GenSet *planeSet2 = ((GenSet *) malloc(sizeof(GenSet)));

    // Initialises set with the following parameters:
    initSet(planeSet2,1, 20, &getSizeOfPlanes, &comparePlanes, &addPlanesToSet, &displayPlanes, &exportPlanes);

    // Adds the following elements to the set:
    addToSet(planeSet2, &(Planes){"Boeing 747", 416});

    // Displays the set
    displaySet(planeSet2);

    // Performs union
    GenSet *unionSet1 = unionSet(planeSet1, planetSet1);

    // Displays the union set
    if (unionSet1 != NULL) {
        printf("\nUnion of Plane Set and Planet Set:\n");
        displaySet(unionSet1);
        deinitSet(unionSet1); // Deinitialises the set
    }

    // Performs intersection
    GenSet *intersectSet1 = intersectSet(planeSet1, planeSet2);

    // Displays the intersection set
    if (intersectSet1 != NULL) {
        printf("\nIntersection of Plane Set 1 and Plane Set 2:\n");
        displaySet(intersectSet1);
        deinitSet(intersectSet1); // Deinitialises the set
    }

    // Performs difference
    GenSet *diffSet1 = diffSet(planeSet1, planetSet1);

    // Displays the difference set
    if (diffSet1 != NULL) {
        printf("\nDifference of Plane Set and Planet Set:\n");
        displaySet(diffSet1);
        deinitSet(diffSet1); // Deinitialises the set
    }

    // Counts the number of elements in the plane set
    printf("\nNumber of elements in Plane Set: %d\n", countSet(planeSet1));

    // Counts the number of elements in the planet set
    printf("\nNumber of elements in Planet Set: %d\n", countSet(planetSet1));

    // Checks if the element Earth is a subset of the planet set
    Planets *planet = (Planets *)isSubsetSet(planetSet1, &(Planets){"Earth", 40075});

    // Displays the element if it is a subset
    if (planet != NULL) {
        printf("\nPlanet found in Planet Set:\n");
        displayPlanets(planet);
    }

    // Checks if the plane set is empty
    printf("\nIs Plane Set empty? %s\n", isEmptySet(planeSet1) ? "Yes" : "No");

    // Checks if the planet set is empty
    printf("\nIs Planet Set empty? %s\n", isEmptySet(planetSet1) ? "Yes" : "No");

    // Exports the plane set and planet set to planeSet.txt and planetSet.txt respectively
    printf("\nExporting Plane Set to planeSet.txt and Planet Set to planetSet.txt...\n");

    // Calls the export function
    export(planeSet1, "planeSet.txt");
    export(planetSet1, "planetSet.txt");

    // Deinitialises the sets
    deinitSet(planeSet1);
    deinitSet(planetSet1);

    printf("\nThank you for using this program. Goodbye!\n");

    return 0;
}