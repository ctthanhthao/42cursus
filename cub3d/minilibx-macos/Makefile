
MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
FRAMEWORKS = -framework Cocoa -framework Metal -framework QuartzCore
#OPTI=-Ounchecked

all: $(NAME)

$(NAME):
	swiftc $(INC) -emit-library $(SRC) $(C_SRC) -o $(NAME) -lz $(FRAMEWORKS)

clean:
	rm -f $(NAME) *.o *.swiftmodule *.swiftdoc *~

