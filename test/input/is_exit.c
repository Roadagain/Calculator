#include "../../input.h"

int main(void)
{
    const char* exit_words[] = {
        "",
        "exit",
        "quit",
        "bye",
    };
    int i;

    for (i = 0; i < 4; ++i){
        if (is_exit(exit_words[i]) != 1){
            return (-1);
        }
    }
    return (0);
}
