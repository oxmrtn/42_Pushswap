# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 15:16:33 by mtrullar          #+#    #+#              #
#    Updated: 2024/07/28 18:10:46 by mtrullar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME		=	push_swap
CHECKER		=	checker
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3

#Folders
INCLUDE			=	incs/
SRCS_DIR		=	srcs/
SRCS_BONUS_DIR	=	srcs_bonus/
LIBFT			= 	libft/
OBJ_DIR			=	obj/
OBJ_BONUS_DIR   =   obj_bonus/

RM				=	@rm -rf

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

BOLD = \e[1m
RESET = \e[0m

SRC_FILE =	list_func/basic_func.c			\
			list_func/func.c				\
			parsing/check_requirements.c	\
			swap_func/composed_swap.c		\
			swap_func/swap.c 				\
			algo/calc_mooves.c				\
			algo/moov.c						\
			algo/small_sort.c				\
			utils/stack_utils.c				\
			utils/algo_utils.c				\
			main.c							\
		
SRC_FILE_NO_MAIN = $(filter-out main.c, $(SRC_FILE))

SRC_BONUS_FILE =	main_checker.c			\
					execute_moov.c			\

SRCS		= $(addprefix $(SRCS_DIR), $(SRC_FILE))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

SRCS_NO_MAIN = $(addprefix $(SRCS_DIR), $(SRC_FILE_NO_MAIN))
OBJ_NO_MAIN  = $(addprefix $(OBJ_DIR), $(SRC_FILE_NO_MAIN:.c=.o))

SRCS_BONUS	= $(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS_FILE))
OBJ_BONUS	= $(addprefix $(OBJ_BONUS_DIR), $(SRC_BONUS_FILE:.c=.o))

OBJF			=	.cache_exists
OBJF_CHECKER	=	.bonus_cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) -I$(INCLUDE) $(OBJ) -Llibft -lcustomft
	@echo "$(GREEN)\e[1mPUSH_SWAP COMPILED!\e[0m$(DEF_COLOR)"

$(CHECKER): $(OBJ_BONUS) $(OBJ_NO_MAIN)
	@make -C $(LIBFT)
	@$(CC) -o $(CHECKER) $(CFLAGS) -I$(INCLUDE) $(OBJ_BONUS) $(OBJ_NO_MAIN) -Llibft -lcustomft
	@echo "$(GREEN)\e[1mCHECKER COMPILED!\e[0m$(DEF_COLOR)"
	
bonus: $(CHECKER)

$(OBJ_BONUS_DIR)%.o: $(SRCS_BONUS_DIR)%.c | $(OBJF_CHECKER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA)\e[1mCHECKER compiling:\e[0m $< $(DEF_COLOR)"
		
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA)\e[1mPUSH_SWAP compiling:\e[0m $< $(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/list_func
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/swap_func
	@mkdir -p $(OBJ_DIR)/algo
	@mkdir -p $(OBJ_DIR)/utils

$(OBJF_CHECKER):
	@mkdir -p $(OBJ_BONUS_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_BONUS_DIR)
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@make fclean -sC $(LIBFT)
	@echo "$(CYAN)Executable destroyed!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)\e[1mEverything has been rebuilt, fresh and clean\e[0m$(DEF_COLOR)"

test: $(NAME) $(CHECKER)
	@echo "$(GREEN)Running tests..."
	@if [ -z "$(ELT)" ]; then echo "$(RED)Error: Please provide the number of elements to sort (e.g., make test ELT=100 REP=1000 MAX=700)"; exit 1; fi
	@if [ -z "$(REP)" ]; then echo "$(RED)Error: Please provide the number of repetitions (e.g., make test ELT=100 REP=1000 MAX=700)"; exit 1; fi
	@if [ -z "$(MAX)" ]; then echo "$(RED)Error: Please provide the maximum number of moves (e.g., make test ELT=100 REP=1000 MAX=700)"; exit 1; fi
	@TOTAL_MOVES=0; \
	SUCCESS_COUNT=0; \
	MIN_MOVES=999999; \
	MAX_MOVES=0; \
	for i in $$(seq 1 $(REP)); do \
	NUMBERS=$$(shuf -i 1-1000 -n $(ELT) | tr '\n' ' '); \
	ARG="$$NUMBERS"; \
	RESULT=$$(./$(NAME) $$ARG | ./$(CHECKER) $$ARG); \
	if [ "$$RESULT" != "OK" ]; then \
		echo "$(RED)Erreur: Le tri n'a pas réussi pour le test $$i"; \
		continue; \
	fi; \
	MOVES=$$(./$(NAME) $$ARG | wc -l); \
	TOTAL_MOVES=$$((TOTAL_MOVES + MOVES)); \
	echo "$(GREEN)Test$(RESET) $(YELLOW)$$i:$(RESET) $(RED)$(BOLD)$$MOVES $(RESET)$(BLUE)coups$(RESET)"; \
	if [ $$MOVES -lt $$MIN_MOVES ]; then \
		MIN_MOVES=$$MOVES; \
	fi; \
	if [ $$MOVES -gt $$MAX_MOVES ]; then \
		MAX_MOVES=$$MOVES; \
	fi; \
	if [ $$MOVES -lt $(MAX) ]; then \
		SUCCESS_COUNT=$$((SUCCESS_COUNT + 1)); \
	fi; \
	done; \
	AVERAGE=$$((TOTAL_MOVES / $(REP))); \
	SUCCESS_PERCENTAGE=$$((SUCCESS_COUNT * 100 / $(REP))); \
	echo "Moyenne sur $(CYAN)$(BOLD)$(REP)$(RESET) tests avec $(CYAN)$(BOLD)$(ELT)$(RESET) éléments: $(RED)$(BOLD)$$AVERAGE$(RESET) coups"; \
	echo "Nombre minimum de coups: $(GREEN)$(BOLD)$$MIN_MOVES$(RESET)"; \
	echo "Nombre maximum de coups: $(RED)$(BOLD)$$MAX_MOVES$(RESET)"; \
	echo "Nombre de tests avec moins de $(CYAN)$(BOLD)$(MAX)$(RESET) coups: $(GREEN)$(BOLD)$$SUCCESS_COUNT$(RESET)"; \
	echo "Pourcentage de réussite: $(GREEN)$(BOLD)$$SUCCESS_PERCENTAGE%$(RESET)"

.PHONY: all clean fclean re bonus test