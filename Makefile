# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:09:53 by emehdaou          #+#    #+#              #
#    Updated: 2023/11/15 23:09:08 by emehdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS 		=	ft_printf.c \
ft_printf_utils.c \

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	-I ./

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
			
.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o ${<:.c=.o}
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			@rm -f $(OBJS)
			@rm -f $(OBJS_BONUS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all