#include <stdio.h>
#include <string.h>
#include <math.h>

#include "calc.h"
#include "input.h"

int main(void)
{
    while (1){
        char input[65536];
        double ans;

        read_line(input);
        if (is_exit(input) == 1){
            puts("bye!!");
            break;
        }
        ans = calc(input, 0);
        if (floor(ans) == ans){
            printf("%.0f\n", ans);
        }
        else{
            printf("%f\n", calc(input, 0));
        }
    }

    return (0);
}
