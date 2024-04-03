# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:27:25 by rbutzke           #+#    #+#              #
#    Updated: 2024/04/03 08:46:06 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= pipex
NAME_BONUS				:= pipex_bonus
CFLAGS					:= -Wextra -Wall -Werror -g3
CC						:= cc
LIBFT					:= ./lib/lib_get_print/libft.a
PATH_MAKE_LIB			:= ./lib/lib_get_print
PIPEX_A					:= ./src/pipex.a
PATH_PIPEX				:= ./src
PIPEX_BONUS_A			:= ./src_bonus/pipex_bonus.a
PATH_PIPEX_BONUS		:= ./src_bonus
INCLUDE					:= -I ./include -I ./lib/lib_get_print/includes
INCLUDE_BONUS			:= -I ./include_bonus -I ./lib/lib_get_print/include_bonus
CMD_CLEAN				:= rm -Rf
CMD_FCLEAN				:= rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(PIPEX_A)
	@echo "   $(NAME): program created successfully"
	@$(CC) $(PIPEX_A) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo ""
	@echo "   to use the program:"
	@echo "   ./$(NAME) input_file cmd1 cmd2 output_file"
	@echo "   ./$(NAME) input_file cmd1 \"cmd2 'flag1' 'flag2'\" output_file"
	@echo ""

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(PIPEX_BONUS_A)
	@echo "   $(NAME_BONUS): program created successfully"
	@$(CC) $(PIPEX_BONUS_A) $(LIBFT) $(INCLUDE_BONUS) -o $(NAME)
	@echo ""
	@echo "   to use the program:"
	@echo "   ./$(NAME_BONUS) input_file cmd1 \"cmd2 'flag1' 'flag2'\" ... output_file"
	@echo "   ./$(NAME_BONUS) here_doc limiter cmd1 cmd2 ... output_file"
	@echo ""

$(LIBFT): libft_a

$(PIPEX_A): pipex_a

$(PIPEX_BONUS_A): pipex_bonus_a

libft_a:
	@echo ""
	@echo "   ************************"
	@echo "  *         libft_a        *"
	@echo "   ************************"
	@echo "  *                        *"
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory
	@echo "   *                        *"
	@echo "    ************************"
	@echo ""

pipex_bonus_a:
	@echo "    *****************************"
	@echo "   *          pipex_bonus        *"
	@echo "    *****************************"
	@echo "   *                             *"
	@$(MAKE) -C $(PATH_PIPEX_BONUS) --no-print-directory
	@echo "   *                              *"
	@echo "    ******************************"
	@echo ""

pipex_a:
	@echo ""
	@echo "    *************************"
	@echo "   *        pipex_a          *"
	@echo "    *************************"
	@echo "   *                         *"
	@$(MAKE) -C $(PATH_PIPEX) --no-print-directory
	@echo "   *                          *"
	@echo "    **************************"
	@echo ""

pipex_clean:
	@$(MAKE) -C $(PATH_PIPEX) clean --no-print-directory
	@$(MAKE) -C $(PATH_PIPEX_BONUS) clean --no-print-directory

pipex_fclean:
	@$(MAKE) -C $(PATH_PIPEX) fclean --no-print-directory
	@$(MAKE) -C $(PATH_PIPEX_BONUS) fclean --no-print-directory

pipex_re:
	@$(MAKE) -C $(PATH_PIPEX) re --no-print-directory
	@$(MAKE) -C $(PATH_PIPEX_BONUS) re --no-print-directory

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) clean --no-print-directory

libft_fclean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory

clean: libft_clean pipex_clean

fclean: clean libft_fclean pipex_fclean
	@$(CMD_CLEAN) $(NAME) $(NAME_BONUS)

re: fclean libft_re pipex_re

.PHONY: all, clean, fclean, re, $(PIPEX_A), $(LIBFT)