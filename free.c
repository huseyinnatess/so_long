/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:19:59 by huates            #+#    #+#             */
/*   Updated: 2024/01/15 12:58:27 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "./ft_printf/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>

void	ft_free(t_data *data, int flag)
{
	int	i;

	if (data != NULL)
	{
		if (data->map != NULL)
		{
			i = 0;
			while (i < data->width + 1)
			{
				free(data->map[i]);
				i++;
			}
			free(data->map);
			data->map = NULL;
		}
		free(data);
		data = NULL;
	}
	if (flag == 1)
		ft_printf("Error\n", 2);
	exit(0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player_img);
	mlx_destroy_image(data->mlx, data->player_exit_img);
	mlx_destroy_image(data->mlx, data->collectible_img);
	mlx_destroy_image(data->mlx, data->exit_img);
	mlx_destroy_image(data->mlx, data->ground_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free(data, 0);
	exit(0);
}

void	free_visited(char **visited, t_data *data, int flag)
{
	int	i;

	if (visited != NULL)
	{
		i = 0;
		if (visited[i] != NULL)
		{
			while (i < data -> height + 1)
			{
				free(visited[i]);
				i++;
			}
		}
		free(visited);
		visited = NULL;
	}
	if (flag == 1)
		ft_free(data, 0);
}
