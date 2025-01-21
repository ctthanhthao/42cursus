# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
LIB_DIR = lib
INCLUDE_DIR = include

# Source files
SERVER_SRC = server.c
CLIENT_SRC = client.c
LIB_SRC    = $(LIB_DIR)/ft_atoi.c \
             $(LIB_DIR)/ft_putendl_fd.c \
             $(LIB_DIR)/ft_putnbr_fd.c \
			 $(LIB_DIR)/ft_putstr_fd.c \
             $(LIB_DIR)/ft_strlen.c
		

# Object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)

# Executables
SERVER_EXEC = server
CLIENT_EXEC = client

# Default target
all: $(SERVER_EXEC) $(CLIENT_EXEC)

# Build server executable
$(SERVER_EXEC): $(SERVER_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Build client executable
$(CLIENT_EXEC): $(CLIENT_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile server object
$(SERVER_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile client object
$(CLIENT_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile library objects
$(LIB_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(LIB_OBJ)

# Remove all generated files
fclean: clean
	rm -f $(SERVER_EXEC) $(CLIENT_EXEC)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re