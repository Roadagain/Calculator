#include <stdio.h>
#include <string.h>

int main(void)
{
    while (1){
        char input[65536];

        fgets(input, 65535, stdin);
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0){
            break;
        }
    }

    return (0);
}
