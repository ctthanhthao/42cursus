#include "get_next_line.h"
// #include <stdio.h>    // For printf()
// #include "src/get_next_line.c"
// #include <fcntl.h>    // For open()
// #include <unistd.h>   // For read() and close()
// #include <stdlib.h>   // For malloc() and free()
// #include "src/get_next_line_utils.c"

int main(int argc, char **argv) {

	char *filename;
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
	filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while (1) {
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
        	free(line);
		}
		else
			break;
    }
	printf("\n");
    close(fd);
	int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("test1.txt", O_RDONLY);

    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);

    printf("File1: %s", line1);
    printf("File2: %s", line2);

	free(line1);
    free(line2);
	line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);

	printf("2_File1: %s", line1);
    printf("2_File2: %s", line2);
	free(line1);
    free(line2);
    close(fd1);
    close(fd2);

	fd1 = open("test.txt", O_RDONLY);

    line1 = get_next_line(fd1);
    printf("3_File1: %s", line1);
	free(line1);
    close(fd1);
    return 0;
}