NAME = so_long
SRC = filename_check.c map_reader.c print_utils.c so_long.c \
	gnl/get_next_line_utils.c gnl/get_next_line.c map_validation.c \
	check_map_content.c flood_fill.c display.c game_manager.c \
	
OBJ = $(SRC:.c=.o)
CFLAGS = -g -Wextra -Werror -Wall -I /usr/include/minilibx-linux
CC = cc

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L/usr/include/minilibx-linux -lmlx -lX11 -lXext -o $(NAME)
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean