#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_map
{
	char			**map;
	int				height;
	int				x;
	int				y;
	int				len;
	int				collectibles;
	int				p;
	int				x_pos;
    int             y_pos;
	int				e;
	int				ff_c;
	int				ff_e; //boolen 
}					t_map;

int     ft_strln(char *str);
void    ft_putstr_fd(char *s, int fd);
int     ft_strncmp(char *s1, char *s2, size_t n);
int     calculate_map_height(char *filename);


int     is_valid_filename(char *str);


#endif
