# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 08:30:37 by lilefebv          #+#    #+#              #
#    Updated: 2024/11/25 11:04:49 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = main.c player.c enemy.c shoot.c render.c stars.c
OBJ = $(SRC:.c=.o)
NAME = ft_shmup
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lncursesw
INCLUDES = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) $(CFLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDES)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all
