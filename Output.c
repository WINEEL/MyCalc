#include <stdio.h>
#include "win.h"

int main() {
    double result = calc();

    if (result == -99999) {
        // Exit signal; do not print
        return 0;
    }

    printf("%.10G\n", result);
    return 0;
}
