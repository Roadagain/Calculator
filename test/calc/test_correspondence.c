#include "../../calc.h"

int main(void)
{
    if (correspondence("(())") != 3){
        return (-1);
    }

    if (correspondence("(((((") != 5){
        return (-1);
    }

    return (0);
}
