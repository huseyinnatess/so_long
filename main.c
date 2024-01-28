/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/01/01 11:20:08 by huates            #+#    #+#             */
/*   Updated: 2024/01/01 11:20:08 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

static void	create_data(t_data *data)
{
	data->width = 0;
	data->height = 0;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	data->player_img = NULL;
	data->player_exit_img = NULL;
	data->collectible_img = NULL;
	data->wall_img = NULL;
	data->exit_img = NULL;
	data->ground_img = NULL;
	data->img_size = 96;
	data->player_x = 0;
	data->player_y = 0;
	data->move_count = 0;
	data->map = NULL;
}

static void	image_add(t_data *data)
{
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&data->img_size, &data->img_size);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible.xpm",
			&data->img_size, &data->img_size);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&data->img_size, &data->img_size);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&data->img_size, &data->img_size);
	data->ground_img = mlx_xpm_file_to_image(data->mlx, "./textures/ground.xpm",
			&data->img_size, &data->img_size);
	data->player_exit_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_exit.xpm",
			&data->img_size, &data->img_size);
	if (data->player_img == NULL || data->collectible_img == NULL
		|| data->wall_img == NULL || data->exit_img == NULL
		|| data->ground_img == NULL || data->player_exit_img == NULL)
		ft_exit(data);
}

static void	add_graphic_2(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible_img,
			j * 96, i * 96);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_img, j
			* 96, i * 96);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, j
			* 96, i * 96);
}

void	add_graphics(t_data *data, int i, int j)
{
	while (++i < data->width)
	{
		while (++j < data->height - 1)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall_img, j * 96, i * 96);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->ground_img, j * 96, i * 96);
			add_graphic_2(data, i, j);
		}
		j = -1;
	}
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2 || check_file(argv[1]))
		ft_free(NULL, 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_free(data, 0);
	create_data(data);
	map_create(data, 0, 0, argv[1]);
	mlx_control(data);
	image_add(data);
	add_graphics(data, -1, -1);
	mlx_hook(data->mlx_win, 2, 0, ft_move, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
	ft_exit(data);
}
