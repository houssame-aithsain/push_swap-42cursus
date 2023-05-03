# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 22:26:05 by hait-hsa          #+#    #+#              #
#    Updated: 2023/02/19 22:26:06 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_M = push_swap-mandatory/

P_B = push_swap-bonus/

SRC_M = ${P_M}if_sorted_plus.c ${P_M}check_duplicate.c ${P_M}hundred_numb_plus.c \
	${P_M}memory_free.c ${P_M}size_counter.c ${P_M}checker_utils.c ${P_M}ft_strjoin.c \
	${P_M}ft_split.c ${P_M}ft_substr.c ${P_M}ft_strdup.c ${P_M}ft_atoi.c ${P_M}push_swap.c \
	${P_M}nodepush.c ${P_M}ft_count_argv.c ${P_M}st_a_actions.c ${P_M}st_b_actions.c ${P_M}three_numb.c \
	${P_M}five_numb.c ${P_M}check_argv.c ${P_M}ft_memcpy.c ${P_M}hundred_numb.c

SRC_B = ${P_B}memory_free_bonus.c ${P_B}st_a_actions_bonus.c ${P_B}st_b_actions_bonus.c \
	${P_B}nodepush_bonus.c ${P_B}ft_split_bonus.c ${P_B}if_sorted_bonus.c ${P_B}ft_substr_bonus.c \
	${P_B}ft_strjoin_bonus.c ${P_B}ft_memcpy_bonus.c ${P_B}ft_strdup_bonus.c ${P_B}ft_strncmp_bonus.c \
	${P_B}ft_atoi_bonus.c ${P_B}check_duplicate_bonus.c ${P_B}checker_bonus.c ${P_B}get_next_line_utils_bonus.c \
	${P_B}check_argv_bonus.c ${P_B}get_next_line_bonus.c ${P_B}check_argv_utils_bonus.c ${P_B}size_counter_bonus.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_M = ${SRC_M:.c=.o}

OBJS_B = ${SRC_B:.c=.o}

NAME_M = push_swap

NAME_B = checker

RM = rm -rf

all: ${NAME_M}

bonus: ${NAME_B}

${NAME_B}: ${OBJS_B}
		${CC} ${CFLAGS} ${OBJS_B} -o ${NAME_B}

${NAME_M} : ${OBJS_M}
		${CC} ${CFLAGS} ${OBJS_M} -o ${NAME_M}

clean:
	${RM} ${OBJS_M} ${OBJS_B}

fclean: clean
	${RM} ${NAME_M} ${NAME_B}

re: fclean all

.PHONY: all bonus clean fclean re