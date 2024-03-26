
NAME = push_swap
CHECKER = checker

SRCSPATH = ./src/
PRINTFPATH = ./ft_printf/
INCPATH = ./includes/ ./ft_printf/includes/

SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
PRINTF = $(PRINTFPATH)libftprintf.a

CC = cc
DEBUG = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror $(foreach H,$(INCPATH),-I$(H)) #$(DEBUG)

all : $(NAME)

$(NAME) : $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $@

$(PRINTF) :
	make -C $(PRINTFPATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

check : $(CHECKER)

$(CHECKER) : $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -D __CHECK__ $(OBJS) $(PRINTF) -o $@

clean :
	make -C $(PRINTFPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTFPATH) fclean
	rm -f $(NAME) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re

