# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 23:02:08 by zadriouc          #+#    #+#              #
#    Updated: 2024/07/21 18:44:29 by zadriouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fract-ol

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
LIBMLX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -O3

FILES	= $(addprefix srcs/, mandelbrot)

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER	= includes/fract_ol.h

BONUS_FILES = $(addprefix bonus/, $(FILES))
BONUS_SRC = $(BONUS_FILES:=_bonus.c)
BONUS_OBJ = $(BONUS_FILES:=_bonus.o)
BONUS_HEADER = bonus/fract_ol_bonus.h

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

#Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus

all: $(NAME)

$(NAME):  $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(FLAGS) $(OBJ) $(OPTS) $(LIBMLX) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) $(FLAGS) $(OPTS) -c $< -o $@

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

bonus:
	@$(MAKE) -C bonus
clean_bonus:
	@$(MAKE) clean -C bonus
fclean_bonus:
	@$(MAKE) fclean -C bonus
re_bonus:
	@$(MAKE) re -C bonus

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(_INFO)$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(_INFO)$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all
