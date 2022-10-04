#include "square.h" ///< подключает заголовочный файл square.h


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

    printf("Correctly executed %d/1\n", TestProgram(0, 0, 0, 0, 0, INF_ROOTS));
    printf("Correctly executed %d/10\n", AllTestForProgram());

    return 0;
}




