#include "solve_square_eq.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

//-----------------------------------------------------------------------------

//Main function of module: input a, b, c of square eq, *x1 , *x2 - possible solutions; nothing returned
void Square_Eq_Solutions(double coef_a, double coef_b, double coef_c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);
    
    int num_roots = Num_Square_Eq_Roots(coef_a, coef_b, coef_c);    // num_roots -- Number of square eq solutions cases.
    switch (num_roots)                                              // May accept 5 int numbers:
    {                                                               //   TWO: case with 2 real solutions
        case N_Sq_Roots::TWO:                                       //   ONE_LINEAR: case of equation, where a = 0 -> linear eqution b*x + c = 0
        {                                                           //   ONE_SQUARE: case with discriminant = 0
            Solve_Two_Roots_Case(coef_a, coef_b, coef_c, x1, x2);   //   NO: No real roots
            printf("x1 = %lg, x2 = %lg", *x1, *x2);                 //   INF: infinite value of roots

            break;
        }
        case N_Sq_Roots::ONE_LINEAR:
        {
            *x1 = Solve_Line_Eq(coef_b, coef_c);
            printf("x = %lg", *x1);

            break;
        }
        case N_Sq_Roots::ONE_SQUARE:
        {
            *x1 = -coef_b / (2 * coef_a);
            if(isfinite(*x1))
                printf("x = %lg", *x1);
            else
                printf("Warning: value of x1 is not finite. x1 = NAN");
            break;
        }
        case N_Sq_Roots::NO:
        {
            printf("No solutions");
            break;
        }
        case N_Sq_Roots::INF:
        {
            printf("Infinite number of solutions");
            break;
        }
        default:
            printf("Error num_roots:%d", num_roots);
    }
}


// Solving case TWO: input a, b, c of square eq, *x1 , *x2 - possible solutions; nothing returned
void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c, double* x1, double* x2)
{
    double discriminant = Solve_Discr(coef_a, coef_b, coef_c);      // func

    *x1 = (-coef_b + sqrt(discriminant)) / (2 * coef_a);
    *x2 = (-coef_b - sqrt(discriminant)) / (2 * coef_a);
    if(!(isfinite(*x1) && isfinite(*x2)))
        printf("Warning: value of x1 and x2 is not finite. x1 = NAN, x2 = NAN");
}


// Solving number of roots: input a, b, c of square eq; str 15 - returned number of roots 
N_Sq_Roots Num_Square_Eq_Roots(double coef_a, double coef_b, double coef_c)
{
    if (Comparing_Doubles(coef_a, ZERO) == 0)
    {
        if (Comparing_Doubles(coef_b, ZERO) == 0)
        {
            if (Comparing_Doubles(coef_c, ZERO) == 0)
            {
                return N_Sq_Roots::INF;
            }
            else
            {
                return N_Sq_Roots::NO;
            }
        }
        else
        {
            return N_Sq_Roots::ONE_LINEAR;
        }
    }
    else
    {
        double discriminant = Solve_Discr(coef_a, coef_b, coef_c);

        if (Comparing_Doubles(discriminant, ZERO) == Compare_Res::LESS)
        {
            return N_Sq_Roots::NO;
        }
        else
        {
            if(Comparing_Doubles(discriminant, ZERO) == Compare_Res::EQUALS)
            {
                return N_Sq_Roots::ONE_SQUARE;
            }
            else
            {
                return N_Sq_Roots::TWO;
            }
        }
    }
}

//-----------------------------------------------------------------------------

// Cmparing 2 numbers type of double with a given precision: input Number1, Number 2; return MORE, EQUALS, LESS
Compare_Res Comparing_Doubles(double num1, double num2)
{
    if (num1 - num2 > BORDER_NUMBER)
    {
        return Compare_Res::MORE;
    }
    else
    {
        if (num1 - num2 < -BORDER_NUMBER)
        {
            return Compare_Res::LESS;
        }
        else
        {
            return Compare_Res::EQUALS;
        }
    }
}

//-----------------------------------------------------------------------------

//Solving case ONE_LINEAR: input coef_a, coef_b; return -coef_b / coef_a if it is finite, if not return 0
double Solve_Line_Eq(double coef_a, double coef_b)
{
    if(isfinite(coef_b / coef_a))
        return -coef_b / coef_a;
    else
    {
        printf("Error:returning value of functioin solve_square_eq.h/Solve_Line_Eq() is not finite. Returned 0\n");
        return 0;
    }
}

//-----------------------------------------------------------------------------

double Solve_Discr(double coef_a, double coef_b, double coef_c)
{
    return coef_b * coef_b - 4 * coef_a * coef_c;
}
