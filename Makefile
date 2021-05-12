# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 15:07:09 by bahaas            #+#    #+#              #
#    Updated: 2021/05/12 19:26:25 by bahaas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME	= checker

PSWAP_NAME		= push_swap

CHECKER_SRCS	= srcs/checker.c		\
				srcs/instructions.c		\
				srcs/parsing_args.c		\
				srcs/print.c			\
				srcs/init.c				\
				srcs/command.c			\
				srcs/free_checker.c		\
				srcs/execute.c			\
				srcs/utils.c			\

PSWAP_SRCS		= srcs/pswap.c 

CC				= clang

CFLAGS			= -Wextra -Werror -Wall -g

HEADER			= -I /includes

CHECKER_OBJS	= ${CHECKER_SRCS:.c=.o}

PSWAP_OBJS		= ${PSWAP_SRCS:.c=.o}

.c.o:
			@printf "\033[34m[PUSH_SWAP]\033[0m Generating objects... %-33.33s\r\033[0m" $@
			@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: 		checker push_swap

checker: 	${CHECKER_OBJS}
			@printf "\n"
			@make -C libft/ --no-print-directory -s
			@${CC} ${CFLAGS} ${HEADER} ${CHECKER_OBJS} -o ${CHECKER_NAME} -L libft/ -lft
			@echo "\033[34m[PUSH_SWAP]\033[0m Building checker program : \033[32mOK\033[0m"

push_swap:	${PSWAP_OBJS}
			@printf "\n"
			@make -C libft/ --no-print-directory -s
			@${CC} ${CFLAGS} ${HEADER} ${PSWAP_OBJS} -o ${PSWAP_NAME} -L libft/ -lft
			@echo "\033[34m[PUSH_SWAP]\033[0m Building push_swap program : \033[32mOK\033[0m"

clean:
			@make clean -C libft/ --no-print-directory
			@rm -rf ${CHECKER_OBJS}
			@rm -rf ${PSWAP_OBJS}
			@echo "\033[34m[PUSH_SWAP]\033[0m Delete .o files : \033[32mOK\033[0m"

fclean:		clean
			@make fclean -C libft/ --no-print-directory
			@rm -rf ${CHECKER_NAME}
			@rm -rf ${PSWAP_NAME}
			@echo "\033[34m[PUSH_SWAP]\033[0m Delete executable files : \033[32mOK\033[0m"

re: 		fclean all

.PHONY:	all clean fclean re checker push_swap
