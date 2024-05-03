NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

LIBFT_DIR	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a

SOURCES  =  $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -o $(NAME)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.SILENT: all clean fclean re

.PHONY: all clean fclean re