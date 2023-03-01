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

int	is_error(int argc, char **argv)
{
	int	x;

	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		x = 0;
		while (argv[1][x] != '\0')
		{
			if (!ft_isdigit(argv[1][x] + 0))
				return (1);
			x++;
		}
	}
	return (0);
}
