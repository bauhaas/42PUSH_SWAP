# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 15:07:09 by bahaas            #+#    #+#              #
#    Updated: 2021/05/12 03:03:36 by bahaas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME	= checker

PUSH_NAME		= push_swap

SRCS			= srcs/main.c			\
				srcs/instructions.c		\
				srcs/parsing_args.c		\
				srcs/print.c			\
				srcs/init.c				\
				srcs/command.c			\
				srcs/free_checker.c		\
				srcs/execute.c			\

SRCS_BONUS		=

CC			= gcc
#CFLAGS		= -Wextra -Werror -Wall -g
CFLAGS		= -g
RM			= rm -rf
HEADER		= -I /includes
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

.c.o:
			@printf "\033[0;33mGenerating push_swap objects... %-33.33s\r" $@
			@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: 		checker push_swap

checker: 	${OBJS}
			@make -C libft/
			@${CC} ${CFLAGS} ${HEADER} ${OBJS} -o ${CHECKER_NAME} -L libft/ -lft
			@echo "Building push_swap : \033[32mOK\033[0m"

push_swap:

clean:
			make clean -C libft/
			${RM} ${OBJS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			make fclean -C libft/
			${RM} ${NAME}

re: 		fclean all

bonus:		${OBJS_BONUS}
			make -C ${LIB_D}

.PHONY:	all clean fclean re checker push_swap
