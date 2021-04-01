SRC = main.c \
	  utils.c \
	  arg.c \
	  input.c \
	  operation.c \
	  parser.c \
	  debug.c

OBJ = $(SRC:%.c=%.o)

CC = gcc -g

FLG = -Wall -Wextra -Werror

RM = rm -rf

NAME = checker

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLG) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all
