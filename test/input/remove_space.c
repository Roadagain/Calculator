#include <string.h>
#include "../input.h"

int main(void)
{
    char before[] = "12 + 3";
    char after[] = "12 + 3";

    remove_space(before);
    if (strcmp(before, after) == 0){
        return (0);
    }
    else {
        return (-1);
    }
}
