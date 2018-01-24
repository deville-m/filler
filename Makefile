NAME = mdeville.filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes/ -Ilibft/includes
LDLIB = -Llibft/
LDFLAGS = -lft
SRCDIR= srcs/
LIB = libft.a
LIBDIR = libft

SRC =	main.c \
		board.c \
		output.c

SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(LIBDIR)/$(LIB):
	@$(MAKE) -j8 -C $(LIBDIR)

%.o: %.c
	@zsh -c "echo -n '\tCompiling $<'"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@zsh -c 'echo -e "\r\t\033[32mCompiled $@\033[0m "'

$(NAME): $(OBJ) $(LIBDIR)/$(LIB)
	@echo "\tLinking $@"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(OBJ) $(LDLIB) $(LDFLAGS)

clean:
	@rm -f $(OBJ) && $(MAKE) -C $(LIBDIR) clean && echo "Removed object files."

fclean: clean
	@rm -f $(NAME) && $(MAKE) -C $(LIBDIR) fclean && echo "Removed target(s)."

re: fclean $(NAME)

.PHONY: all clean fclean re $(LIBDIR)/$(LIB)
