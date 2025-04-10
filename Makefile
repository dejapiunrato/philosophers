# Variables
NAME = philosophers
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft/includes
LDFLAGS = -L$(LIBFTDIR) -lft -lm

# Directorios
SRCDIR = sources
OBJDIR = objects
LIBFTDIR = libft

# Archivos fuente
SRCS = $(wildcard $(SRCDIR)/*.c)

# Archivos objeto
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Reglas
all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft
