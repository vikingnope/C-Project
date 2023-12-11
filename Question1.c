#include <stdio.h>
#include <ctype.h>

void menu(int *a, int *b, int *c, int *d, int *e, int *f, int *x0, int *iterations);
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *x0, int *iterations);
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *x0, int *iterations);

int main() {
    int a, b, c, d, e, f;
    int x0, iterations;

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

    printf("Enter the starting value of x: ");
    scanf("%d", &x0);

    printf("\n");

    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    printf("\n");

    menu(&a, &b, &c, &d, &e, &f, &x0, &iterations);

    return 0;
}

void menu(int *a, int *b, int *c, int *d, int *e, int *f, int *x0, int *iterations){
    int choice;

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

void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *x0, int *iterations){

    printf("Secant Method\n");


    menu(a, b, c, d, e, f, x0, iterations);
}

void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *x0, int *iterations){

    printf("Newton-Raphson Method\n");

    menu(a, b, c, d, e, f, x0, iterations);
}
