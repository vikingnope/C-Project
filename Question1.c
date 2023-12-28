#include <stdio.h>
#include <math.h>

void menu(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int iterations);
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow, int iterations);
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow, int iterations);
long double differentiation(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow);
long double functionWorkOut(int *a, int *b, int *c, int *d, int *e, int *f, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow, long double *x0);

int main() {
    int a, b, c, d, e, f;
    int iterations;
    long double x0;

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

    int aPow = 5;
    int bPow = 4;
    int cPow = 3;
    int dPow = 2;
    int ePow = 1;
    int fPow = 0;

    printf("1. Secant Method\n");
    printf("2. Newton-Raphson Method.\n");
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
            secantMethod(a, b, c, d, e, f, x0, &aPow, &bPow, &cPow, &dPow, &ePow, &fPow, iterations);
            break;
        case 2:
            newtonRaphsonMethod(a, b, c, d, e, f, x0, &aPow, &bPow, &cPow, &dPow, &ePow, &fPow, iterations);
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
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow, int iterations){

    printf("Secant Method\n");

    long double tempX0 = *x0;
    int tempIterations = iterations;

    menu(a, b, c, d, e, f, &tempX0, tempIterations);
}

/**
 * The following method is used to work out the Newton-Raphson method of the polynomial.
 */
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow, int iterations){

    printf("Newton-Raphson Method\n");

    long double tempX0 = *x0;
    int tempIterations = iterations;

    do {
        *x0 -= (functionWorkOut(a, b, c, d, e, f, aPow, bPow, cPow, dPow, ePow, fPow, x0) / differentiation(a, b, c, d, e, f, x0, aPow, bPow, cPow, dPow, ePow, fPow));
        iterations--;

    } while (iterations > 0);

    printf("The closest root is: %Lf\n", *x0);

    printf("\n");

    menu(a, b, c, d, e, f, &tempX0, tempIterations);
}

/**
 * The following method is used to work out the differentiation of the polynomial.
 */
long double differentiation(int *a, int *b, int *c, int *d, int *e, int *f, long double *x0, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow){

    printf("Differentiation\n");

    *aPow = 4;
    *bPow = 3;
    *cPow = 2;
    *dPow = 1;
    *ePow = 0;
    *fPow = -1;

    *f = 0;

    return functionWorkOut(a, b, c, d, e, f, aPow, bPow, cPow, dPow, ePow, fPow, x0);
}

/**
 * The following method is used to work out the work out the function at a given point.
 */
long double functionWorkOut(int *a, int *b, int *c, int *d, int *e, int *f, int *aPow, int *bPow, int *cPow, int *dPow, int *ePow, int *fPow, long double *x0){
    printf("Function Work Out\n");

    long double aWorkOut = 0;
    long double bWorkOut = 0;
    long double cWorkOut = 0;
    long double dWorkOut = 0;
    long double eWorkOut = 0;
    long double fWorkOut = 0;

    if (*aPow >= 0){
        aWorkOut = *a * powl(*x0, *aPow);
    }

    if (*bPow >= 0){
        bWorkOut = *b * powl(*x0, *bPow);
    }

    if (*cPow >= 0){
        cWorkOut = *c * powl(*x0, *cPow);
    }

    if (*dPow >= 0){
        dWorkOut = *d * powl(*x0, *dPow);
    }

    if (*ePow >= 0){
        eWorkOut = *e * powl(*x0, *ePow);
    }

    if (*fPow >= 0){
        fWorkOut = *f * powl(*x0, *fPow);
    }

    printf("The function work out is: %Lf\n", (aWorkOut + bWorkOut + cWorkOut + dWorkOut + eWorkOut + fWorkOut));
    return (aWorkOut + bWorkOut + cWorkOut + dWorkOut + eWorkOut + fWorkOut);
}
