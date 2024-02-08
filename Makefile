# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:27:25 by rbutzke           #+#    #+#              #
#    Updated: 2024/02/08 08:58:03 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= pipex
CFLAGS					:= #-Wextra -Wall -Werror -g3
CC						:= cc
LIBFT					:= ./lib/lib_get_print/libft.a
PATH_MAKE_LIB			:= ./lib/lib_get_print
PIPEX_A					:= ./src/pipex.a
PATH_PIPEX				:= ./src
PIPEX_BONUS_A			:= ./src_bonus/pipex_bonus.a
PATH_PIPEX_BONUS		:= ./src_bonus
INCLUDE					:= -I ./include -I ./lib/lib_get_print/includes
CMD_CLEAN		:= rm -Rf
CMD_FCLEAN		:= rm -rf

all: $(NAME) $(LIBFT) $(PIPEX_A)

bonus: PIPEX_A			:= $(PIPEX_BONUS_A)
bonus: PATH_PIPEX		:= $(PATH_PIPEX_BONUS)
bonus: all

$(NAME): 
	@$(CC) $(PIPEX_A) $(LIBFT) $(INCLUDE) -o $(NAME)

$(NAME): $(LIBFT)

$(NAME): $(PIPEX_A)

pipex.a:
$(PIPEX_A): $(PATH_PIPEX)/Makefile
	@$(MAKE) -C $(PATH_PIPEX) --no-print-directory

libft:
$(LIBFT): $(PATH_MAKE_LIB)/Makefile
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory


pipex_clean:
	@$(MAKE) -C $(PATH_PIPEX) clean --no-print-directory
	@$(MAKE) -C $(PATH_PIPEX_BONUS) clean --no-print-directory

pipex_fclean:
	@$(MAKE) -C $(PATH_PIPEX) clean --no-print-directory
	@$(MAKE) -C $(PATH_PIPEX_BONUS) clean --no-print-directory

pipex_re:
	@$(MAKE) -C $(PATH_PIPEX) re --no-print-directory

clean: pipex_clean
	@$(CMD_CLEAN) $(OBJS)

fclean: clean libft_clean pipex_fclean
	@$(CMD_CLEAN) $(NAME) $(O_FILE)

re: fclean libft_re pipex_re

.PHONY: all, clean, fclean, re
