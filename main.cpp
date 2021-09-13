#include <stdio.h>
#include <stdlib.h>
#include "solve_square_eq.h"

//-----------------------------------------------------------------------------

int main()
{
    double coef_a = 0;
    double coef_b = 0;
    double coef_c = 0;

    double x1 = 0;
    double x2 = 0;

    printf("solver square equation a*x^2 + b*x + c = 0\n"
           "enter numbers a, b, c\n");

    for(bool input_check = false; input_check == false;)
    {
        if(scanf("%lg %lg %lg", &coef_a, &coef_b, &coef_c) == 3)
            input_check = true;
        else
            printf("Enter numbers again\n");
        fflush(stdin);
    }

    printf("a = %lg, b = %lg, c = %lg\n", coef_a, coef_b, coef_c); // %lf

    Square_Eq_Solutions(coef_a, coef_b, coef_c, &x1, &x2);

    return 0;
}
