#include <string.h>
#include "../../input.h"

int main(void)
{
    char before[] = "-2+1";
    char after[] = "(0-2)+1";

    replace_minus(before);
    if (strcmp(before, after) == 0){
        return (0);
    }
    else {
        return (-1);
    }
}
