#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//-----------------------------------------------------------------------------

enum CompWithZeroResults
{
    LESS = -1,
    EQUALS,
    MORE
};

enum NumOfRoots
{
    INF = -1,
    NO,
    ONE,
    TWO
};

//-----------------------------------------------------------------------------

NumOfRoots Num_Of_Roots(double coef_a, double coef_b, double coef_c);


void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c);


void Solution(double coef_a, double coef_b, double coef_c);


CompWithZeroResults Comp_With_Zero(double double_arg);


void Solve_Line_Eq(double coef_a, double coef_b);


int main()
{

    setlocale(LC_ALL, "Rus");

    double coef_a  = 0;
    double coef_b  = 0;
    double coef_c  = 0;

    printf("Введите аргументы a, b, c через пробел\n");
    scanf("%lg %lg %lg", &coef_a, &coef_b, &coef_c);
    printf("a = %lg, b = %lg, c = %lg\n", coef_a, coef_b, coef_c);

    Solution(coef_a, coef_b, coef_c);

    return 0;
}

//-----------------------------------------------------------------------------

void Solution(double coef_a, double coef_b, double coef_c)
{
    int num_roots = Num_Of_Roots(coef_a, coef_b, coef_c);

    switch (num_roots)
    {
        case NumOfRoots(TWO):
        {
            Solve_Two_Roots_Case(coef_a, coef_b, coef_c);

            break;
        }
        case NumOfRoots(ONE):
        {
            Solve_Line_Eq(coef_b, coef_c);

            break;
        }
        case NumOfRoots(NO):
        {
            printf("No solutions");

            break;
        }
        case NumOfRoots(INF):
        {
            printf("Any number");

            break;
        }
        default: printf("DEFAULT");
    }
}

//-----------------------------------------------------------------------------

void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c)
{
    double discriminant = (coef_b*coef_b) - (4*coef_a*coef_c);
    int compare = Comp_With_Zero(discriminant);

    switch(compare)
    {
        case CompWithZeroResults(MORE):
        {
            double x1 = (-coef_b + sqrt(discriminant))/(2*coef_a);
            double x2 = (-coef_b - sqrt(discriminant))/(2*coef_a);

            printf("x1 = %lg, x2 = %lg",x1 ,x2);
            break;
        }
        case CompWithZeroResults(EQUALS):
        {
            double x = -coef_b/(2*coef_a);

            printf("x = %lg", x);
            break;
        }
        case CompWithZeroResults(LESS):
        {
            printf("No solutions");
            break;
        }
        default: printf("DEFAULT");
    }
}
/*    if (Comp_With_Zero(discriminant))
    {
        double x1 = (-coef_b + sqrt(discriminant))/(2*coef_a);
        double x2 = (-coef_b - sqrt(discriminant))/(2*coef_a);
        printf("x1 = %lg, x2 = %lg",x1 ,x2);
    }
    else
    {
        if (Comp_With_Zero(discriminant))
        {
            double x = -coef_b/(2*coef_a);
            printf("x = %lg", x);
        }
        else
        {
            printf("No solution");
        }
    } */

//-----------------------------------------------------------------------------

NumOfRoots Num_Of_Roots(double coef_a, double coef_b, double coef_c)
{
    if (Comp_With_Zero(coef_a) == 0)
    {
        if (Comp_With_Zero(coef_b) == 0)
        {
            if (Comp_With_Zero(coef_c) == 0)
            {
                return NumOfRoots(INF);
            }
            else
            {
                return NumOfRoots(NO);
            }
        }
        else
        {
            return NumOfRoots(ONE);
        }
    }
    else
    {
        return NumOfRoots(TWO);
    }
}

//-----------------------------------------------------------------------------

CompWithZeroResults Comp_With_Zero(double double_arg)
{
    const double border_num = 10e-5;
    if (double_arg > border_num)
    {
        return CompWithZeroResults(MORE);
    }
    else
    {
        if (double_arg < -border_num)
        {
            return CompWithZeroResults(LESS);
        }
        else
        {
            return CompWithZeroResults(EQUALS);
        }
    }
}

//-----------------------------------------------------------------------------

void Solve_Line_Eq(double coef_a, double coef_b)
{
    printf("x = %lg", -coef_b/coef_a);
}
