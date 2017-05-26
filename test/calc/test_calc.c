#include <math.h>
#include "../../calc.h"
#include "../../input.h"

int main(void)
{
    char formula1[64] = "12+3*4";
    double result1 = 24;
    if (1e-10 < fabs(calc(formula1, 0) - result1)){
        return (-1);
    }

    char formula2[64] = "3*-2";
    double result2 = -6;
    replace_minus(formula2);
    if (1e-10 < fabs(calc(formula2, 0) - result2)){
        return (-1);
    }

    return (0);
}
