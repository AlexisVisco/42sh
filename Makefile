# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/19 13:46:02 by aviscogl     #+#   ##    ##    #+#        #
#    Updated: 2018/01/23 20:58:11 by aviscogl    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = shell
CC = gcc
CC_FLAGS = -g

LFT_PATH = ./libft
SRC_PATH = ./src/
INC_PATH = -I ./includes -I $(LFT_PATH)/includes
OBJ_PATH = ./obj/

SRC_NAME = \
shell.c \
\
editor/editor.c \
editor/editor_insert.c \
editor/readline.c \
editor/readline_raw.c \
editor/readline_notty.c \
editor/handle_keys.c \
editor/terminal_manager.c \
editor/util/get_colums_len.c \
editor/util/get_cursor_pos.c \
editor/refresher/buf_append.c \
editor/refresher/refresh_line.c \
editor/refresher/refresh_utils.c \
editor/edit_fn/ef_clear_screen.c \
editor/edit_fn/ef_del_prev_word.c \
editor/edit_fn/ef_delete_curr_to_end.c \
editor/edit_fn/ef_delete_entire_line.c \
editor/edit_fn/ef_go_end.c \
editor/edit_fn/ef_go_home.c \
editor/edit_fn/ef_move_left.c \
editor/edit_fn/ef_move_right.c \
editor/edit_fn/ef_swap_char.c \
editor/edit_fn/redirect_to_functions.c \
\
util/ft_realloc.c \
util/ft_char_to_str.c \

EDITOR_FOLDERS = editor editor/util editor/refresher editor/keys_functions

OBJ_FOLDERS = $(EDITOR_FOLDERS) env eval exec lex messages parser util 
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_FOLDERS_BIS = $(addprefix $(OBJ_PATH),$(OBJ_FOLDERS))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft


$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir -p $(OBJ_PATH) $(OBJ_FOLDERS_BIS)
	$(CC) $(CC_FLAGS) $(INC_PATH) -o $@ -c $^

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

download_libft:
	@git clone https://github.com/AlexisVisco/libft/
	@cd libft && rm -rf .git

update_libft:
	@rm -rf ./libft
	@git clone https://github.com/AlexisVisco/libft/
	@cd libft && rm -rf .git

git_add:
	@git add includes/*.h
	@git add src/*
	@git add libft/src/*
	@git add libft/includes/*.h
	@git add libft/Makefile
	@git add Makefile
	@git add auteur

norme:
	norminette $(SRC)
	norminette ./includes $(LFT_PATH)/includes

launch: $(NAME)
	@./$(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re, download_libft, update_libft, git_add, norme