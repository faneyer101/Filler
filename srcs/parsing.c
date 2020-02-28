/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 00:56:27 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:57:50 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int		stock_plateau(t_liste *list, t_map *plat, int i)
{
	if (!(plat->tab_m = (char**)malloc(sizeof(char*) * (plat->size_y + 1))))
		return (-1);
	while (list)
	{
		plat->tab_m[i] = ft_strdup(list->tmp);
		i++;
		list = list->next;
	}
	plat->tab_m[i] = NULL;
	return (0);
}

void	free_list(t_liste *list)
{
	t_liste	*next_list;

	next_list = list->next;
	while (list != NULL)
	{
		ft_strdel(&list->tmp);
		list->next = NULL;
		free(list);
		list = next_list;
		if (next_list != NULL)
			next_list = next_list->next;
	}
}

int		norme_parting(t_liste **list, t_add *address, char *line, int *i)
{
	static int	bole = 0;

	if (bole == 0)
	{
		bole++;
		stock_plateau(list[0], address->plat, 0);
		free_list(list[0]);
		if (!(address->pie->tab_p = (char**)malloc(sizeof(char*) *
						(address->pie->size_y + 1))))
			return (-1);
	}
	if (i[1] < address->pie->size_y)
	{
		if (!(address->pie->tab_p[i[1]] = ft_strdup(line)))
			return (-1);
		i[1]++;
		if (i[1] == address->pie->size_y)
		{
			address->pie->tab_p[i[1]] = NULL;
			bole = 0;
			return (-2);
		}
	}
	return (0);
}

int		parting_vm(char *line, t_add *address, int *i, t_liste **list)
{
	if ((ft_strstr(line, "Plateau")) != NULL)
	{
		address->plat->size_y = ft_atoi(&line[7]);
		address->plat->size_x = ft_atoi(&line[8 +
				ft_strlen_c(&line[8], ' ')]);
	}
	else if ((ft_strstr(line, "faneyer.filler")) != NULL)
		(ft_strstr(line, "p2") != NULL) ? (address->plat->c = "xXoO") :
			(address->plat->c = "oOxX");
	else if ((ft_strstr(line, "Piece")) != NULL)
	{
		address->pie->size_y = ft_atoi(&line[5]);
		address->pie->size_x = ft_atoi(&line[6 + ft_strlen_c(&line[6], ' ')]);
	}
	else if ((ft_strstr(line, "000") != NULL) ||
			(i[0] < address->plat->size_y && i[0] > 0))
	{
		push_back_list(list, &line[4]);
		i[0]++;
	}
	else if (address->pie->size_x != 0 || address->pie->size_y != 0)
		if (norme_parting(list, address, line, i) == -2)
			return (-2);
	return (0);
}

int		parsing(char *line, t_add *address, int fd)
{
	int		i[2];
	t_liste	*list;
	int		bole;
	int		ret;

	bole = 0;
	list = NULL;
	i[0] = 0;
	i[1] = 0;
	ret = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ret = parting_vm(line, address, i, &list);
		if (ret == -1)
			return (-1);
		else if (ret == -2)
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
