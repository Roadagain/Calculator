#include "input.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void read_line(char *p)
{
    fgets(p, MAX_SIZE, stdin);
    remove_space(p);
}

void remove_space(char* p)
{
    int i, j;

    i = j = 0;
    while (p[i] != '\0'){
        while (isspace(p[j])){
            j++;
        }
        while (!isspace(p[j])){
            p[i] = p[j];
            if (p[i] == '\0'){
                break;
            }
            else {
                i++;
                j++;
            }
        }
    }
}
