# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpauw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 17:41:17 by mpauw             #+#    #+#              #
#    Updated: 2017/12/15 16:03:10 by mpauw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = partitions
FLAGS = -Wall -Wextra -Werror 
INCLUDES = partitions.h
SRCS = partitions.c \
	   helpers.c 
OBJ = $(SRCS:%.c=%.o)
LFTDIR = libft/
LIBFT = libft.a
FT = ft
MAKE = make

all : $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT)
	-@gcc $(FLAGS) -o $(NAME) -ggdb $(OBJ) -I$(LFTDIR) -L$(LFTDIR) -l$(FT)
	-@echo "Partitions Ready"

%.o: %.c $(INCLUDES)
	-@gcc $(FLAGS) -I$(LFTDIR) -c $(SRCS)

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR) $(LIBFT)

clean:
	-@/bin/rm -f $(OBJ)
	-@$(MAKE) -C $(LFTDIR) clean

fclean: clean
	-@/bin/rm -f $(NAME)
	-@$(MAKE) -C $(LFTDIR) fclean

re: fclean all
