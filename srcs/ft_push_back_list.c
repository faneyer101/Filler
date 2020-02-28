/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_push_back_list.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 09:36:55 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 11:09:45 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

t_liste	*ft_create_elem(char *s)
{
	t_liste	*box;

	box = NULL;
	box = (t_liste*)malloc(sizeof(t_liste));
	if (box == NULL)
		return (box);
	box->tmp = ft_strdup(s);
	box->next = NULL;
	return (box);
}

void	push_back_list(t_liste **begin_list, char *str)
{
	t_liste	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = ft_create_elem(str);
		list = list->next;
	}
	else
		*begin_list = ft_create_elem(str);
}
