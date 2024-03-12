NAME = libft.a
SHARED = libft.so
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
EXEC = a.out

GITCLONE = git clone
TRIPOULLE = git@github.com:Tripouille/libftTester.git
WARMACHINE = git@github.com:0x050f/libft-war-machine.git
UNIT-TEST = git@github.com:alelievr/libft-unit-test.git

MANDATORY		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_putstr_fd.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  \
				ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strlen.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c

BONUS			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(MANDATORY:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

.PHONY :  all clean fclean re so bonus get_testers delete_testers update_testers

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : $(MANDATORY)
	$(CC) $(CFLAGS) $(MANDATORY)

bonus : $(NAME) $(BONUS_OBJS)

	ar -rcs $(NAME) $(BONUS_OBJS)

get_testers :
	$(GITCLONE) $(TRIPOULLE) tripoulle_test
	$(GITCLONE) $(WARMACHINE) war-machine
	$(GITCLONE) $(UNIT-TEST) ../unit-test

delete_testers :
	rm -rf ./tripoulle_test ./war-machine ../unit-test

update_testers : delete_testers get_testers

$(BONUS_OBJS) : $(BONUS)
	$(CC) $(CFLAGS) $(BONUS)

so : $(SHARED)

$(SHARED) : $(OBJS) $(BONUS_OBJS)

	$(CC) -fPIC $(CFLAGS) $(MANDATORY)
	gcc -shared -o $(SHARED) $(OBJS) $(BONUS_OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(SHARED) $(EXEC) ./main/*.so

re : fclean all
