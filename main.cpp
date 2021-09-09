#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//-----------------------------------------------------------------------------

#define ZERO 0

enum CompareRes
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

int Num_Of_Roots(double coef_a, double coef_b, double coef_c);


void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c);


void Solution(double coef_a, double coef_b, double coef_c);


int Comparing_Doubles(double double_arg1, double double_arg2);


double Solve_Line_Eq(double double_1, double double_2);


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
            printf("x = %lg", Solve_Line_Eq(coef_b, coef_c));

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
    int compare = Comparing_Doubles(discriminant, ZERO);

    switch(compare)
    {
        case CompareRes(MORE):
        {
            double x1 = (-coef_b + sqrt(discriminant))/(2*coef_a);
            double x2 = (-coef_b - sqrt(discriminant))/(2*coef_a);

            printf("x1 = %lg, x2 = %lg",x1 ,x2);
            break;
        }
        case CompareRes(EQUALS):
        {
            double x = -coef_b/(2*coef_a);

            printf("x = %lg", x);
            break;
        }
        case CompareRes(LESS):
        {
            printf("No solutions");
            break;
        }
        default: printf("DEFAULT");
    }
}

//-----------------------------------------------------------------------------

int Num_Of_Roots(double coef_a, double coef_b, double coef_c)
{
    if (Comparing_Doubles(coef_a, ZERO) == 0)
    {
        if (Comparing_Doubles(coef_b, ZERO) == 0)
        {
            if (Comparing_Doubles(coef_c, ZERO) == 0)
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

int Comparing_Doubles(double double_arg1, double double_arg2)
{
    const double border_number= 1e-5;
    if (double_arg1 - double_arg2 > border_number)
    {
        return CompareRes(MORE);
    }
    else
    {
        if (double_arg1 - double_arg2 < -border_number)
        {
            return CompareRes(LESS);
        }
        else
        {
            return CompareRes(EQUALS);
        }
    }
}

//-----------------------------------------------------------------------------

double Solve_Line_Eq(double double_1, double double_2)
{
    return -double_2 / double_1;
}
