#include "calc.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int calc(const char* p)
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
                return (ans + calc(p + i + 1));
            case '-':
                return (ans - calc(p + i + 1));
            case '*':
                ans *= atoi(p + i + 1);
                i++;
                break;
            case '/':
                ans /= atoi(p + i + 1);
                i++;
                break;
            case '\0':
                return (ans);
            default:
                puts("Error");
                return (0);
        }
    }
}
