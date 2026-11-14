#include "ascii_stats.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static constexpr size_t INPUT_BUFFER_SIZE = 64;

[[nodiscard]] static bool ask_continue() {
    char buffer[INPUT_BUFFER_SIZE];

    while (true) {
        printf("\nLoop again? (Y/n): ");

        if (fgets(buffer, sizeof(buffer), stdin) == nullptr) {
            return false;
        }

        if (strchr(buffer, '\n') == nullptr) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        }

        char *start = buffer;

        while (isspace((unsigned char)*start)) {
            start++;
        }

        char *end = start + strlen(start);

        while (end > start && isspace((unsigned char)end[-1])) {
            end--;
        }

        *end = '\0';

        for (size_t i = 0; start[i] != '\0'; i++) {
            start[i] = (char)toupper((unsigned char)start[i]);
        }

        if (strcmp(start, "Y") == 0 ||
            strcmp(start, "YES") == 0 ||
            start[0] == '\0') {
            return true;
            }

        if (strcmp(start, "N") == 0 ||
            strcmp(start, "NO") == 0) {
            return false;
            }
        printf("[Error] Invalid input. Expected 'Y' or 'n'.\n");
    }
}

int main() {
    printf("=============================\n");
    printf("     ASCII TEXT ANALYZER     \n");
    printf("=============================\n");
    printf("\nREMEMBER: Only standard ASCII characters (0-127) are supported.\n");
    printf("Extended characters, non ASCII symbols, or accents will be ignored\n");

    do {
        printf("\nTo indicate the end of the entered text, press CTRL + D\n");
        printf("\nEnter text to analyze: ");
        printf("\n");
        // Input logic

    } while (ask_continue());

    printf("\nClosing program...\n");
    return 0;
}
