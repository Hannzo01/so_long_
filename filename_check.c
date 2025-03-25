#include "so_long.h"

int	is_valid_filename(char *str)
{
	int	len;

	len = ft_strln(str);
	if (len < 5)
	{
		ft_putstr_fd("Error\nInvalid name\n", 2);
		return (0);
	}
	if (ft_strncmp(str + len - 4, ".ber", 4) != 0 || str[len - 5] == '/')
	{	
		ft_putstr_fd("Error\nInvalid name\n", 2);
		return (0);
	}
	return (1);
}