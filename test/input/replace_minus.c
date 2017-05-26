#include <string.h>
#include "../../input.h"

int main(void)
{
    // a case removable
    char before1[64] = "-2+1";
    char after1[64] = "(0-2)+1";
    puts(before1);
    replace_minus(before1);
    puts(before1);
    if (strcmp(before1, after1) != 0){
        return (-1);
    }

    // a case not removable
    char before2[64] = "3-2";
    char after2[64] = "3-2";
    puts(before2);
    replace_minus(before2);
    puts(before2);
    if (strcmp(before2, after2) != 0){
        return (-1);
    }

    return (0);
}
