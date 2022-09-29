#include "razdel_comp.h"
int CompareTwoDouble(double number1, double number2)
{
    return (fabs(number1 - number2) < DOUBLE_RANGE);  //!
}

