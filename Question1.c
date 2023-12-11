#include <stdio.h>

void menu(int *choice, int *a, int *b, int *c, int *d, int *e, int *f, int *iterations);
void secantMethod(void);
void newtonRaphsonMethod(void);

int main() {
    int choice;
    int a, b, c, d, e, f;
    int iterations;

    printf("Enter a ax^5+bx^4+cx^3+dx^2+ex+f=0\n");
    printf("Enter a:");
    scanf("%d", &a);

    printf("\n");

    printf("Enter b:");
    scanf("%d", &b);

    printf("\n");

    printf("Enter c:");
    scanf("%d", &c);

    printf("\n");

    printf("Enter d:");
    scanf("%d", &d);

    printf("\n");

    printf("Enter e:");
    scanf("%d", &e);

    printf("\n");

    printf("Enter f:");
    scanf("%d", &f);

    printf("\n");

    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    menu(&choice, &a, &b, &c, &d, &e, &f, &iterations);

    return 0;
}

void menu(int *choice, int *a, int *b, int *c, int *d, int *e, int *f, int *iterations){
    printf("1. Secant Method\n");
    printf("2. Newton-Raphson Method.\n");
    printf("3. Quit\n");
    printf("Enter your choice:");
    scanf("%d", choice);

    switch (*choice){
        case 1:
            secantMethod();
            break;
        case 2:
            newtonRaphsonMethod();
            break;
        case 3:
            printf("Thank you for using this program,.\n");
            break;
        default:
            printf("Invalid choice.\n");
            menu(choice, a, b, c, d, e, f, iterations);
    }
}

void secantMethod(){
}

void newtonRaphsonMethod(){

}
