#include <fcntl.h>   // For open()
#include <unistd.h>  // For close()
#include <stdio.h>   // For printf()
#include <stdlib.h>  // For NULL
#include "get_next_line_bonus.h"

// Function to test and print each line output
void print_lines_from_file(int fd) {
    char *line;
    int line_num = 1;

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s", line_num++, line);
        free(line);
    }
    printf("End of file reached or NULL returned\n");
}

int main() {
    int fd;

    // Test Case 1: Basic Line-by-Line Reading
    printf("\nTest Case 1: Basic Line-by-Line Reading\n");
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test1.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 2: File Without Newline at End
    printf("\nTest Case 2: File Without Newline at End\n");
    fd = open("test2.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test2.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 3: Empty File
    printf("\nTest Case 3: Empty File\n");
    fd = open("test3.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test3.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 4: Single Character Line
    printf("\nTest Case 4: Single Character Line\n");
    fd = open("test4.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test4.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 5: Lines Longer Than BUFFER_SIZE
    printf("\nTest Case 5: Lines Longer Than BUFFER_SIZE\n");
    fd = open("test5.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test5.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 6: File Descriptor Boundaries and Multiple FDs
    printf("\nTest Case 6: File Descriptor Boundaries and Multiple FDs\n");
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test5.txt", O_RDONLY);
    if (fd1 == -1 || fd2 == -1) {
        perror("Error opening test6a.txt or test6b.txt");
        if (fd1 != -1) close(fd1);
        if (fd2 != -1) close(fd2);
        return 1;
    }
    printf("Reading from test1.txt:\n");
    print_lines_from_file(fd1);
    printf("Reading from test5.txt:\n");
    print_lines_from_file(fd2);
    close(fd1);
    close(fd2);

    // Test Case 7: Continuous Calls Until EOF
    printf("\nTest Case 7: Continuous Calls Until EOF\n");
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test1.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 8: Large File (if available)
    
    printf("\nTest Case 8: Large File\n");
    fd = open("large_test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening large_test.txt");
        return 1;
    }
    print_lines_from_file(fd);
    close(fd);

    // Test Case 9: Invalid FD
    printf("\nTest Case 9: Invalid FD\n");
    char *line = get_next_line(-1);
    if (line == NULL) {
        printf("Passed invalid FD test (returned NULL as expected)\n");
    } else {
        printf("Unexpected output: %s\n", line);
        free(line);
    }

    // Test Case 11: Multiple Files Read in an Interleaved Manner
    printf("\nTest Case 11: Multiple Files Read in Interleaved Manner\n");
	char *file1 = "test1.txt";
	char *file2 = "test5.txt";
	char *file3 = "large_test.txt";
    int fd_a = open(file1, O_RDONLY);
    int fd_b = open(file2, O_RDONLY);
    int fd_c = open(file3, O_RDONLY);

    if (fd_a == -1 || fd_b == -1 || fd_c == -1) {
        perror("Error opening one or more of test11a.txt, test11b.txt, or test11c.txt");
        if (fd_a != -1) close(fd_a);
        if (fd_b != -1) close(fd_b);
        if (fd_c != -1) close(fd_c);
        return 1;
    }

    // Read one line at a time from each file in an interleaved manner
    char *line_a = get_next_line(fd_a);
    char *line_b = get_next_line(fd_b);
    char *line_c = get_next_line(fd_c);

    int line_number = 1;
    while (line_a || line_b || line_c) {
        if (line_a) {
            printf("File %s, Line %d: %s", file1, line_number, line_a);
            free(line_a);
            line_a = get_next_line(fd_a);
        }
        if (line_b) {
            printf("File %s, Line %d: %s", file2, line_number, line_b);
            free(line_b);
            line_b = get_next_line(fd_b);
        }
        if (line_c) {
            printf("File %s, Line %d: %s", file3, line_number, line_c);
            free(line_c);
            line_c = get_next_line(fd_c);
        }
        line_number++;
    }

    close(fd_a);
    close(fd_b);
    close(fd_c);

    return 0;
}