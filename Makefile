NAME = ft_printf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	ar rcsT $@ $^ $(LIB)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C ./libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re