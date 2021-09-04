#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//-----------------------------------------------------------------------------

#define ONE_ROOT       1
#define TWO_ROOTS      2
#define NO_ROOTS       0
#define INF_ROOTS     -1

//-----------------------------------------------------------------------------

int Num_Of_Roots(double coef_a, double coef_b, double coef_c);

//-----------------------------------------------------------------------------

void Solve_Two_Roots_Case(double coef_a, double coef_b, double coef_c);

//-----------------------------------------------------------------------------

void Solution(double coef_a, double coef_b, int coef_c);

//-----------------------------------------------------------------------------

int main()
{

    setlocale(LC_ALL, "Rus");

    double coef_a  = 0;
    double coef_b  = 0;
    double coef_c  = 0;

    printf("Введите аргументы a, b, c через пробел\n");
    scanf("%lg %lg %lg", &coef_a, &coef_b, &coef_c);

    Solution(coef_a, coef_b, coef_c);

    return 0;
}

//-----------------------------------------------------------------------------

void Solution(double coef_a, double coef_b, int coef_c)
{
    int num_roots = Num_Of_Roots(coef_a, coef_b, coef_c);

    switch (num_roots)
    {
        case TWO_ROOTS:
        {
            Solve_Two_Roots_Case(coef_a, coef_b, coef_c);

            break;
        }
        case ONE_ROOT:
        {
            double x = -coef_b/coef_c;

            printf("x = %lg", x);

            break;
        }
        case NO_ROOTS:
        {
            printf("No solutions");

            break;
        }
        case INF_ROOTS:
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

    if (discriminant > 0)
    {
        double x1 = (-coef_b + sqrt(discriminant))/(2*coef_a);
        double x2 = (-coef_b - sqrt(discriminant))/(2*coef_a);

        printf("x1 = %lg, x2 = %lg",x1 ,x2);
    }
    else
    {
        if (discriminant == 0)
        {
            double x = -coef_b/(2*coef_a);

            printf("x = %lg", x);
        }
        else
        {
            printf("No solution");
        }
    }
}

//-----------------------------------------------------------------------------

int Num_Of_Roots(double coef_a, double coef_b, double coef_c)
{
    if (coef_a == 0)
    {
        if (coef_b == 0)
        {
            if (coef_c == 0)
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
        else
        {
            return ONE_ROOT;
        }
    }
    else
    {
        return TWO_ROOTS;
    }
}
/*! TODO
1)  Doxygen -- докуметация
2)  Определение функции от объявления
3)  Параметры функции назвать нормально
5)  str 59, 60 -- переименовать переменные
6)  str 32     -- пробелы
7)  Что будет если 000
8)  str 38, 42 -- очко с пробелами
9)  str 63     -- убрал хуйню, переделывай
10) github     -- код
11) хуйня с double
12) разделение на файлы
*/
