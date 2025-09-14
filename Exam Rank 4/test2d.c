#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Helper function to trim leading and trailing whitespace
void trim_whitespace(char* str) {
    if (!str) return;

    // Find first non-whitespace
    char* start = str;
    while (isspace((unsigned char)*start)) start++;

    // If the string is all spaces
    if (*start == '\0') {
        *str = '\0';
        return;
    }

    // Find end of trimmed string
    char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Shift trimmed content to beginning
    if (start != str)
        memmove(str, start, strlen(start) + 1);
}

// Main cleanup function
void clean_up(char*** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char* str = array[i][j];
			printf("Just started.....\n");
//			printf("Before trim: [%s]\n", str ? str : "NULL");
            if (str) {
                trim_whitespace(str);
                if (strlen(str) == 0) {
                    free(array[i][j]);  // optional: free memory if dynamically allocated
                    array[i][j] = NULL;
                }
            }
        }
    }
}

int main() {
    char* data[2][3] = {
        {strdup("  hello "), strdup(" world"), NULL},
        {strdup("   "), strdup("C Lang "), strdup(" ")}
    };

    clean_up((char***)data, 2, 3);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (data[i][j])
                printf("[%s] ", data[i][j]);
            else
                printf("[NULL] ");
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            free(data[i][j]);

    return 0;
}