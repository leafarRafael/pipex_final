NAME			:= pipex.a

SRC				:= main.c about_struct.c about_nbr_args.c\
				about_envp.c about_command.c about_nbr_args.c about_command.c\
				about_files.c about_other_utilities.c about_free_memory.c\
				about_executable.c about_children.c about_error_handling.c

NUM_FILES		:= $(words $(SRC))
O_FILE_PATH 	:= /o_file
OBJS			:= ./objs
INCLUDES		:= -I ../include -I ../lib/lib_get_print/includes
O_FILE			:= $(SRC:%.c=$(OBJS)/%.o)
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
	@echo "[$(shell echo 	$$(($(COUNT) * 100 / $(NUM_FILES))))%] pipex_a Progress"

clean:
	@$(CMD_CLEAN) $(OBJS) $(NAME)

fclean: clean
	@$(CMD_FCLEAN) $(NAME)

re: fclean all

.PHONI: all clean fclean re bonus
