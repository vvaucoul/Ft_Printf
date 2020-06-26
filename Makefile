# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 14:21:42 by vvaucoul          #+#    #+#              #
#    Updated: 2019/12/27 15:05:13 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	=       libftprintf.a
LIBFT_A 	=		libft.a

COMP 		=		gcc -Wall -Werror -Wextra -g3 $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H 	=	-I include/
LIBFT_H 	= 	-I libft/

OBJ_DIR 	=	obj/
SRC_DIR 	=	srcs/
LIB_DIR 	=	libft/

CFILE    	=		ft_printf.c				\
					ft_parser.c				\
					ft_macros.c				\
					ft_macros_02.c			\
					ft_manage_main_str.c	\
					ft_parse_attribut.c		\
					ft_parse_str.c			\
					ft_parse_str_02.c		\
					ft_manage_display.c		\
					ft_manage_display_02.c	\
					ft_manage_attributs.c	\
					ft_manage_line.c		\
					ft_utoa.c				\
					ft_itoa_base.c			\
					ft_itoa_neg_base.c		\
					ft_strupper.c			\
					ft_ultoa.c				\
					ft_putaddress.c			\
					ft_ptrlen.c				\
					ft_putstr_spe.c			\
					ft_realloc.c

CFIND 		=		$(CFILE:%=$(SRC_DIR)%)

OFILE 		=		$(CFILE:%.c=%.o)

RM     		=       rm -f

OBJ 		=		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root dir.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re:	fclean all

.PHONY: all clean fclean re
