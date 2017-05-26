#include "input.h"
#include "calc.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_line(char *p)
{
    if (fgets(p, MAX_SIZE, stdin) == NULL){
        p[0] = '\0';
        return;
    }
    remove_space(p);
    replace_minus(p);
}

int is_exit(const char* p)
{
    const char* exit_words[] = {
        "",
        "exit",
        "quit",
        "bye",
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

void replace_minus(char* p)
{
    int i, j;
    char *tmp = (char*)calloc(65536, sizeof(char));

    i = j = 0;
    while (p[i] != '\0'){
        if (p[i] == '-' && (p == 0 || (isdigit(p[i - 1]) == 0 && p[i - 1] != ')'))){
            sprintf(tmp + j, "(0-%g)", -atof(p + i));
            while (tmp[j] != ')'){
                ++j;
            }
            ++j;

            ++i;
            while (isdigit(p[i]) == 1){
                ++i;
            }
        }
        else {
            tmp[j] = p[i];
            ++i;
            ++j;
        }
    }
    tmp[j] = '\0';

    strcpy(p, tmp);
    free(tmp);
}
