#include <stdio.h>
#include <string.h>

#include "input.h"

int main(void)
{
    while (1){
        char input[65536];

        read_line(input);
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0){
            break;
        }
    }

    return (0);
}
