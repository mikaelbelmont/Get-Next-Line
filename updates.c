/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:30:33 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/21 14:49:11 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap(t_window *window, char **mapa)
{
	int	i;
	int	j;

	i = -1;
	while (mapa[++i])
	{
		j = -1;
		while (mapa[i][++j])
		{
			if (mapa[i][j] == '1')
				mlx_put_image_to_window(window->mlx, \
				window->win, window->wall_img.img, j * 64, i * 64);
			else
				mlx_put_image_to_window(window->mlx, \
				window->win, window->floor_img.img, j * 64, i * 64);
		}
	}
}

void	ft_delcollect(t_window *window, int i, int j)
{
	if (window->player_img.x == j * 64 && window->player_img.y == i * 64)
	{
		window->mapa[i][j] = '0';
		window->collect_img.count++;
	}
	else
	{
		mlx_put_image_to_window(window->mlx, window->win, \
		window->collect_img.img, window->collect_img.x, window->collect_img.y);
	}
}

void	ft_initexit(t_window *window, char **mapa)
{
	int	i;
	int	j;

	i = -1;
	while (mapa[++i])
	{
		j = -1;
		while (mapa[i][++j])
		{
			if (mapa[i][j] == 'E')
			{
				window->exit_img.x = j * 64;
				window->exit_img.y = i * 64;
				mlx_put_image_to_window(window->mlx, window->win, \
				window->exit_img.img, window->exit_img.x, window->exit_img.y);
				if (window->player_img.x == j * 64 \
				&& window->player_img.y == i * 64)
					if (window->collect_img.count == window->collect_img.n)
						ft_end(window);
			}
		}
	}
}
