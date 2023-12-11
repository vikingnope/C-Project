#include <stdio.h>
#include <ctype.h>

void menu(int *a, int *b, int *c, int *d, int *e, int *f, int *iterations);
void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *iterations);
void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *iterations);

int main() {
    int a, b, c, d, e, f;
    int iterations;

    printf("Enter the polynomial in the format: x^5+bx^4+cx^3+dx^2+ex+f=0\n");

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

    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    printf("\n");

    menu(&a, &b, &c, &d, &e, &f, &iterations);

    return 0;
}

void menu(int *a, int *b, int *c, int *d, int *e, int *f, int *iterations){
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
            secantMethod(a, b, c, d, e, f, iterations);
            break;
        case 2:
            newtonRaphsonMethod(a, b, c, d, e, f, iterations);
            break;
        case 3:
            printf("Thank you for using this program.\n");
            break;
        default:
            printf("Invalid choice from menu.\n");
            menu(a, b, c, d, e, f, iterations);
    }
}

void secantMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *iterations){

    printf("Secant Method\n");


    menu(a, b, c, d, e, f, iterations);
}

void newtonRaphsonMethod(int *a, int *b, int *c, int *d, int *e, int *f, int *iterations){

    printf("Newton-Raphson Method\n");

    menu(a, b, c, d, e, f, iterations);
}
