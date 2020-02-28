/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 17:57:24 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:49:15 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int	tcheck_placement(t_add *ad, int *cd, int count, int *xy)
{
	while (ad->pie->size_y > xy[3] && ad->plat->size_y > (xy[2] + cd[0]))
	{
		xy[0] = 0;
		xy[1] = 0;
		while (ad->pie->size_x > xy[1] && ad->plat->size_x > (xy[0] + cd[1]))
		{
			if (ad->pie->tab_p[xy[3]][xy[1]] == '*' && (ad->plat->tab_m[xy[2] +
				cd[0]][xy[0] + cd[1]] == ad->plat->c[0] || ad->plat->tab_m[xy[2]
				+ cd[0]][xy[0] + cd[1]] == ad->plat->c[1]))
				count++;
			else if (ad->pie->tab_p[xy[3]][xy[1]] == '*' &&
				(ad->plat->tab_m[xy[2] + cd[0]][xy[0] + cd[1]] ==
				ad->plat->c[2] || ad->plat->tab_m[xy[2] + cd[0]][xy[0]
				+ cd[1]] == ad->plat->c[3]))
				return (-1);
			xy[0]++;
			xy[1]++;
		}
		xy[2]++;
		xy[3]++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	calcul(t_resolv *solution, t_piece *tetri, t_map *plateau, int *cd)
{
	int				x;
	int				y;
	long long int	toto;

	y = 0;
	toto = 0;
	while (tetri->size_y > y)
	{
		x = 0;
		while (tetri->size_x > x)
		{
			if (tetri->tab_p[y][x] == '*' && (plateau->tab_m[cd[0] + y][cd[1] +
				x] != plateau->c[0] && plateau->tab_m[cd[0] + y][cd[1] + x]
				!= plateau->c[1]))
				toto += plateau->tab_mcpy[cd[0] + y][cd[1] + x];
			x++;
		}
		y++;
	}
	if (solution->total == 0 || toto <= solution->total)
	{
		solution->total = toto;
		return (0);
	}
	return (-1);
}

int	opti(t_map *plateau, t_piece *tetri, int *coord, int a)
{
	int	i;

	i = 0;
	if (a == 1)
		while (i < plateau->size_x)
		{
			if (plateau->tab_m[coord[0] + pos_y(tetri)][i] == plateau->c[2] ||
				plateau->tab_m[coord[0] + pos_y(tetri)][i] == plateau->c[3])
				return (-1);
			i++;
		}
	if (a == 2)
		while (i < plateau->size_y)
		{
			if (plateau->tab_m[i][coord[1] + pos_x(tetri)] == plateau->c[2] ||
				plateau->tab_m[i][coord[1] + pos_x(tetri)] == plateau->c[3])
				return (-1);
			i++;
		}
	return (0);
}

int	resolv(t_add *address, t_resolv *solution)
{
	int		coord[2];
	int		xy[4];

	coord[0] = address->plat->size_y - address->pie->size_y;
	while (coord[0] >= (0 - pos_y(address->pie)))
	{
		coord[1] = address->plat->size_x - address->pie->size_x;
		while (coord[1] >= (0 - pos_x(address->pie)))
		{
			xy[0] = 0;
			xy[1] = 0;
			xy[2] = 0;
			xy[3] = 0;
			if (tcheck_placement(address, coord, 0, xy) == 0 &&
				calcul(solution, address->pie, address->plat, coord) == 0)
			{
				solution->y = coord[0];
				solution->x = coord[1];
			}
			coord[1]--;
		}
		coord[0]--;
	}
	return (0);
}
