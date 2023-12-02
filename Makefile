##### FONT APPEARANCE ##########################################################
END		=$'\033[0m
BOLD	=$'\033[1m
UNDER	=$'\033[4m
REV		=$'\033[7m
GREY	=$'\033[30m
RED		=$'\033[31m
GREEN	=$'\033[32m
YELLOW	=$'\033[33m
BLUE	=$'\033[34m
PURPLE	=$'\033[35m
CYAN	=$'\033[36m
WHITE	=$'\033[37m

##### PROCESS CALCULATOR #######################################################
ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
	T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
	N := x
	C = $(words $N)$(eval N := x $N)
	ECHO = printf "%3d %% - %s\n" `expr $C '*' 100 / $T`
endif

##### DIRECTORIES ##############################################################
BUILD	= .build
OBJ_DIR	= $(BUILD)/obj
SRC_DIR	= ./src
INC_DIR	= ./inc
SUB_DIR	+= ctype \
			input_output/ft_printf \
			input_output/get_next_line \
			list \
			memory \
			string
DIRS	:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

SUB_SRC	:= ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_tolower.c \
            ft_toupper.c
SRC		:= $(addprefix ctype/, $(SUB_SRC))

SUB_SRC	:= ft_lstadd_back.c \
            ft_lstadd_front.c \
            ft_lstclear.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstlast.c \
            ft_lstmap.c \
            ft_lstnew.c \
            ft_lstsize.c
SRC		+= $(addprefix list/, $(SUB_SRC))

SUB_SRC	:= ft_bzero.c \
            ft_calloc.c \
			ft_matrix_free.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c
SRC		+= $(addprefix memory/, $(SUB_SRC))

SUB_SRC	:= ft_putchar.c \
			ft_putchar_fd.c \
            ft_putendl_fd.c \
			ft_putnbr.c \
            ft_putnbr_fd.c \
			ft_putstr.c \
            ft_putstr_fd.c
SRC		+= $(addprefix input_output/, $(SUB_SRC))
SUB_PF	:= ft_printf.c \
            ft_printf_utils.c
SRC		+= $(addprefix input_output/ft_printf/, $(SUB_PF))
SUB_GNL	:= get_next_line.c \
            get_next_line_utils.c
SRC		+= $(addprefix input_output/get_next_line/, $(SUB_GNL))

SUB_SRC	:= ft_atoi.c \
			ft_atol.c \
            ft_itoa.c \
			ft_matrix_height.c \
            ft_split.c \
			ft_strcharjoin.c \
            ft_strchr.c \
            ft_strrchr.c \
            ft_strdup.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmapi.c \
            ft_strncmp.c \
			ft_strstr.c \
			ft_strrstr.c \
            ft_strnstr.c \
            ft_strtrim.c \
            ft_substr.c
SRC		+= $(addprefix string/, $(SUB_SRC))

OBJ		= $(SRC:%.c=$(OBJ_DIR)/%.o)

##### COMPILATION ##############################################################
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I $(INC_DIR)

NAME	= libft.a
CHECKSUM_FILE := $(BUILD)/last_build_checksum

##### RULES ####################################################################
$(NAME): $(OBJ)
	@printf "$(GREEN)$(BOLD)"	
	@$(ECHO) 'Creation of $@ 🏁'
	@printf "$(END)"
	@ar -rcs $@ $^

all: $(NAME)
	@if [ -e "$(CHECKSUM_FILE)" ] && [ "$$(cat $(CHECKSUM_FILE))" = "$$(make checksum)" ]; then \
		echo "${BOLD}${GREEN}[ OK ]  Libft is already built!${END}"; \
	else \
		make checksum > "$(CHECKSUM_FILE)"; \
		echo "\n${BOLD}${GREEN}[ OK ]  Libft built successfully! 🎉${END}"; \
	fi \

clean:
	@echo "${BOLD}${PURPLE}> All objects files have been deleted ❌${END}"
	@rm -rf $(BUILD)

fclean: clean
	@echo "${BOLD}${RED}> Cleaning has been done ❌${END}"
	@rm -rf $(NAME) a.out

re: fclean
	@$(MAKE) all

$(BUILD):
	@printf "$(BLUE)$(BOLD)"
	@$(ECHO) 'Creation of $@ directory 📁'
	@printf "$(END)"
	@mkdir -p $@ $(DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD)
	@printf "$(YELLOW)$(BOLD)"
	@$(ECHO) 'Compilation of $<'
	@printf "$(END)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

checksum:
	@find $(SRC_DIR) -name '*.c' | xargs cat | shasum -a 256 | cut -d ' ' -f 1

.PHONY: all clean fclean re

endif
