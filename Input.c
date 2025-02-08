#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];

    while (1) {
        printf("\n>>> ");
        fflush(stdout);  // Ensure prompt appears before input

        if (fgets(s, sizeof(s), stdin) == NULL)
            return 1;  // Exit if input fails

        // Remove trailing newline
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n')
            s[len - 1] = '\0';

        // Handle exit()
        if (strcmp(s, "exit()") == 0) {
            // Create a marker file for the batch script to detect
            FILE *marker = fopen("exit_marker.txt", "w");
            if (marker) fclose(marker);
            exit(0);  // Exit the program
        }

        // If input is empty, set a default expression "0"
        if (s[0] == '\0')
            strcpy(s, "0");

        // Open win.h and overwrite with new function
        FILE *p = fopen("win.h", "w");
        if (p == NULL)
            return 1;  // Exit if file error

        // Write the input as a valid return expression
        fprintf(p, "#include<stdio.h>\n#include<math.h>\n#include\"wincalc.h\"\n"
                   "double calc(){ return(%s); }", s);

        fclose(p);
        break;  // Exit the loop to allow Output.c to compile
    }

    return 0;
}