##### FONT APPEARANCE ##########################################################
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

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

##### COMPILATION ##############################################################
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I ./inc

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

NAME	= libft.a

##### RULES ####################################################################
$(NAME): $(OBJ)
	@printf "\033[1;32m"	
	@$(ECHO) 'Creation of $@ 🏁'
	@printf "\033[0m"
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
	@printf "\033[1;34m"
	@$(ECHO) 'Creation of $@ directory 📁'
	@printf "\033[0m"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD)
	@printf "\033[1;33m"
	@$(ECHO) 'Compilation of $<'
	@printf "\033[0m"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re

endif
