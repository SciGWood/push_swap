# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:45:33 by gdetourn          #+#    #+#              #
#    Updated: 2023/12/05 14:33:15 by gdetourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror
CC		= cc

BONUS 	= checker

SRC_1	= 	push_swap.c \

SRC_2	= 	ft_cases_possibilities_ab.c \
			ft_cases_possibilities_ba.c \
			ft_cases_to_make.c \
			ft_cheapest_number.c \
			ft_error_and_free.c \
			ft_move_01.c \
			ft_move_02.c \
			ft_parsing.c \
			ft_sort_mult.c \
			ft_split.c \
			ft_utils_01.c \
			ft_utils_02.c \
			ft_utils_lst.c \

SRC_BONUS	= 	checker.c \
				get_next_line_utils.c \
				get_next_line.c \

OBJ_1		= $(SRC_1:.c=.o)
OBJ_2		= $(SRC_2:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

all : $(NAME) $(BONUS)

$(NAME): $(OBJ_1) $(OBJ_2)
	$(CC) $(CFLAGS) $(OBJ_1) $(OBJ_2) -o $(NAME)

$(BONUS): $(OBJ_2) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_2) $(OBJ_BONUS) -o $(BONUS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
		rm -rf $(OBJ_1) $(OBJ_2) $(OBJ_BONUS)

fclean: clean
		rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus