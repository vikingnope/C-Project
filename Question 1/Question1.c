#include <stdio.h>
#include <math.h> // Used for powl and isnan

void menu(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations); // Method declaration
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations); // Method declaration
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations); // Method declaration
long double differentiation(const int *a, const int *b, const int *c, const int *d, const int *e, const long double *x0); // Method declaration
long double functionWorkOut(const int *a, const int *b, const int *c, const int *d, const int *e, const int *f, const long double *x0); // Method declaration

/**
 * The following main method is used to run the program.
 * It asks the user for the inputs which can be used in both Secant and Newton-Raphson methods.
 * Returns 0 if the program is successful.
 */
int main() {
    int a, b, c, d, e, f;
    int iterations;
    long double x0;

    // Clears buffer in cases for when terminal does not output anything
    setbuf(stdout, 0);

    printf("Enter the polynomial in the format: Ax^5+Bx^4+Cx^3+Dx^2+Ex+F=0\n");

    printf("\n");

    printf("Enter a: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &a) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter a: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("Enter b: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &b) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter b: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("Enter c: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &c) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter c: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("Enter d: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &d) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter d: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("Enter e: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &e) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter e: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("Enter f: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &f) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter f: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("The polynomial is: f(x)=%dx^5+%dx^4+%dx^3+%dx^2+%dx+%d\n", a, b, c, d, e, f);

    printf("\n");

    printf("Enter the value of x0: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%Lf", &x0) != 1){
        printf("\n");
        printf("Please enter any double value.\n");
        printf("Enter the value of x0: ");
        while (getchar() != '\n');
    }

    printf("\n");

    printf("Enter number of iterations: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &iterations) != 1){
        printf("\n");
        printf("Please enter an integer.\n");
        printf("Enter number of iterations: ");
        while (getchar() != '\n');
    }

    printf("\n");

    menu(&a, &b, &c, &d, &e, &f, &x0, iterations); // Calls menu and passes the values of a, b, c, d, e, f, x0 and iterations

    return 0;
}

/**
 * The following method is used to display the menu.
 * Does not return anything.
 */
void menu(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations){
    int choice;

    printf("1. Secant Method\n");
    printf("2. Newton-Raphson Method\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%d", &choice) != 1){
        printf("\n");
        printf("Please enter a different choice.\n");
        printf("Enter your choice: ");
        while (getchar() != '\n');
    }

    printf("\n");

    // Switch statement to determine which method to use depending on the user's choice
    switch (choice){
        case 1:
            secantMethod(a, b, c, d, e, f, x0, iterations);
            break;
        case 2:
            newtonRaphsonMethod(a, b, c, d, e, f, x0, iterations);
            break;
        case 3:
            printf("Thank you for using this program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice from menu.\n");
            menu(a, b, c, d, e, f, x0, iterations);
    }
}

/**
 * The following method is used to work out the Secant method of the polynomial.
 * Does not return anything.
 */
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations){

    // If the iterations is less than or equal to 0 then the following if condition will be executed
    if (iterations <= 0) {
        printf("Cannot converge with 0 or negative iterations.\n");
        printf("\n");
        menu(a, b, c, d, e, f, x0, iterations);
        return;
    }

    long double x1;

    printf("Secant Method\n");

    printf("\n");

    printf("Enter the value of x1: ");

    // While loop to check if the user has entered the correct format
    while (scanf("%Lf", &x1) != 1){
        printf("\n");
        printf("Please enter any double value.\n");
        printf("Enter a: ");
        while (getchar() != '\n');
    }

    printf("\n");

    long double doubleReturnX0 = *x0; // Used to store the original value of x0

    long double tempX0 = *x0;
    int tempIterations = iterations; // Used to store the original value of iterations

    do {
        long double functionValueX0 = functionWorkOut(a, b, c, d, e, f, x0); // Work out the function with the value at x0
        long double functionValueX1 = functionWorkOut(a, b, c, d, e, f, &x1); // Work out the function with the value at x1

        *x0 = x1 - (functionValueX1 * (x1 - *x0)) / (functionValueX1 - functionValueX0); // Works out new x0 by getting x1 - (function at x1 * (x1 - x0)) / (function at x1 - function at x0)

        x1 = tempX0; // Set x1 to the value of x0
        tempX0 = *x0; // Set tempX0 to the value of x0

        iterations--; // Decrease iterations by 1

        // If the root is not defined then the following if condition will be executed
        if (isnan(*x0)){
            printf("No root has been found.\n");
            printf("\n");
            menu(a, b, c, d, e, f, x0, iterations);
            return;
        }

    } while (iterations > 0);

    printf("The closest root after %d iterations is: %Lf\n", tempIterations, *x0);
    printf("\n");

    menu(a, b, c, d, e, f, &doubleReturnX0, tempIterations); // Calls menu and passes the original value of x0 and iterations
}

/**
 * The following method is used to work out the Newton-Raphson method of the polynomial.
 * Does not return anything.
 */
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations){

    // If the iterations is less than or equal to 0 then the following if condition will be executed
    if (iterations <= 0) {
        printf("Cannot converge with 0 or negative iterations.\n");
        printf("\n");
        menu(a, b, c, d, e, f, x0, iterations);
        return;
    }

    printf("Newton-Raphson Method\n");

    long double tempX0 = *x0; // Used to store the original value of x0
    int tempIterations = iterations; // Used to store the original value of iterations

    do {
        long double functionValue = functionWorkOut(a, b, c, d, e, f, x0); // Work out the function with the value at x0
        long double derivative = differentiation(a, b, c, d, e, x0); // Work out the derivative with the value at x0

        *x0 -= functionValue / derivative; // Works out new x0 by getting x0 - function at x0 / derivative at x0

        iterations--; // Decrease iterations by 1

        // If the root is not defined then the following if condition will be executed
        if (isnan(*x0)){
            printf("No root has been found.\n");
            printf("\n");
            menu(a, b, c, d, e, f, x0, iterations);
            return;
        }
    } while (iterations > 0);

    printf("The closest root after %d iterations is: %Lf\n", tempIterations, *x0);
    printf("\n");

    menu(a, b, c, d, e, f, &tempX0, tempIterations); // Calls menu and passes the original value of x0 and iterations
}

/**
 * The following method is used to work out the differentiation of the polynomial.
 * Returns a long double value.
 */
long double differentiation(const int *a, const int *b, const int *c, const int *d, const int *e, const long double *x0){

    long double answer = 0;

    answer += *a * 5 * powl(*x0, 4);
    answer += *b * 4 * powl(*x0, 3);
    answer += *c * 3 * powl(*x0, 2);
    answer += *d * 2 * (*x0);
    answer += *e;

    return answer; // Returns the worked out polynomial
}

/**
 * The following method is used to work out the work out the function at a given point.
 * Returns a long double value.
 */
long double functionWorkOut(const int *a, const int *b, const int *c, const int *d, const int *e, const int *f, const long double *x0){

    long double answer = 0;

    answer += *a * powl(*x0, 5);
    answer += *b * powl(*x0, 4);
    answer += *c * powl(*x0, 3);
    answer += *d * powl(*x0, 2);
    answer += *e * (*x0);
    answer += *f;

    return answer; // Returns the worked out polynomial
}