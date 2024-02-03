NAME			:= pipex_bonus.a

SRC_BONUS		:= about_argv_bonus.c about_envp_bonus.c\
				about_error_bonus.c about_structs_bonus.c\
				main_bonus.c children_bonus.c\
				utils_bonus.c funcoes_temp_bonus.c\
				memory_freeing.c about_command.c

NUM_FILES		:= $(words $(SRC_BONUS))
O_FILE_PATH 	:= /o_file
OBJS			:= ./objs
INCLUDES		:= -I ../include_bonus -I ../lib/lib_get_print/includes
O_FILE			:= $(SRC_BONUS:%.c=$(OBJS)/%.o)
CC				:= cc
CFLAGS 			:= -Wall -Werror -Wextra
O_FLAGS 		:= -c
CMD_CLEAN		:= rm -Rf
CMD_FCLEAN		:= rm -rf

all : $(NAME)

$(NAME): $(O_FILE) $(LIBFT)

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@ar -rc $(NAME) $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@echo "[$(shell echo 	$$(($(COUNT) * 100 / $(NUM_FILES))))%] pipex_bonus Progress"

clean:
	@$(CMD_CLEAN) $(OBJS) $(NAME)

fclean: clean
	@$(CMD_FCLEAN) $(NAME)

re: fclean all

.PHONI: all clean fclean re bonus
