#include <stdio.h>  ///< подключает заголовочный файл stdio.h
//#include <TXLib.h>  ///< подключает заголовочный файл TXLib.h
#include <assert.h>
 ///< подключает заголовочный файл math.h
#include "square.h" ///< подключает заголовочный файл square.h
//#include "square.h"

int main()
{
    double a = 0,  ///< Коэффициент а уравнения
           b = 0,  ///< Коэффициент b уравнения
           c = 0,  ///< Коэффициент c уравнения
           x1 = 0, ///< Корень x1 уравнения
           x2 = 0; ///< Корень x2 уравнения

    input_coef(&a, &b, &c);

    switch (SolveSquareEq(a, b, c, &x1, &x2)) {
        case NO_ROOTS:
            printf("No real roots\n");
            break;
        case ONE_ROOT:
            printf("X = %lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("X1 = %lg\n", x1);
            printf("X2 = %lg\n", x2);
            break;
        case INF_ROOTS:
            printf("Any number is a root\n");
            break;
        default:
            printf("switch failed in main(), value = %d\n",
            SolveSquareEq(a, b, c, &x1, &x2));
            break;
    }

    TestProgram(0, 0, 0, 0, 0, INF_ROOTS);

    printf("%d\n", TestProgram(0, 0, 0, 0, 0, INF_ROOTS));
    printf("%d\n", AllTestForProgram());

    return 0;
}



void input_coef(double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    /**
        \brief Переменная, которая принимает возвращаемо значение функции scanf()
        в функции input_coef()
    */
    int ret_scanf = 0;

    while (ret_scanf < NUM_READ_SCANF) {
        puts("Solve square equation ax^2+bx+c.");
        puts("Enter the coefficients of the equation");

        ret_scanf = scanf("%lg %lg %lg", a, b, c);
        int symbol = getchar();
        while (symbol != '\n') {
            if (symbol > 57 || symbol < 48) {
                ret_scanf = 0;
            }
            symbol = getchar();
        }
    }
}



NUM_OF_ROOTS SolveSquareEq(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a) != 0);
    assert(isfinite(b) != 0);
    assert(isfinite(c) != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (CompareTwoDouble(a, 0) == 1) {
        return SolveLinEq(b, c, x1, x2);
    }

    if (CompareTwoDouble(b, 0) == 1 && c/a < 0) {
        *x1 = sqrt(-c/a);
        *x2 = -sqrt(-c/a);
        return TWO_ROOTS;
    }

    if (CompareTwoDouble(b, 0) == 1 && c/a > 0) {
        return NO_ROOTS;
    }

    if (CompareTwoDouble(b, 0) == 1 && CompareTwoDouble(c, 0) == 1) {
        *x1 = *x2 = 0;
        return ONE_ROOT;
    }

    if (CompareTwoDouble(b, 0) == 0 && CompareTwoDouble(c, 0) == 1) {
        *x1 = 0;
        *x2 = -b/(2*a);
        return TWO_ROOTS;
    }

    double discr = b * b - 4 * a * c; ///< переменная, обозначающая дискриминант уравнения

    if (discr < 0) {
        return NO_ROOTS;
    }

    if (CompareTwoDouble(discr, 0) == 1) {
        *x1 = *x2 = -b / (2 * a);
        return ONE_ROOT;
    }

    *x1 = (-b + sqrt(discr)) / (2 * a);
    *x2 = (-b - sqrt(discr)) / (2 * a);
    return TWO_ROOTS;

}



NUM_OF_ROOTS SolveLinEq(double b, double c, double* x1, double* x2)
{
    assert(isfinite(b) != 0);
    assert(isfinite(c) != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);
    if (CompareTwoDouble(b, 0) == 1) {

        if (CompareTwoDouble(c, 0) == 1) {
            return INF_ROOTS;
        }

        return NO_ROOTS;
    }

    *x1 = *x2 = -c / b;

    return ONE_ROOT;
}






int TestProgram(double coefa, double coefb, double coefc, double correct1,
                double correct2, NUM_OF_ROOTS correct_number)
{
    double x1 = 0, x2 = 0;

    NUM_OF_ROOTS number = SolveSquareEq(coefa, coefb, coefc, &x1, &x2);

    if (!((number == correct_number) && ((CompareTwoDouble(x1, correct1) == 1) || (CompareTwoDouble(x1, correct2) == 1)) &&
        ((CompareTwoDouble(x2, correct2) == 1 || (CompareTwoDouble(x2, correct1) == 1))))) {
        printf("FAILED number = %d, x1 = %lg, x2 = %lg\n", number, x1, x2);
        printf("expected number = %d, x1 = %lg, x2 = %lg\n",
        correct_number, correct1, correct2);

        return 0;
    }

    return 1;
}



int AllTestForProgram(void)
{
    struct coef_and_roots {
        double coefa;
        double coefb;
        double coefc;
        double correct1;
        double correct2;
        NUM_OF_ROOTS correct_number;
    };

    struct coef_and_roots data_for_AllTest[] = {
                {0, 0, 0, 0, 0, INF_ROOTS},
                {1, 1, 1, 0, 0, NO_ROOTS},
                {0, 0, 1, 0, 0, NO_ROOTS},
                {0, 1, 1, -1, -1, ONE_ROOT},
                {1, 2, 1, -1, -1, ONE_ROOT},
                {1, 6, 5, -1, -5, TWO_ROOTS},
                {1, 2, 2, 0, 0, NO_ROOTS},
                {0, 1, 0, 0, 0, ONE_ROOT},
                {0, 5, 6, -1.2, -1.2, ONE_ROOT},
                {1, 0, -4, 2, -2, TWO_ROOTS}
    };

    int oktest = 0;

    size_t num_tests = sizeof(data_for_AllTest)/sizeof(data_for_AllTest[0]);

    for(size_t i = 0; i < num_tests; i++) {
        oktest += TestProgram(data_for_AllTest[i].coefa, data_for_AllTest[i].coefb, data_for_AllTest[i].coefc,
                              data_for_AllTest[i].correct1, data_for_AllTest[i].correct2,
                              data_for_AllTest[i].correct_number);
    }

    return oktest;
}
