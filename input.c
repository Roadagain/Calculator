#include "input.h"

#include <stdio.h>
#include <string.h>

void read_line(char *p)
{
    fgets(p, MAX_SIZE, stdin);
}
