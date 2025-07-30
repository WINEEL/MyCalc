#include <stdio.h>
#include "win.h"

int main() {
    double result = calc();

    if (result == -99999) {
        return 0; // exit silently
    }

    // Green output for result
    printf("\033[1;32m%.10G\033[0m\n", result);
    return 0;
}
