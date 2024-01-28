/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:20:37 by huates            #+#    #+#             */
/*   Updated: 2024/01/15 12:41:49 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_data
{
	char	**map;
	int		width;
	int		height;
	int		c_count;
	int		p_count;
	int		e_count;
	int		player_x;
	int		player_y;
	int		move_count;
	void	*player_img;
	void	*player_exit_img;
	void	*collectible_img;
	void	*wall_img;
	void	*exit_img;
	void	*ground_img;
	int		img_size;
	void	*mlx;
	void	*mlx_win;
}			t_data;

void		map_create(t_data *data, int i, int j, char *map);
void		ft_free(t_data *data, int flag);
void		move_control(t_data *data);
void		mlx_control(t_data *data);
int			ft_exit(t_data *data);
int			ft_move(int key_code, t_data *data);
void		add_graphics(t_data *data, int i, int j);
void		free_visited(char **visited, t_data *data, int i);
int			check_file(char *map);

#endif
