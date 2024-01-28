/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:20:16 by huates            #+#    #+#             */
/*   Updated: 2024/01/15 13:30:04 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	check_height(t_data *data, int j, int i, int flag)
{
	if (data->height == 0)
		data->height = j;
	else if (data->height != j)
		ft_free(data, 1);
	else
		data->height = j;
	if (flag == 1)
		data->width = i + 1;
}

static void	map_arg_control(t_data *data, int i, int j)
{
	while (i < data->width)
	{
		while (j < data->height - 1)
		{
			if (data->map[i][j] == 'C')
				data->c_count++;
			else if (data->map[i][j] == 'E')
				data->e_count++;
			else if (data->map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
				data->p_count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (data->c_count < 1 || data->e_count != 1 || data->p_count != 1)
		ft_free(data, 1);
	move_control(data);
}

static void	map_wall_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->width)
	{
		while (j < data->height - 1)
		{
			if (data->map[0][j] != '1' || data->map[i][0] != '1')
				ft_free(data, 1);
			if (data->map[data->width - 1][j] != '1'
				|| data->map[i][data->height - 2] != '1')
				ft_free(data, 1);
			j++;
		}
		j = 0;
		i++;
	}
	map_arg_control(data, 0, 0);
}

static void	data_init(t_data *data, int i, int fd)
{
	if (fd < 0)
		ft_free(data, 1);
	if (data->map == NULL)
		data->map = (char **)malloc(sizeof(char *) * BUFFER_SIZE);
	if (!data->map)
		ft_free(data, 0);
	if (data->map[i] == NULL)
		data->map[i] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!data->map[i])
		ft_free(data, 0);
}

void	map_create(t_data *data, int i, int j, char *map)
{
	char	c;
	int		fd;

	fd = open(map, O_RDONLY);
	data_init(data, i, fd);
	while (read(fd, &c, 1) == 1 && fd > 0)
	{
		if (c == '0' || c == '1' || c == '\n' || c == 'C' || c == 'E'
			|| c == 'P')
		{
			data->map[i][j++] = c;
			if (c == '\n')
			{
				check_height(data, j, ++i, 1);
				j = 0;
				data_init(data, i, fd);
			}
		}
		else
			ft_free(data, 1);
	}
	check_height(data, ++j, ++i, 0);
	close(fd);
	map_wall_control(data);
}
