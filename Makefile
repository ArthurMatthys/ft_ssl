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
vpath %.c src/parser
vpath %.c src/hash
vpath %.c src/hash/md5
vpath %.c src/hash/sha2
vpath %.c src/hash/sha2/sha224
vpath %.c src/hash/sha2/sha256
vpath %.c src/hash/sha2/sha384
vpath %.c src/hash/sha2/sha512
vpath %.c src/hash/sha2/sha512224
vpath %.c src/hash/sha2/sha512256

.PHONY: all clean fclean re

NAME = ft_ssl

CC = gcc
CFLAGS += -Wall -Wextra -Werror -g

OBJDIR = ./obj/
INCDIR = ./includes/
LFTDIR = ./libft/
H_FILE = $(INCDIR)ft_ssl.h $(INCDIR)ft_ssl_hash.h
LIB=$(LFTDIR)libft.a

INCLUDE = -I $(INCDIR) -I $(LFTDIR)includes

SRC = ft_ssl.c \
	  ft_ssl_usage.c \
	  get_cmd.c \
	  read_file.c \
	  \
	  argv_utils.c \
	  dispatcher.c \
	  handle_raw_mode.c \
	  handle_history.c \
	  input_echo.c \
	  input_stdin.c \
	  line_edit.c \
	  stdin_to_cmd.c \
	  stdin_to_argv.c \
	  \
	  ft_ssl_hash.c \
	  ft_ssl_hash_routine.c \
	  ft_ssl_hash_utils.c \
      ft_ssl_utils_reg.c \
	  ft_ssl_print_hash.c \
	  \
	  ft_md5_fct.c \
	  ft_ssl_md5.c \
	  \
      ft_sha_s32.c \
      ft_sha_s64.c \
      ft_sha_utils.c \
	  \
	  ft_ssl_sha224.c \
	  \
	  ft_ssl_sha256.c \
	  \
	  ft_ssl_sha384.c \
	  \
	  ft_ssl_sha512.c \
	  \
	  ft_ssl_sha512224.c \
	  \
	  ft_ssl_sha512256.c

O_FILES = $(SRC:%.c=$(OBJDIR)%.o)

NAME_UP = FT_SSL

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: lib $(NAME) 

$(NAME): $(LIB) $(OBJDIR) $(O_FILES)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mLinking...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) -L$(LFTDIR) -lft $(INCLUDE)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mDone!\033[0m\n"

lib:
	@make -C $(LFTDIR)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: %.c $(H_FILE)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mBuilding $<\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	@printf "[$(NAME_UP)] \033[1;31mCleaned .o!\033[0m\n"
	@rm -rf $(OBJDIR)
	@make -C $(LFTDIR) clean

fclean: clean
	@printf "[$(NAME_UP)] \033[1;31mCleaned .a!\033[0m\n"
	@rm -f $(NAME)
	@make -C $(LFTDIR) fclean

test : all
	@./test_ssl.sh 2>/dev/null

re: fclean all
