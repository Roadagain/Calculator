#include "calc.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

double calc(const char* p, int mul_div_flag)
{
    int i;
    double ans;

    if (p[0] != '(' && mul_div_flag == 1){
        return (atof(p));
    }
    else if (p[0] == '('){
        ans = 0;
    }
    else {
        ans = atof(p);
    }

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
                i += correspondence(p + i + 1) + 1;
                break;
            case '/':
                ans /= calc(p + i + 1, 1);
                i += correspondence(p + i + 1) + 1;
                break;
            case '(':
                ans = calc(p + i + 1, 0);
                i += correspondence(p + i) + 1;
                break;
            case ')':
            case '\0':
                return (ans);
            default:
                puts("Error");
                return (0);
        }
    }

    return (ans);
}

int correspondence(const char *p)
{
    int brackets_count;
    int i;

    if (p[0] != '('){
        return (0);
    }

    brackets_count = 1;
    for (i = 1; p[i] != '\0'; i++){
        if (p[i] == '('){
            brackets_count++;
        }
        else if (p[i] == ')'){
            brackets_count--;
            if (brackets_count == 0){
                return (i);
            }
        }
    }

    return (i);
}
