# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/11/30 11:44:19 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= philo
##-----------------------------##



##-----Directory Location------##
HEAD		= ./includes/
PRE			= ./srcs/
MAIN		= philo/
INPUT		= input/
UTILS		= utils/
ERROR		= error/
##-----------------------------##



##------------Srcs-------------##
MAINSRC			= philo.c
INPUTSRC		= input.c init_input.c
UTILSSRC		= input_utils.c ft_atoi.c ft_bzero.c ft_calloc.c
ERRORSRC		= malloc_error.c

SRCS			= ${addprefix ${MAIN}, ${MAINSRC}} ${addprefix ${INPUT}, ${INPUTSRC}} \
					${addprefix ${UTILS}, ${UTILSSRC}} ${addprefix ${ERROR}, ${ERRORSRC}}
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRCS:.c=.o}}
##-----------------------------##



##----------conpiler-----------##
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			${CC} ${CFLAGS} -I${HEAD} -c $< -o $@

${NAME}:	${OBJS}
			@echo "object file		compiled"
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "philo			created"
			@echo "         ___       ___       ___       ___       ___    "
			@echo "        /\  \     /\__\     /\  \     /\__\     /\  \   "
			@echo "       /::\  \   /:/__/_   _\:\  \   /:/  /    /::\  \  "
			@echo "      /::\:\__\ /::\/\__\ /\/::\__\ /:/__/    /:/\:\__\ "
			@echo "      \/\::/  / \/\::/  / \::/\/__/ \:\  \    \:\/:/  / "
			@echo "         \/__/    /:/  /   \:\__\    \:\__\    \::/  /  "
			@echo "                  \/__/     \/__/     \/__/     \/__/   "

# -fsanitize=address
clean:
			@${RM} ${OBJS}
			@echo "object file		removed"

fclean:		clean
			@${RM} ${NAME}
			@echo "philo			removed"

re:			fclean all

exe:		re
			@make -s clean

.PHONY:		all clean fclean re exe
##-----------------------------##