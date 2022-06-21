/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:24:33 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/21 15:07:53 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_left(t_window *window)
{
	static int	a;

	if (window->keys.a && !window->keys.d && !window->keys.w && !window->keys.s)
	{
		window->player_img.x -= window->player_img.speed;
		if (window->mapa[(window->player_img.y / 64)] \
		[(window->player_img.x / 64)] == '1')
			window->player_img.x += window->player_img.speed;
		window->mvcount += 1;
		if (a < 2)
			a += 1;
		else
			a = 0;
	}
}

/*
void	ft_update_right(t_base *base)
{
	static int	d;

	if (!base->keys.a && base->keys.d && !base->keys.w && !base->keys.s)
	{
		base->img_p.img = base->img_p.img_d[d];
		base->img_p.x += base->img_p.pace;
		if (base->map[base->img_p.y / 32][(base->img_p.x / 32)] == '1')
			base->img_p.x -= base->img_p.pace;
		base->move_counter += 1;
		if (d < 2)
			d += 1;
		else
			d = 0;*/

void	ft_update_right(t_window *window)
{
	static int	d;

	if (!window->keys.a && window->keys.d && !window->keys.w && !window->keys.s)
	{
		window->player_img.x += window->player_img.speed;
		if (window->mapa[window->player_img.y / 64] \
		[(window->player_img.x / 64)] == '1')
			window->player_img.x -= window->player_img.speed;
		window->mvcount += 1;
		if (d < 2)
			d += 1;
		else
			d = 0;
	}
}

void	ft_update_up(t_window *window)
{
	static int	w;

	if (!window->keys.a && !window->keys.d && window->keys.w && !window->keys.s)
	{
		window->player_img.y -= window->player_img.speed;
		if (window->mapa[window->player_img.y / 64] \
		[window->player_img.x / 64] == '1')
			window->player_img.y += window->player_img.speed;
		window->mvcount += 1;
		if (w < 2)
			w += 1;
		else
			w = 0;
	}
}

void	ft_update_down(t_window *window)
{
	static int	s;

	if (!window->keys.a && !window->keys.d && !window->keys.w && window->keys.s)
	{
		window->player_img.y += window->player_img.speed;
		if (window->mapa[(window->player_img.y / 64)] \
		[(window->player_img.x / 64)] == '1')
			window->player_img.y -= window->player_img.speed;
		window->mvcount += 1;
		if (s < 2)
			s += 1;
		else
			s = 0;
	}
}

void	ft_wichside(t_window *window)
{
	static int	speed;

	if (speed++ < 10)
		return ;
	speed = 0;
	ft_update_up(window);
	ft_update_down(window);
	ft_update_left(window);
	ft_update_right(window);
}
