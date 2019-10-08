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

vpath %.c src
vpath %.c src/hash
vpath %.c src/hash/md5

.PHONY: all clean fclean re

NAME = ft_ssl

CC = gcc
CFLAGS += -Wall -Wextra -Werror -g

OBJDIR = ./obj/
INCDIR = ./includes/
LFTDIR = ./libft/
H_FILE = $(INCDIR)ft_ssl.h $(INCDIR)ft_ssl_hash.h

INCLUDE = -I $(INCDIR) -I $(LFTDIR)includes

SRC = ft_ssl.c \
	  ft_ssl_usage.c \
	  get_cmd.c \
	  read_file.c \
	  ft_ssl_hash_utils.c \
	  ft_ssl_hash_routine.c \
	  ft_ssl_hash.c \
	  ft_md5_fct.c \
	  ft_ssl_md5.c 

O_FILES = $(SRC:%.c=$(OBJDIR)%.o)


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

$(OBJDIR)%.o: %.c $(H_FILE)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	rm -rf $(OBJDIR)
	make -C $(LFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LFTDIR) fclean

re: fclean all
