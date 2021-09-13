#ifndef SOLVE_SQUARE_EQ_H
#define SOLVE_SQUARE_EQ_H

//-----------------------------------------------------------------------------

const double ZERO          = 0;
const double BORDER_NUMBER = 1e-6;

enum Compare_Res
{
    LESS = -1,
    EQUALS,
    MORE
};

enum N_Sq_Roots
{
    INF         = -2,
    NO          = -1,
    ONE_LINEAR,
    ONE_SQUARE,
    TWO
};

//-----------------------------------------------------------------------------

N_Sq_Roots Num_Square_Eq_Roots(double coef_a, double coef_b, double coef_c);


double Solve_D(double coef_a, double coef_b, double coef_c);


void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c, double* x1, double* x2);


void Square_Eq_Solutions(double coef_a, double coef_b, double coef_c, double* x1, double* x2);


Compare_Res Comparing_Doubles(double num1, double num2);


double Solve_Line_Eq(double coef_a, double coef_b);


double Solve_Discr(double coef_a, double coef_b, double coef_c);


#endif // SOLVE_SQUARE_EQ_H
