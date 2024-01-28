/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_include.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:20:19 by huates            #+#    #+#             */
/*   Updated: 2024/01/15 12:58:50 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	mlx_control(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_free(data, 0);
	data->mlx_win = mlx_new_window(data->mlx, (data->height - 1) * 96,
			data->width * 96, "so_long");
	if (data->mlx_win == NULL)
		ft_free(data, 0);
}
