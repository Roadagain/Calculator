#include "../../calc.h"

int main(void)
{
    const char* operators = "+-*/()";
    int i;

    for (i = 0; operators[i] != '\0'; ++i){
        if (isoperator(operators + i) != 1){
            return (-1);
        }
    }

    const char* alnums = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (i = 0; alnums[i] != '\0'; ++i){
        if (isoperator(alnums + i) == 1){
            return (-1);
        }
    }

    const char* symbols = "^\\@[;:],._ !\"#$%&'=~|`{}<>?";
    for (i = 0; symbols[i] != '\0'; ++i){
        if (isoperator(symbols + i) == 1){
            return (-1);
        }
    }

    return (0);
}
