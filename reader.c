/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:31:48 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/19 09:05:54 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_infs *infs)
{
	char	*line;
	int		i;
	char	*mapstr;

	i = 1;
	mapstr = ft_strdup("\0");
	while (i <= infs->maph && get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) > 3 && !ft_isdigit(*(line + 4)))
		{
			mapstr = ft_strjoindelone(&mapstr, (line + 4));
			ft_strdel(&line);
			mapstr = ft_strjoindelone(&mapstr, "\n");
			i++;
		}
		else
			ft_strdel(&line);
	}
	infs->map = ft_strsplit(mapstr, '\n');
	ft_strdel(&mapstr);
}

void	where_am_i(t_infs *in)
{
	int i;
	int j;

	i = -1;
	while (++i < in->maph)
	{
		j = -1;
		while (++j < in->mapw)
		{
			if (in->map[i][j] == in->mark
			|| in->map[i][j] == ft_tolower(in->mark))
			{
				(in->loc).y = i;
				(in->loc).x = j;
				return ;
			}
		}
	}
}

void	where_to_spread(t_infs *infs)
{
	int d[4];
	int max;

	where_am_i(infs);
	d[0] = abs((infs->loc).y);
	d[1] = abs(infs->mapw - (infs->loc).x);
	d[2] = abs(infs->maph - (infs->loc).y);
	d[3] = abs((infs->loc).x);
	max = ft_max_nums(4, d[0], d[1], d[2], d[3]);
	if (d[0] == max)
		infs->direction = 0;
	else if (d[1] == max)
		infs->direction = 1;
	else if (d[2] == max)
		infs->direction = 2;
	else if (d[3] == max)
		infs->direction = 3;
	if (infs->direction == 0 || infs->direction == 2)
		infs->dirlen = infs->maph;
	if (infs->direction == 1 || infs->direction == 3)
		infs->dirlen = infs->mapw;
}

void	read_map_tet(t_infs *infs)
{
	read_map(infs);
	read_tet(infs);
	if (infs->direction == -1)
		where_to_spread(infs);
}
