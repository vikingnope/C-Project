#include <stdio.h>
#include <math.h>

void menu(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations);
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations);
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations);
long double differentiation(int *a, int *b, int *c, int *d, int *e, long double *x0);
long double functionWorkOut(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0);

int main() {
    int a, b, c, d, e, f;
    int iterations;
    long double x0;

    setbuf(stdout, 0);

    printf("Enter the polynomial in the format: Ax^5+Bx^4+Cx^3+Dx^2+Ex+F=0\n");

    printf("\n");

    printf("Enter a: ");
    scanf("%d", &a);

    printf("\n");

    printf("Enter b: ");
    scanf("%d", &b);

    printf("\n");

    printf("Enter c: ");
    scanf("%d", &c);

    printf("\n");

    printf("Enter d: ");
    scanf("%d", &d);

    printf("\n");

    printf("Enter e: ");
    scanf("%d", &e);

    printf("\n");

    printf("Enter f: ");
    scanf("%d", &f);

    printf("\n");

    printf("The polynomial is: %dx^5+%dx^4+%dx^3+%dx^2+%dx+%d=0\n", a, b, c, d, e, f);

    printf("\n");

    printf("Enter the starting value of x0: ");
    scanf("%Lf", &x0);

    printf("\n");

    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    printf("\n");

    menu(&a, &b, &c, &d, &e, &f, &x0, iterations);

    return 0;
}

/**
 * The following method is used to display the menu.
 */
void menu(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations){
    int choice;

    printf("1. Secant Method\n");
    printf("2. Newton-Raphson Method\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");

    while (scanf("%d", &choice) != 1){
        printf("\n");
        printf("Please enter a different choice.\n");
        printf("Enter your choice: ");
        while (getchar() != '\n');
    }

    printf("\n");

    switch (choice){
        case 1:
            secantMethod(a, b, c, d, e, f, x0, iterations);
            break;
        case 2:
            newtonRaphsonMethod(a, b, c, d, e, f, x0, iterations);
            break;
        case 3:
            printf("Thank you for using this program.\n");
            break;
        default:
            printf("Invalid choice from menu.\n");
            menu(a, b, c, d, e, f, x0, iterations);
    }
}

/**
 * The following method is used to work out the Secant method of the polynomial.
 */
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations){

    printf("Secant Method\n");

    long double tempX0 = *x0;
    int tempIterations = iterations;

    menu(a, b, c, d, e, f, &tempX0, tempIterations);
}

/**
 * The following method is used to work out the Newton-Raphson method of the polynomial.
 */
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations){

    printf("Newton-Raphson Method\n");

    long double tempX0 = *x0;
    int tempIterations = iterations;
    int tempA = *a;
    int tempB = *b;
    int tempC = *c;
    int tempD = *d;
    int tempE = *e;
    int tempF = *f;

    do {
        long double functionValue = functionWorkOut(a, b, c, d, e, f, x0);
        long double derivative = differentiation(a, b, c, d, e, x0);

        *x0 -= functionValue / derivative;

        *a = tempA;
        *b = tempB;
        *c = tempC;
        *d = tempD;
        *e = tempE;
        *f = tempF;

        iterations--;

    } while (iterations > 0);

    printf("The closest root after %d iterations is: %Lf\n", tempIterations, *x0);

    printf("\n");

    menu(a, b, c, d, e, f, &tempX0, tempIterations);
}

/**
 * The following method is used to work out the differentiation of the polynomial.
 */
long double differentiation(int *a, int *b, int *c, int *d, int *e, long double *x0){

    long double answer = 0;

    answer += *a * 5 * powl(*x0, 4);
    answer += *b * 4 * powl(*x0, 3);
    answer += *c * 3 * powl(*x0, 2);
    answer += *d * 2 * (*x0);
    answer += *e;

    return answer;
}

/**
 * The following method is used to work out the work out the function at a given point.
 */
long double functionWorkOut(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0){

    long double answer = 0;

    answer += *a * powl(*x0, 5);
    answer += *b * powl(*x0, 4);
    answer += *c * powl(*x0, 3);
    answer += *d * powl(*x0, 2);
    answer += *e * (*x0);
    answer += *f;

    return answer;
}
