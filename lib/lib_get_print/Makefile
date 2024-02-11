NAME = libft.a

FILES = libft/src_ctype/ft_isalnum.c libft/src_ctype/ft_isascii.c libft/src_ctype/ft_isprint.c\
		libft/src_ctype/ft_isalpha.c libft/src_ctype/ft_isdigit.c libft/src_ctype/ft_toupper.c\
		libft/src_ctype/ft_tolower.c libft/src_string/src_mem/ft_memcmp.c libft/src_string/src_mem/ft_memcpy.c\
		libft/src_string/src_mem/ft_memset.c libft/src_string/src_mem/ft_memchr.c libft/src_string/src_mem/ft_memmove.c\
		libft/src_string/src_str/ft_strncmp.c libft/src_string/src_str/ft_strnstr.c libft/src_string/src_str/ft_strdup.c\
		libft/src_string/src_str/ft_strlen.c libft/src_string/src_str/ft_strlcat.c libft/src_string/src_str/ft_bzero.c\
		libft/src_string/src_str/ft_strlcpy.c libft/src_string/src_str/ft_strchr.c libft/src_string/src_str/ft_strrchr.c\
		libft/src_stdlib/ft_calloc.c libft/src_stdlib/ft_atoi.c libft/src_lst/ft_lstclear.c\
		libft/src_lst/ft_lstdelone.c libft/src_lst/ft_lstadd_front.c libft/src_lst/ft_lstnew.c libft/src_lst/ft_lstmap.c\
		libft/src_lst/ft_lstlast.c libft/src_lst/ft_lstsize.c libft/src_lst/ft_lstiter.c libft/src_lst/ft_lstadd_back.c\
		libft/src_/ft_striteri.c libft/src_/ft_strjoin.c libft/src_/ft_itoa.c libft/src_/ft_strtrim.c\
		libft/src_/ft_split.c libft/src_/ft_substr.c libft/src_/ft_strmapi.c libft/src_put/ft_putendl_fd.c\
		libft/src_put/ft_putnbr_fd.c libft/src_put/ft_putstr_fd.c libft/src_put/ft_putchar_fd.c\
		get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\
		ft_printf/ft_putpointer.c ft_printf/ft_putstr.c ft_printf/ft_putnbr_base.c\
		ft_printf/ft_strl.c  ft_printf/ft_putchar.c ft_printf/ft_printf.c

NUM_FILES	:= $(words $(FILES))

O_FILE_PATH := /o_file
OBJS		:= ./objs
INCLUDES = ./includes
O_FILE = $(FILES:%.c=$(OBJS)/%.o)
CC = cc
CFLAGS = #-Wall -Werror -Wextra
O_FLAGS = -c

all :$(NAME)

$(NAME): $(O_FILE)

bonus: $(O_BONUS)

$(O_BONUS): $(B_FILES)

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -I$(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@ar -rc $(NAME) $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@echo "[$(shell echo 	$$(($(COUNT) * 100 / $(NUM_FILES))))%] libft Progress"

clean:
	rm -Rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONI: all clean fclean re bonus
