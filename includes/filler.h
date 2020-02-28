/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 08:12:16 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 21:12:41 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 1
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_map
{
	char			**tab_m;
	int				**tab_mcpy;
	char			*c;
	int				size_x;
	int				size_y;
}					t_map;

typedef struct		s_piece
{
	char			**tab_p;
	int				size_x;
	int				size_y;
}					t_piece;

typedef struct		s_liste
{
	char			*tmp;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_resolv
{
	long long int	total;
	int				y;
	int				x;
}					t_resolv;

typedef struct		s_add
{
	t_map			*plat;
	t_piece			*pie;
}					t_add;

int					get_next_line(const int fd, char **line);
int					parsing(char *line, t_add *address, int fd);
int					copy_plateau(t_map *plateau);
void				init(t_map *plateau, t_piece *tetri,
		t_resolv *solu, t_add *ad);
void				push_back_list(t_liste **begin_list, char *str);
int					resolv(t_add *address, t_resolv *solution);
int					pos_x(t_piece *tetri);
int					pos_y(t_piece *tetri);

#endif
