/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 14:53:42 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 14:54:21 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int	pos_x(t_piece *tetri)
{
	int	x;
	int	y;
	int	tmp;

	x = 0;
	y = 0;
	tmp = 99999999;
	while (y < tetri->size_y)
	{
		x = 0;
		while (x < tetri->size_x)
		{
			if (tetri->tab_p[y][x] == '*' && tmp > x)
			{
				tmp = x;
			}
			x++;
		}
		y++;
	}
	if (tmp == 99999999)
		return (-1);
	return (tmp);
}

int	pos_y(t_piece *tetri)
{
	int	y;
	int	x;
	int	tmp;

	x = 0;
	y = 0;
	tmp = 99999999;
	while (y < tetri->size_y)
	{
		x = 0;
		while (x < tetri->size_x)
		{
			if (tetri->tab_p[y][x] == '*' && tmp > y)
			{
				tmp = y;
			}
			x++;
		}
		y++;
	}
	if (tmp == 99999999)
		return (-1);
	return (tmp);
}
