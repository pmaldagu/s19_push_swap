SRC = main.c \
	  debug.c \
	  operation.c \
	  parser.c \
	  arg.c \
	  utils.c \
	  prepare.c \
	  sort.c 

OBJ = $(SRC:%.c=%.o)

CC = gcc -g

FLG = -Wall -Wextra -Werror

RM = rm -rf

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLG) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all
