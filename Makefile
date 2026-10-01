NAME = passwordManager

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes
SRC = main.c \
	  srcs/utils.c \
	  srcs/termUi.c \
	  srcs/userInputs.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME).exe

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	del /Q $(OBJ) 2>NUL

fclean: clean
	del /Q $(NAME).exe 2>NUL

re: fclean all

.PHONY: all clean fclean re