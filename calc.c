#include "calc.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int calc(const char* p, int mul_div_flag)
{
    int i;
    int ans;

    ans = atoi(p);
    i = 0;
    while (p[i] != '\0'){
        while (isdigit(p[i])){
            i++;
        }
        switch (p[i]){
            case '+':
                return (ans + calc(p + i + 1, 0));
            case '-':
                return (ans - calc(p + i + 1, 0));
            case '*':
                ans *= calc(p + i + 1, 1);
                if (p[i + 1] == '('){
                    while (p[i] != ')'){
                        i++;
                    }
                }
                else {
                    i++;
                }
                break;
            case '/':
                ans /= calc(p + i + 1, 1);
                if (p[i + 1] == '('){
                    while (p[i] != ')'){
                        i++;
                    }
                }
                else {
                    i++;
                }
                break;
            case '\0':
                return (ans);
            default:
                puts("Error");
                return (0);
        }
    }

    return (ans);
}
