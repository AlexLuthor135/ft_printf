SRCS			=	ft_printf.c flags.c


OBJS	=	${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a
EXECUTABLE 		= ft_printf

all:	$(NAME) #$(EXECUTABLE)

$(NAME):  $(OBJS)
				ar rcs $@ $^

#$(EXECUTABLE): $(OBJS)
#	$(CC) $(CFLAGS) -o $@ $(SRCS) $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(EXECUTABLE)

re:				fclean all

.PHONY:			all clean fclean re