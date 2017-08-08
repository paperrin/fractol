# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paperrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 19:37:35 by paperrin          #+#    #+#              #
#    Updated: 2017/08/08 20:08:37 by paperrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc

CFLAGS		=	-O3 -Wall -Wextra -Werror

RM			=	rm -rf

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

INC_DIRS	=	./include/			\
				./mlx/				\
				./libft/include/

LIB_DIRS	=	./libft/			\
				./mlx/

LIBS		=	-lft				\
				-lmlx

INC_PARAMS	=	$(INC_DIRS:%=-I%)

LIB_PARAMS	=	$(LIB_DIRS:%=-L%)

CFILES		=	main.c				\
				event.c				\
				event2.c			\
				put_pixel.c			\
				map_nb.c			\
				core_mandel_julia.c	\
				fract_mandelbrot.c	\
				fract_julia.c		\

HFILES		=	./include/fractol.h

SRC			=	$(CFILES:%=$(SRC_DIR)%)

OBJ			=	$(CFILES:%.c=$(OBJ_DIR)%.o)

# # # # #

all				:	$(NAME)

$(NAME)			:	$(OBJ) $(HFILES)
						make -C ./mlx/
						make -C ./libft/
						$(CC) $(OBJ) -o $@ $(LIB_PARAMS) $(LIBS) \
							-framework OpenGL -framework Appkit

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
						mkdir -p $(OBJ_DIR)
						$(CC) $(CFLAGS) $(INC_PARAMS) -c $< -o $@

clean			:
						$(RM) $(OBJ_DIR)
						make -C ./mlx/ clean
						make -C ./libft/ clean


fclean			:	clean
						$(RM) $(NAME)
						make -C ./libft/ fclean

re				:	fclean all
