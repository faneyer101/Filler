/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maphot.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 19:57:54 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 08:00:37 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_hot(t_map *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < p->size_y)
	{
		x = 0;
		while (x < p->size_x)
		{
			if (p->tab_m[y][x] == p->c[2] || p->tab_m[y][x] == p->c[3])
				p->tab_mcpy[y][x] = -1;
			else if (p->tab_m[y][x] == p->c[0] || p->tab_m[y][x] == p->c[1])
				p->tab_mcpy[y][x] = -2;
			else if (p->tab_m[y][x] == '.')
				p->tab_mcpy[y][x] = -3;
			x++;
		}
		y++;
	}
}

void	head_fun_norme(t_map *p, int a, int x, int y)
{
	if (x > 0 && p->tab_mcpy[y][x - 1] != '\0' && p->tab_mcpy[y][x - 1] == -3)
		p->tab_mcpy[y][x - 1] = a + 1;
	if ((x + 1) < p->size_x && p->tab_mcpy[y][x + 1] != '\0' &&
			p->tab_mcpy[y][x + 1] == -3)
		p->tab_mcpy[y][x + 1] = a + 1;
	if (y > 0 && p->tab_mcpy[y - 1][x] == -3)
		p->tab_mcpy[y - 1][x] = a + 1;
	if (p->size_y > (y + 1) && p->tab_mcpy[y + 1][x] == -3)
		p->tab_mcpy[y + 1][x] = a + 1;
	if (p->size_x > (x + 1) && p->size_y > (y + 1) &&
			p->tab_mcpy[y + 1][x + 1] != '\0' &&
			p->tab_mcpy[y + 1][x + 1] == -3)
		p->tab_mcpy[y + 1][x + 1] = a + 1;
	if (x > 0 && p->size_y > (y + 1) && p->tab_mcpy[y + 1][x - 1] != '\0' &&
			p->tab_mcpy[y + 1][x - 1] == -3)
		p->tab_mcpy[y + 1][x - 1] = a + 1;
	if (y > 0 && x > 0 && p->tab_mcpy[y - 1][x - 1] != '\0' &&
			p->tab_mcpy[y - 1][x - 1] == -3)
		p->tab_mcpy[y - 1][x - 1] = a + 1;
	if (y > 0 && (x + 1) < p->size_x && p->tab_mcpy[y - 1][x + 1] != '\0' &&
			p->tab_mcpy[y - 1][x + 1] == -3)
		p->tab_mcpy[y - 1][x + 1] = a + 1;
}

int		heat_fun(t_map *plateau, int a)
{
	int	x;
	int	y;
	int ret;

	y = 0;
	ret = 0;
	while (y < plateau->size_y)
	{
		x = 0;
		while (x < plateau->size_x)
		{
			if (plateau->tab_mcpy[y][x] == a)
			{
				ret = -1;
				head_fun_norme(plateau, a, x, y);
			}
			x++;
		}
		y++;
	}
	return (ret);
}

int		alloc(t_map *p, int i)
{
	if (!(p->tab_mcpy = (int**)malloc(sizeof(int*) * (p->size_y + 1))))
		return (-1);
	while (i < p->size_y)
	{
		if (!(p->tab_mcpy[i] = (int*)malloc(sizeof(int) * (p->size_x))))
			return (-1);
		i++;
	}
	p->tab_mcpy[i] = NULL;
	return (0);
}

int		copy_plateau(t_map *plateau)
{
	static int	ok = 0;
	int			i;
	int			x;
	int			y;

	if (ok == 0 && alloc(plateau, 0) == -1)
		return (-1);
	ok = 1;
	init_hot(plateau);
	i = -1;
	while (heat_fun(plateau, i) == -1)
		i++;
	y = 0;
	while (plateau->size_y > y)
	{
		x = 0;
		while (plateau->size_x > x)
		{
			if (plateau->tab_mcpy[y][x] == -3)
				plateau->tab_mcpy[y][x] = 2147483647;
			x++;
		}
		y++;
	}
	return (0);
}
