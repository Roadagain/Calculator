#include "input.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void read_line(char *p)
{
    if (fgets(p, MAX_SIZE, stdin) == NULL){
        p[0] = '\0';
        return;
    }
    remove_space(p);
}

int is_exit(const char* p)
{
    const char* exit_words[] = {
        "exit",
        "quit",
    };
    int len = (int)(sizeof(exit_words) / sizeof(char*));
    int i;

    if (strlen(p) == 0){
        return (1);
    }
    for (i = 0; i < len; i++){
        if (strcmp(p, exit_words[i]) == 0){
            return (1);
        }
    }
    return (0);
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
