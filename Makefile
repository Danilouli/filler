# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:28:01 by schmurz           #+#    #+#              #
#    Updated: 2018/03/31 17:47:09 by dsaadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

null :=
space := ${null} ${null}

LIBDIR = ./libft
LIBS = -lft
LIBNAME = libft.a
INCLUDES = ./includes/
EXEC = dsaadia.filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCDIR = ./
SRCFILES = filler.c placer.c reader.c play.c strategy.c dists.c reader2.c \
						abs.c
HEADFILES = filler.h
SRC = $(subst ${space}, $(SRCDIR), $(SRCFILES))
HEAD = $(subst ${space}, $(INCLUDES), $(HEADFILES))
OBJ = $(SRC:.c=.o)

all: $(LIBNAME) $(EXEC)
		@printf "%b" "$(OK_COLOR)Finished : OK$(NO_COLOR)\n"

$(EXEC): $(OBJ) $(HEAD)
						@printf "%b" "$(COM_COLOR)Compiling : $(OBJ_COLOR)$(@)$(NO_COLOR)\n"
						@$(CC) -o $(EXEC) -L$(LIBDIR) $(LIBS) $(CFLAGS) $(OBJ)

$(LIBNAME):
					@printf "%b" "$(COM_COLOR)Compiling : $(OBJ_COLOR)$(@)$(NO_COLOR)\n"
					@make -C $(LIBDIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBDIR)
	@printf "%b" "$(WARN_COLOR)Cleaned : All .o file are annihilated$(NO_COLOR)\n"

fclean: clean
	@rm -f $(EXEC)
	@make fclean -C $(LIBDIR)
	@printf "%b" "$(WARN_COLOR)Fcleaned : Still there remains some ashes...$(NO_COLOR)\n"

re: fclean all

.SILENT: $(OBJ)
