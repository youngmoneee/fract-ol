ARCH		= arch -x86_64
CC			= gcc
CLFAGS		= -Wall -Wextra -Werror

NAME		= fractol

SUFFIX		= -framework OpenGL -framework Appkit

MINILIBX	= mlx
FTPF		= ft_printf
INCLUDE		= ./include

SRCSDIR		= srcs
BSRCSDIR	= bonus

SRCSFILE	= main.c\
			  hook.c\
			  image.c\
			  window.c
BSRCSFILE	= main.c\
			  hook.c

SRCS		= $(addprefix $(SRCSDIR)/, $(SRCSFILE))
BSRCS		= $(addprefix $(BSRCSDIR)/, $(BSRCSFILE))

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

.c.o:
	$(ARCH) $(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(ARCH) $(CC) $(CFLAGS) -g $(OBJS) -I $(INCLUDE) -Lmlx -lmlx $(SUFFIX) -o $(NAME)

bonus		: $(BOBJS)
	$(ARCH) $(CC) $(CFLAGS) $(BOBJS) -I $(INCLUDE) -Lmlx -lmlx $(SUFFIX) -o $(NAME)

$(MINILIBX)	:
	$(MAKE) -c $(ARCH) ./$(MINILIBXDIR)
	cp $(MINILIBXDIR)/libmlx.dylib ./

clean		:
	rm -rf $(OBJS) $(BOBJS)

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all fclean clean re bonus
