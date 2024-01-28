/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:20:29 by huates            #+#    #+#             */
/*   Updated: 2024/01/15 12:58:53 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

static void	dfs(char **map, int y, int x, char **visited)
{
	if ((visited[y][x + 1] == '0') && (map[y][x + 1] == '0' || map[y][x
			+ 1] == 'C' || map[y][x + 1] == 'E'))
	{
		visited[y][x + 1] = '9';
		dfs(map, y, x + 1, visited);
	}
	if ((visited[y][x - 1] == '0') && (map[y][x - 1] == '0' || map[y][x
			- 1] == 'C' || map[y][x - 1] == 'E'))
	{
		visited[y][x - 1] = '9';
		dfs(map, y, x - 1, visited);
	}
	if ((visited[y + 1][x] == '0') && (map[y + 1][x] == '0' || map[y
			+ 1][x] == 'C' || map[y + 1][x] == 'E'))
	{
		visited[y + 1][x] = '9';
		dfs(map, y + 1, x, visited);
	}
	if ((visited[y - 1][x] == '0') && (map[y - 1][x] == '0' || map[y
			- 1][x] == 'C' || map[y - 1][x] == 'E'))
	{
		visited[y - 1][x] = '9';
		dfs(map, y - 1, x, visited);
	}
}

static void	visited_allocated(char **visited, t_data *data)
{
	if (visited == NULL)
		free_visited(visited, data, 1);
	visited[0] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (visited[0] == NULL)
		free_visited(visited, data, 1);
}

static void	check_map(t_data *data, char **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->height - 1)
		{
			if ((data->map[i][j] == 'C' || data->map[i][j] == 'E')
				&& visited[i][j] == '0')
			{
				write(1, "Error\n", 6);
				free_visited(visited, data, 1);
			}
			j++;
		}
		i++;
	}
	free_visited(visited, data, 0);
}

void	move_control(t_data *data)
{
	char	**visited;
	int		i;
	int		j;

	i = 0;
	visited = (char **)malloc(sizeof(char *) * BUFFER_SIZE);
	visited_allocated(visited, data);
	while (i < data->width)
	{
		j = 0;
		while (j < data->height - 1)
		{
			visited[i][j] = '0';
			j++;
		}
		i++;
		visited[i] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (visited[i] == NULL)
			free_visited(visited, data, 1);
	}
	visited[data->player_x][data->player_y] = '9';
	dfs(data->map, data->player_x, data->player_y, visited);
	check_map(data, visited);
}
