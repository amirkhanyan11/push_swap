
NAME = push_swap

SRCSPATH = ./src/
LIBFTPATH = ./libft/
INCPATH = ./includes/ ./libft/

SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBFT = $(LIBFTPATH)libft.a
MAIN = ./main/main.c


CC = cc
DEBUG = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror $(foreach H,$(INCPATH),-I$(H)) # $(DEBUG)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(MAIN) $(LIBFT) $(OBJS) -o $@

$(LIBFT) :
	make -C $(LIBFTPATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
