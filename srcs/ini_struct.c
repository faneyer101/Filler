/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ini_struct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/26 20:11:35 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:41:47 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init(t_map *plateau, t_piece *tetri, t_resolv *solu, t_add *ad)
{
	tetri->size_x = 0;
	tetri->size_y = 0;
	plateau->size_x = 0;
	plateau->size_y = 0;
	solu->total = 0;
	solu->y = 0;
	solu->x = 0;
	ad->plat = plateau;
	ad->pie = tetri;
}
