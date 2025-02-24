# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

# Directorios
SRCDIR = sources
OBJDIR = objects

# Archivos fuente
SRCS =	sources/ft_printf/ft_printf_utils.c \
		sources/ft_printf/ft_printf.c \
		sources/libft/ft_atoi.c \
		sources/libft/ft_bzero.c \
		sources/libft/ft_calloc.c \
		sources/libft/ft_isalnum.c \
		sources/libft/ft_isalpha.c \
		sources/libft/ft_isascii.c \
		sources/libft/ft_isdigit.c \
		sources/libft/ft_isprint.c \
		sources/libft/ft_itoa.c \
		sources/libft/ft_lstadd_back_bonus.c \
		sources/libft/ft_lstadd_front_bonus.c \
		sources/libft/ft_lstclear_bonus.c \
		sources/libft/ft_lstdelone_bonus.c \
		sources/libft/ft_lstiter_bonus.c \
		sources/libft/ft_lstlast_bonus.c \
		sources/libft/ft_lstmap_bonus.c \
		sources/libft/ft_lstnew_bonus.c \
		sources/libft/ft_lstsize_bonus.c \
		sources/libft/ft_memchr.c \
		sources/libft/ft_memcmp.c \
		sources/libft/ft_memcpy.c \
		sources/libft/ft_memmove.c \
		sources/libft/ft_memset.c \
		sources/libft/ft_putchar_fd.c \
		sources/libft/ft_putendl_fd.c \
		sources/libft/ft_putnbr_fd.c \
		sources/libft/ft_putstr_fd.c \
		sources/libft/ft_split.c \
		sources/libft/ft_strchr.c \
		sources/libft/ft_strdup.c \
		sources/libft/ft_striteri.c \
		sources/libft/ft_strjoin.c \
		sources/libft/ft_strlcat.c \
		sources/libft/ft_strlcpy.c \
		sources/libft/ft_strlen.c \
		sources/libft/ft_strmapi.c \
		sources/libft/ft_strncmp.c \
		sources/libft/ft_strnstr.c \
		sources/libft/ft_strrchr.c \
		sources/libft/ft_strtrim.c \
		sources/libft/ft_substr.c \
		sources/libft/ft_tolower.c \
		sources/libft/ft_toupper.c \
		sources/get_next_line/get_next_line.c

# Archivos objeto
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
