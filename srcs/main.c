/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 08:11:22 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 21:32:21 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_intdel(int **pa, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(pa[i]);
		pa[i] = NULL;
		i++;
	}
	free(pa[i]);
	pa[i] = NULL;
	free(pa);
	pa = NULL;
}

void	clear_prog(int i, t_map *plateau, t_piece *tetri)
{
	while (i < plateau->size_y)
	{
		ft_strdel(&plateau->tab_m[i]);
		i++;
	}
	i = 0;
	while (i < tetri->size_y)
	{
		ft_strdel(&tetri->tab_p[i]);
		i++;
	}
	free(tetri->tab_p);
	tetri->tab_p = NULL;
}

int		main(void)
{
	t_map		plateau;
	t_piece		tetri;
	t_resolv	solution;
	t_add		address;
	int			i;

	init(&plateau, &tetri, &solution, &address);
	while (1)
	{
		init(&plateau, &tetri, &solution, &address);
		parsing(NULL, &address, 0);
		copy_plateau(&plateau);
		resolv(&address, &solution);
		clear_prog(0, &plateau, &tetri);
		ft_printf("%d %d\n", solution.y, solution.x);
		i = 0;
		while (plateau.tab_m[i] != NULL)
		{
			ft_strdel(&plateau.tab_m[i]);
			i++;
		}
		free(plateau.tab_m);
	}
	ft_intdel(plateau.tab_mcpy, plateau.size_y);
	return (0);
}
