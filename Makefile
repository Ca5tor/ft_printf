SRCS		= ft_printf.c fun_output.c utils_0.c utils_1.c
	
OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

COMPILE		= $(CC) $(CFLAGS)

LIB			= ar rc $(NAME)

RM			= rm -f

RLIB		= ranlib

.PHONY:		all clean fclean re

all:		$(SRCS) $(NAME)

%.o:	%.c ft_printf.h
	$(COMPILE) -c $< -o $@

$(NAME):	$(OBJS)
	$(LIB) $(OBJS)
	$(RLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all