# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 15:07:09 by bahaas            #+#    #+#              #
#    Updated: 2021/05/27 20:43:14 by bahaas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME	= checker

PSWAP_NAME		= push_swap

CHECKER_SRCS	= srcs/checker/checker.c			\
				srcs/checker/execute.c				\

PSWAP_SRCS		= srcs/pswap/pswap.c 				\
				srcs/pswap/big_size_algo.c			\
				srcs/pswap/small_size_algo.c		\
				srcs/pswap/select.c					\

COMMON_SRCS =	srcs/common/utils.c					\
				srcs/common/init.c					\
				srcs/common/print.c					\
				srcs/common/free_checker.c			\
				srcs/common/parsing_args.c			\
				srcs/common/instructions.c			\
				srcs/common/command.c				\
				srcs/common/init_stack.c			\
	
CC				= clang

CFLAGS			= -Wextra -Werror -Wall -g

HEADER			= -I /includes

CHECKER_OBJS	= ${CHECKER_SRCS:.c=.o}

PSWAP_OBJS		= ${PSWAP_SRCS:.c=.o}
	
COMMON_OBJS		= ${COMMON_SRCS:.c=.o}

.c.o:
	@printf "\033[34m[PUSH_SWAP]\033[0m Generating .o files: \033[32mOK\033[0m%-33.33s\r\033[0m"
			@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: 		checker push_swap

checker: 	${CHECKER_OBJS} ${COMMON_OBJS}
			@printf "\n"
			@make -C libft/ --no-print-directory -s
			@${CC} ${CFLAGS} ${HEADER} ${CHECKER_OBJS} ${COMMON_OBJS} -o ${CHECKER_NAME} -L libft/ -lft
			@echo "\033[34m[PUSH_SWAP]\033[0m Building checker program : \033[32mOK\033[0m"

push_swap:	${PSWAP_OBJS} ${COMMON_OBJS}
			@printf "\n"
			@make -C libft/ --no-print-directory -s
			@${CC} ${CFLAGS} ${HEADER} ${PSWAP_OBJS} ${COMMON_OBJS} -o ${PSWAP_NAME} -L libft/ -lft
			@echo "\033[34m[PUSH_SWAP]\033[0m Building push_swap program : \033[32mOK\033[0m"

clean:
			@make clean -C libft/ --no-print-directory
			@rm -rf ${CHECKER_OBJS}
			@rm -rf ${PSWAP_OBJS}
			@rm -rf ${COMMON_OBJS}
			@echo "\033[34m[PUSH_SWAP]\033[0m Delete .o files : \033[32mOK\033[0m"

fclean:		clean
			@make fclean -C libft/ --no-print-directory
			@rm -rf ${CHECKER_NAME}
			@rm -rf ${PSWAP_NAME}
			@echo "\033[34m[PUSH_SWAP]\033[0m Delete executable files : \033[32mOK\033[0m"

re: 		fclean all

.PHONY:	all clean fclean re checker push_swap
