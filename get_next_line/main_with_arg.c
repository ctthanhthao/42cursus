#include "get_next_line_bonus.h"
 #include <stdio.h>    // For printf()
// #include "src/get_next_line.c"
 #include <fcntl.h>    // For open()
 #include <unistd.h>   // For read() and close()
// #include <stdlib.h>   // For malloc() and free()
// #include "src/get_next_line_utils.c"

int main(int argc, char **argv) {

	int i = 1;
	int fd;
	char *line;
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
	printf("BUFFER SIZE : %i\n", BUFFER_SIZE);
	// Test Case 1: Basic Line-by-Line Reading
    printf("\nTest Case: Reading Line by Line in Files\n");
	while (i < argc)
	{
		printf("Reading %s .....\n", argv[i]);
		fd = open(argv[i], O_RDONLY);
		if (fd < 0) {
			perror("Error opening file");
			return 1;
    	}
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
		printf("Done %s .....\n", argv[i]);
		printf("\n");
		i++;
	}
    return 0;
}