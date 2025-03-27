#include "so_long.h"

typedef struct s_list
{
    void *mlx;
    void *mlx_window;
    void  *player_image;
    void    *floor_image;
    void    *door_image;
    void    *collectible_image;
    void    *wall_image;
    int    image_width;
    int     image_height;
}t_list;

int ft_handler(int keycode, t_list *game)
{
    printf("%d\n", )
    (void)game;
    printf("%d\n", keycode);
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx, game->mlx_window);//deestro window
        mlx_destroy_display(game->mlx);// destroy mlx connection
        free(game->player_image);
        free(game);
        exit(1);
    }

    return (1);
}
int ft_close(t_list *game)
{
    mlx_destroy_window(game->mlx, game->mlx_window);
    mlx_destroy_display(game->mlx);
    free(game->player_image);
    free(game);
    exit(1);   
}
int       display_image(t_list *game)
{                                                                //display p at pos 50 50
    mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_image, 0 , 0);
    mlx_put_image_to_window(game->mlx, game->mlx_window, game->door_image, 51, 51);
    mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_image, 100, 100);
    mlx_put_image_to_window(game->mlx, game->mlx_window, game->collectible_image, 200, 200);
    mlx_put_image_to_window(game->mlx, game->mlx_window, game->wall_image, 0, 0);

    return (0);
}

int main()
{
    t_list *game = malloc(sizeof(t_list));
    game->mlx = mlx_init();
    game->mlx_window = mlx_new_window(game->mlx, 300, 300, "test!");
    mlx_key_hook(game->mlx_window, ft_handler, game);
    mlx_hook(game->mlx_window, 17, 0, ft_close, game);
    game->player_image = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &game->image_width, &game->image_height);
    game->door_image = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm", &game->image_width, &game->image_height);
    game->collectible_image = mlx_xpm_file_to_image (game->mlx, "./textures/collectibles.xpm", &game->image_width, &game->image_height);
    game->wall_image = mlx_xpm_file_to_image (game->mlx, "./textures/wall.xpm", &game->image_width, &game->image_height);
    game->floor_image = mlx_xpm_file_to_image (game->mlx, "./textures/floor.xpm", &game->image_width, &game->image_height);

    if (!game->player_image) {
    printf("Error: Could not load image.\n");
    free(game);
    return (1);  // Exit if the image could not be loaded
}
    display_image(game);
    mlx_loop(game->mlx);
}



