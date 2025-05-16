NAME	:= lib_rt.a
MAKEFLAGS += --no-print-directory

#==============================COMPIL===========================#

CC = clang
CFLAGS = -Wall -Wextra -Werror
SILENT = 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

#================================COUNT============================#

NB_COMP	:=	1

ifndef RECURSION
TO_COMP :=	$(shell make RECURSION=1 -n | grep Compiling | wc -l)
else
TO_COMP	:=	1
endif

PERCENT	:= 0

NB_COMP_BONUS := 1
ifndef RECURSION
TO_COMP_BONUS := $(shell make bonus RECURSION=1 -n | grep Compiling | wc -l)
else
TO_COMP_BONUS := 1
endif

#==============================COLORS==============================#
NOC			= \e[0m
BOLD		= \e[1m
DIM			= \e[2m
UNDERLINE	= \e[4m
BLACK		= \e[1;30m
RED			= \e[1m\e[38;5;196m
GREEN		= \e[1m\e[38;5;76m
YELLOW		= \e[1m\e[38;5;220m
BLUE		= \e[1m\e[38;5;33m
PURPLE		= \e[1;35m
CYAN		= \e[1;36m
WHITE		= \e[1;37m
SPECIAL		= \e[1m\e[38;5;223m

BLACK_BG 	= \033[0;40m
RED_BG 		= \033[0;41m
GREEN_BG 	= \033[0;42m
YELLOW_BG 	= \033[0;43m
BLUE_BG 	= \033[0;44m
MAGENTA_BG 	= \033[0;45m
CYAN_BG 	= \033[0;46m
WHITE_BG 	= \033[0;47m
RESET_BG	= \033[0m

#================================DIRS============================#

SRC_DIR			:=  srcs
HEADER_DIR		:=	includes
BUILD_DIR		:=	.build

#==============================SOURCES===========================#

SRCS_FILES:=	array/ft_alloc_2d_tab.c \
				array/ft_free_2d_tab.c \
				conversion/ft_atoi.c \
				conversion/ft_atof.c \
				conversion/ft_atol.c \
				conversion/ft_atoll.c \
				conversion/ft_atoui.c \
				conversion/ft_itoa.c \
				conversion/ft_ltoa.c \
				conversion/ft_lltoa.c \
				conversion/ft_lutoa_base.c \
				get_next_line/get_next_line.c \
				mem/ft_bzero.c \
				mem/ft_calloc.c \
				mem/ft_memset.c \
				print/ft_print_address_fd.c \
				print/ft_print_char_fd.c \
				print/ft_printfd.c \
				print/ft_print_hexa_fd.c \
				print/ft_print_integer_fd.c \
				print/ft_print_str_fd.c \
				print/ft_print_unsigned_fd.c \
				print/ft_putchar.c \
				print/ft_putchar_fd.c \
				print/ft_putnbr_fd.c \
				print/ft_putstr.c \
				print/ft_putstr_fd.c \
				string/ft_isalnum.c \
				string/ft_isalpha.c \
				string/ft_isdigit.c \
				string/ft_split.c \
				string/ft_strcmp.c \
				string/ft_strcat.c \
				string/ft_strdup.c \
				string/ft_strjoin.c \
				string/ft_strjoinfree.c \
				string/ft_strlen.c \
				string/ft_strncmp.c \
				string/ft_strndup.c \
				string/ft_isascii.c
				

SRCS:=			$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

#=============================OBJECTS===========================#

OBJS:=			${SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o}

#===============================DEPS=============================#

DEPS:=			${SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.d}

#=============================INCLUDES===========================#

INC:=			-I$(HEADER_DIR)

#================================DIR=============================#

DIRS			:=	$(sort $(shell dirname $(OBJS)))

#===============================RULES============================#

all: $(NAME)

bonus: $(BONUS_NAME)

$(DIRS):
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "\n$(GREEN)Create binaries$(NOC)"
	@ar rcs $@ $^
	@if [ "$(SILENT)" = "0" ]; then \
		echo "$(PURPLE)"; \
		echo "    __    _ __         ____  ______"; \
		echo "   / /   (_) /_       / __ \/_  __/"; \
		echo "  / /   / / __ \     / /_/ / / /   "; \
		echo " / /___/ / /_/ /    / _, _/ / /    "; \
		echo "/_____/_/_.___/____/_/ |_| /_/     "; \
		echo "             /_____/               "; \
		echo "$(NOC)"; fi

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

clean:
	@echo "$(RED)Remove objects$(NOC)"
	@rm -f $(OBJ) $(BOBJ)
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)Remove binary$(NOC)"
	@rm -f $(NAME)

re: fclean
	@make

rebonus: fclean
	@make bonus

.PHONY: all clean fclean re rebonus

-include $(DEPS)
