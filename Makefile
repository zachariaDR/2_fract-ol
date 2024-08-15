# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 23:02:08 by zadriouc          #+#    #+#              #
#    Updated: 2024/08/14 19:00:06 by zadriouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= cc
FLAGS	= -Wall -Wextra -Werror -O3
RM		= rm -rf
LIBMLX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIB 	= $(addprefix lib/, ft_putchar_fd ft_putstr_fd ft_strncmp ft_strchr ft_strdup ft_strlcpy  ft_strtrim ft_substr\
			ft_atoi ft_atod ft_after_dot ft_strlen ft_is_digit)
FRACTS	= $(addprefix fractals/, mandelbrot julia tricorn burningship)
TOOLS	= $(addprefix tools/, coloring events math init)
CHECKS	= $(addprefix checks/, check_args no_dublicates one_single_dot only_nbs valid_order str_is_valid)
FILES	= $(addprefix srcs/, fractol $(FRACTS) $(TOOLS) $(LIB) $(CHECKS))

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER	= includes/fract_ol.h
INCLUDE = -I includes

# BONUS_FILES = $(addprefix bonus/, $(FILES))
# BONUS_SRC = $(BONUS_FILES:=_bonus.c)
# BONUS_OBJ = $(BONUS_FILES:=_bonus.o)
# BONUS_HEADER = bonus/fract_ol_bonus.h

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
	@ $(CC) $(FLAGS) $(OBJ) $(INCLUDE) $(OPTS) $(LIBMLX) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) $(FLAGS) $(INCLUDE) $(OPTS) -c $< -o $@

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

nice: all clean

re: fclean all
