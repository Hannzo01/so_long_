#include "so_long.h"
#include <stdio.h>


int ft_close(int keycode, void *cont)
{
	if (keycode == 65307)
		exit(0);
	printf("%d\n", keycode);
	return 0;
}

int			mlx_loop_end1(t_xvar *xvar)
{
	xvar->end_loop = 1;
	return (1);
}


int main()
{
	int x;

	x = 0;
	void *mlx_ptr = mlx_init();
	void *mlx_ptr1 = mlx_init();
	void *mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "test1");
	void *mlx_win1 = mlx_new_window(mlx_ptr1, 1000, 1000, "test2");
	void *image_c = mlx_xpm_file_to_image(mlx_ptr, "./textures/test.xpm", &x , &x);
	void *image_c1 = mlx_xpm_file_to_image(mlx_ptr1, "./textures/test.xpm", &x , &x);
	mlx_put_image_to_window(mlx_ptr, mlx_win, image_c, 0, 0);
	mlx_put_image_to_window(mlx_ptr1, mlx_win1, image_c1, 0, 0);
	mlx_key_hook(mlx_win, ft_close, NULL);
	mlx_key_hook(mlx_win1, ft_close, NULL);
	mlx_hook(mlx_win , 17, 0, mlx_loop_end1, mlx_ptr);
	pid_t pid = fork();
	if (pid == 0)
	{
		mlx_loop(mlx_ptr);
	}
	mlx_loop(mlx_ptr1);
}
