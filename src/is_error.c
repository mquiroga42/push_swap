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

int	is_error(int argc, char ***argv)
{
	int	y;

	if (argc < 2)
		return (1);
	while (!argc)
	{
		y = 0;
		while (argv[argc][y])
		{
			write(1, &argv[argc][y], 1);
			y++;
		}
		argc++;
	}
	return (0);
}
