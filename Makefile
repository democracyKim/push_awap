# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:00:36 by minkim3           #+#    #+#              #
#    Updated: 2023/03/16 10:26:28 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -fsanitize=address
NAME		= push_swap.a
AR			= ar -rcs
RM			= rm -f
HEADER		= push_swap.h
LIBFT		= libft/libft.a
SOURCES		= utils/stack_utils.c\
			  utils/stack_utils2.c\
			  utils/stack_utils3.c\
			  utils/exit.c\
			  utils/doubly_linked_stack.c\
			  utils/valid_args.c\
			  utils/fill_stack.c\
			  utils/pattern.c\
			  utils/sort_numbers_a.c\
			  utils/sort_numbers.c\
			  greedy/apply_greedy.c\
			  greedy/calculate_cost.c\
			  greedy/move_init.c\
			  greedy/get_pivot.c\
			  
S_SOURCES	= push_swap.c\
			  operations/push.c\
			  operations/reverse.c\
			  operations/rotate.c\
			  operations/swap.c

B_SOURCES	= checker.c\
			  checker_operations/push.c\
			  checker_operations/reverse.c\
			  checker_operations/rotate.c\
			  checker_operations/swap.c

OBJECTS    = $(SOURCES:.c=.o)
S_OBJECTS  = $(S_SOURCES:.c=.o)
B_OBJECTS  = $(B_SOURCES:.c=.o)

all:
	make lib
	make $(NAME)
	make push_swap

$(NAME): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	make -C libft

clean:
	$(RM) $(OBJECTS) $(OBJECTS:.o=.d) $(S_OBJECTS) $(S_OBJECTS:.o=.d) $(B_OBJECTS) $(B_OBJECTS:.o=.d)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) push_swap checker
	make fclean -C libft

re:
	make fclean
	make all

push_swap: $(S_OBJECTS) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

checker: $(B_OBJECTS) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

bonus: lib $(NAME) checker

.PHONY: all lib clean fclean re bonus

-include $(OBJECTS:.o=.d) $(S_OBJECTS:.o=.d) $(B_OBJECTS:.o=.d)
