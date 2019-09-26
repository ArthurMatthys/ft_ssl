# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/11 14:35:04 by amatthys     #+#   ##    ##    #+#        #
#    Updated: 2019/09/23 08:47:22 by amatthys    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_ssl

CC = gcc
CFLAGS += -Wall -Wextra -Werror -g

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./includes/
LFTDIR = ./libft/
H_FILE = $(INCDIR)ft_ssl.h $(INCDIR)ft_ssl_md5.h

INCLUDE = -I $(INCDIR) -I $(LFTDIR)includes

SRC = cmd.c ft_ssl.c ft_ssl_md5.c ft_ssl_sha256.c input_setup.c \
	  utils_general.c  print_struct.c ft_ssl_md5_parser.c \
	  ft_ssl_md5_fct.c ft_ssl_md5_cst.c ft_getstdin.c ft_ssl_print.c

C_FILES = $(addprefix $(SRCDIR), $(SRC))
O_FILES = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(C_FILES))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(O_FILES) $(LFTDIR)libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) -L$(LFTDIR) -lft $(INCLUDE)

$(LFTDIR)libft.a:
	make -C $(LFTDIR)

$(OBJDIR):
	mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(H_FILE)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	rm -rf $(OBJDIR)
	make -C $(LFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LFTDIR) fclean

re: fclean all
