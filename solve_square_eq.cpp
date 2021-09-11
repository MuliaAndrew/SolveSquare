#include "solve_square_eq.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// description + installation + launch

// debug + release

// README.md

// for * <assert.h>



//-----------------------------------------------------------------------------


void Square_Eq_Solutions(double coef_a, double coef_b, double coef_c, double* x1, double* x2)
{
    int num_roots = Num_Of_Square_Eq_Roots(coef_a, coef_b, coef_c);
    switch (num_roots)
    {
        case N_Of_Square_Eq_Roots::TWO: // (Num...) TWO
        {
            Solve_Two_Roots_Case(coef_a, coef_b, coef_c, x1, x2);
            printf("x1 = %lg, x2 = %lg", *x1, *x2);

            break;
        }
        case N_Of_Square_Eq_Roots::ONE_LINEAR:
        {
            *x1 = Solve_Line_Eq(coef_b, coef_c);
            printf("x = %lg", *x1);

            break;
        }
        case N_Of_Square_Eq_Roots::ONE_SQUARE:
        {
            *x1 = -coef_b / (2 * coef_a);
            printf("x = %lg", *x1);

            break;
        }
        case N_Of_Square_Eq_Roots::NO:
        {
            printf("No solutions");
            break;
        }
        case N_Of_Square_Eq_Roots::INF:
        {
            printf("Infinite number of solutions");
            break;
        }
        default:
            printf("Error num_roots:%d", num_roots);
    }
}


void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c, double* x1, double* x2)
{
    double discriminant = Solve_D(coef_a, coef_b, coef_c);      // func

    *x1 = (-coef_b + sqrt(discriminant)) / (2 * coef_a);
    *x2 = (-coef_b - sqrt(discriminant)) / (2 * coef_a);
}


N_Of_Square_Eq_Roots Num_Of_Square_Eq_Roots(double coef_a, double coef_b, double coef_c)
{
    if (Comparing_Doubles(coef_a, ZERO) == 0)
    {
        if (Comparing_Doubles(coef_b, ZERO) == 0)
        {
            if (Comparing_Doubles(coef_c, ZERO) == 0)
            {
                return N_Of_Square_Eq_Roots::INF;
            }
            else
            {
                return N_Of_Square_Eq_Roots::NO;
            }
        }
        else
        {
            return N_Of_Square_Eq_Roots::ONE_LINEAR;
        }
    }
    else
    {
        int discriminant = Solve_D(coef_a, coef_b, coef_c);

        if (Comparing_Doubles(discriminant, ZERO) == Compare_Res::LESS)
        {
            return N_Of_Square_Eq_Roots::NO;
        }
        else
        {
            if(Comparing_Doubles(discriminant, ZERO) == Compare_Res::EQUALS)
            {
                return N_Of_Square_Eq_Roots::ONE_SQUARE;
            }
            else
            {
                return N_Of_Square_Eq_Roots::TWO;
            }
        }
    }
}


//-----------------------------------------------------------------------------


Compare_Res Comparing_Doubles(double double_arg1, double double_arg2) // names
{
     // global const

    if (double_arg1 - double_arg2 > BORDER_NUMBER)
    {
        return Compare_Res::MORE;
    }
    else
    {
        if (double_arg1 - double_arg2 < -BORDER_NUMBER)
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


double Solve_Line_Eq(double coef_a, double coef_b) // NAN   -- printf
{
    return -coef_b / coef_a; // /0 + isfinit
}

//-----------------------------------------------------------------------------

double Solve_D(double coef_a, double coef_b, double coef_c)
{
    return coef_b * coef_b - 4 * coef_a * coef_c;
}
