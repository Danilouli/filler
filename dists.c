/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:36:40 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 21:21:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	dist(t_point p1, t_point p2)
{
	return (abs(p1.y - p2.y) + abs(p1.x - p2.x));
}

int	dist_to_dir(t_infs *in)
{
	int		i;
	int		j;
	int		min;
	int		k;
	t_point	pt;

	i = -1;
	k = 0;
	min = 2147483647;
	while (++i < in->maph)
	{
		j = -1;
		while (++j < in->mapw)
		{
			pt.y = i;
			pt.x = j;
			if (in->map[i][j] == in->mark && (k = spread_dist(in, pt)) < min)
				min = k;
		}
	}
	return (min);
}

int	dist_to_rdir(t_infs *in)
{
	int		i;
	int		j;
	int		min;
	int		k;
	t_point	pt;

	i = -1;
	k = 0;
	min = 2147483647;
	while (++i < in->maph)
	{
		j = -1;
		while (++j < in->mapw)
		{
			pt.y = i;
			pt.x = j;
			if (in->map[i][j] == in->mark && (k = spreadr_dist(in, pt)) < min)
				min = k;
		}
	}
	return (min);
}

int	spreadr_dist(t_infs *in, t_point m)
{
	if (in->direction == 0)
		return (abs(in->maph - m.y) - 1);
	if (in->direction == 1)
		return (abs(m.x));
	if (in->direction == 2)
		return (abs(m.y));
	if (in->direction == 3)
		return (abs(in->mapw - m.x) - 1);
	return (abs(in->mapw - m.x));
}

int	spread_dist(t_infs *in, t_point m)
{
	if (in->direction == 0)
		return (abs(m.y));
	if (in->direction == 1)
		return (abs(in->mapw - m.x) - 1);
	if (in->direction == 2)
		return (abs(in->maph - m.y) - 1);
	if (in->direction == 3)
		return (abs(m.x));
	return (abs(m.x));
}
