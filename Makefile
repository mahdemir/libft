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
			ft_printf \
			get_next_line \
			list \
			memory \
			stdio \
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

SUB_SRC	:= ft_printf.c \
            ft_printf_utils.c
SRC		+= $(addprefix ft_printf/, $(SUB_SRC))

SUB_SRC	:= get_next_line.c \
            get_next_line_utils.c
SRC		+= $(addprefix get_next_line/, $(SUB_SRC))

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
			ft_free_matrix.c \
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
SRC		+= $(addprefix stdio/, $(SUB_SRC))

SUB_SRC	:= ft_atoi.c \
			ft_atol.c \
            ft_itoa.c \
            ft_split.c \
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

##### RULES ####################################################################
$(NAME): $(OBJ)
	@printf "$(GREEN)$(BOLD)"	
	@$(ECHO) 'Creation of $@ 🏁'
	@printf "$(END)"
	@ar -rcs $@ $^

all: $(NAME)

clean:
ifeq (re, $(filter re, $(MAKECMDGOALS)))
	@echo "${BOLD}${RED}  0 % - Deleting $(BUILD) directory ❌${END}"
else ifeq (clean, $(filter clean, $(MAKECMDGOALS)))
	@echo "${BOLD}${RED}100 % - Deleting $(BUILD) directory ❌${END}"
else ifeq (fclean, $(filter fclean, $(MAKECMDGOALS)))
	@echo "${BOLD}${RED} 50 % - Deleting $(BUILD) directory ❌${END}"
endif
	@rm -rf $(BUILD)

fclean: clean
ifeq (re, $(filter re, $(MAKECMDGOALS)))

	@echo "${BOLD}${RED}  0 % - Deleting $(NAME) library ❌${END}"
else ifeq (fclean, $(filter fclean, $(MAKECMDGOALS)))
	@echo "${BOLD}${RED}100 % - Deleting $(NAME) library ❌${END}"
endif
	@rm -rf $(NAME) a.out

re: fclean
	@$(MAKE) all

$(BUILD):
	@printf "$(BLUE)$(BOLD)"
	@$(ECHO) 'Creation of $@ directory 📁'
	@printf "$(END)"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD)
	@printf "$(YELLOW)$(BOLD)"
	@$(ECHO) 'Compilation of $<'
	@printf "$(END)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re

endif
