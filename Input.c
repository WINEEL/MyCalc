#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to display static help menu
void show_help() {
    printf("\n---------------- HELP MENU ----------------\n\n");
    printf("Available Functions:\n");
    printf("  - Basic arithmetic: +, -, *, /, ()\n");
    printf("  - Trigonometric (Degrees): sin(x), cos(x), tan(x)\n");
    printf("  - Logarithmic: log(x), log10(x)\n");
    printf("  - Factorial: fact(n) (n <= 20)\n");
    printf("  - Power: pow(base, exponent)\n");
    printf("  - Prime check: isprime(n)\n");
    printf("  - nth Prime: nth_prime(n)\n");
    printf("  - Reverse number: reverse(n)\n");
    printf("  - Find factors: factors(n)\n\n");
    printf("Special Commands:\n");
    printf("  - help_all(): List all functions dynamically\n");
    printf("  - exit(): Exit the calculator\n");
    printf("-------------------------------------------\n\n");
}

// Function to display all functions from wincalc.h
void show_all_functions() {
    printf("\n---------- LIST OF FUNCTIONS IN WINCALC.H ----------\n");

    FILE *file = fopen("wincalc.h", "r");
    if (file == NULL) {
        printf("Error: Could not open wincalc.h\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if ((strstr(line, "long int") || strstr(line, "double") || strstr(line, "int")) &&
            strchr(line, '(') && strchr(line, ')')) {
            printf("%s", line);
        }
    }

    fclose(file);
    printf("----------------------------------------------------\n\n");
}

int main() {
    char s[100];

    while (1) {
        printf("\n>>> ");
        fflush(stdout);

        if (fgets(s, sizeof(s), stdin) == NULL)
            return 1;

        // Remove newline and trailing spaces
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
        while (len > 0 && isspace(s[len - 1])) s[--len] = '\0';

        // Handle exit
        if (strcmp(s, "exit()") == 0 || strcmp(s, "exit") == 0) {
            FILE *p = fopen("win.h", "w");
            if (p == NULL) {
                perror("Error opening win.h");
                return 1;
            }
            fprintf(p, "#include<stdio.h>\n#include<math.h>\n#include\"wincalc.h\"\n"
                       "double calc(){ return -99999; }");
            fclose(p);

            FILE *m = fopen("exit_marker.txt", "w");
            if (m) fclose(m);

            break;
        }

        // Handle help
        if (strcmp(s, "help()") == 0 || strcmp(s, "help") == 0) {
            show_help();
            continue;
        }

        // Handle help_all
        if (strcmp(s, "help_all()") == 0 || strcmp(s, "help_all") == 0) {
            show_all_functions();
            continue;
        }

        if (s[0] == '\0') strcpy(s, "0");

        FILE *p = fopen("win.h", "w");
        if (p == NULL) {
            perror("Error opening win.h");
            return 1;
        }

        fprintf(p, "#include<stdio.h>\n#include<math.h>\n#include\"wincalc.h\"\n"
                   "double calc(){ return(%s); }", s);
        fclose(p);
        break;
    }

    return 0;
}
