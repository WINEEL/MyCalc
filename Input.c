#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_help() {
    printf("\n---------------- HELP MENU ----------------\n");
    printf("Available Functions:\n");
    printf("  - Basic arithmetic: +, -, *, /, ()\n");
    printf("  - Trigonometric: sin(x), cos(x), tan(x) (x in radians)\n");
    printf("  - Trigonometric: sin_deg(x), cos_deg(x), tan_deg(x) (x in degrees)\n");
    printf("  - Logarithmic: log(x), log10(x)\n");
    printf("  - Factorial: fact(n) (n <= 20)\n");
    printf("  - Power: pow(base, exponent)\n");
    printf("  - Prime check: isprime(n)\n");
    printf("  - nth Prime: nth_prime(n)\n");
    printf("  - Reverse number: reverse(n)\n");
    printf("  - Find factors: factors(n)\n");
    printf("  - To exit: type exit()\n");
    printf("-------------------------------------------\n\n");
}

int main() {
    char s[100];

    while (1) {  // Keep looping until user exits
        printf("\n>>> ");  
        fflush(stdout);  // 💡 Ensure prompt appears before input

        if (fgets(s, sizeof(s), stdin) == NULL)
            return 1;  // Exit if input fails

        // Remove trailing newline
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n')
            s[len - 1] = '\0';

        // Handle exit()
        if (strcmp(s, "exit()") == 0)
            exit(0);

        // Handle help()
        if (strcmp(s, "help()") == 0) {
            show_help();
            continue;  // Restart the loop without writing to win.h
        }

        // If input is empty, set a default expression "0" to prevent errors
        if (s[0] == '\0')
            strcpy(s, "0");

        // Open win.h and overwrite with new function
        FILE *p = fopen("win.h", "w");
        if (p == NULL)
            return 1;  // Exit if file error

        // Ensure return(%s); format is correct
        fprintf(p, "#include<stdio.h>\n#include<math.h>\n#include\"wincalc.h\"\n"
                   "double calc(){ return(%s); }", s);

        fclose(p);
        break;  // Exit the loop to allow Output.c to compile
    }

    return 0;
}