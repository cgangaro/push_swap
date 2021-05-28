# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 14:50:53 by cgangaro          #+#    #+#              #
#    Updated: 2021/05/28 13:48:15 by cgangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
PATH		= 	srcs
SRCS_NAME	=	main.c ft_list.c ft_utils.c first.c action.c create_list.c second.c
OBJS		= ${SRCS:.c=.o}
FLAGS		= -Wall -Werror -Wextra
SRCS		= $(addprefix ${PATH}/,${SRCS_NAME})
%.o: %.c ./inc/push_swap.h
		gcc $(FLAGS) -c $< -o $@
all:	$(NAME)
$(NAME) : $(OBJS)
			gcc $(FLAGS) $(OBJS)  -o $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS) $(NAME)
norme:
	@norminette $(SRCS) inc/push_swap.h