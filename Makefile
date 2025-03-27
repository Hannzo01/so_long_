NAME = so_long

SRCS = filename_check.c map_reader.c print_utils.c so_long.c \
	gnl/get_next_line_utils.c gnl/get_next_line.c map_validation.c \
	check_map_content.c flood_fill.c display.c game_manager.c utils.c 

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
