/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyberoot <cyberoot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:36:42 by cyberoot          #+#    #+#             */
/*   Updated: 2023/01/20 09:18:21 by cyberoot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_error(int argc, char **argv, t_list_ps **bloq_a)
{
	int y;
	int	x;
	int status_minus;

	if (argc == 1)
		return (1);
	else
	{
		y = 1;
		while (y < argc)
		{
			x = 0;
			while (argv[y][x] != '\0')
			{
				if (!ft_isdigit(argv[y][x]))
					return (1);
				x++;
			}
			y++;
		}
	}
	return (0);
}
