# Variables
NAME = fractol
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft/includes -Iminilibx_linux
LDFLAGS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lX11 -lXext -lm

# Directorios
SRCDIR = sources
OBJDIR = objects
LIBFTDIR = libft
MLXDIR = minilibx_linux

# Archivos fuente
SRCS = sources/events.c \
	sources/inicialization.c \
	sources/main.c \
	sources/show_fractal.c \
	sources/utils.c

# Archivos objeto
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Reglas
all: libft mlx $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFTDIR)

mlx:
	@$(MAKE) -C $(MLXDIR)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft mlx
