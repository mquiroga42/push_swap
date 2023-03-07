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

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*bloq_a;
	t_list	*bloq_b;

	if (is_error(argc, argv, &bloq_a))
		return (write(2, "error\n", 6), 0);
	else
	{
        printf("%d", bloq_a->next->content);
		push_swap(&bloq_a, &bloq_b);
	}
	return (0);
}
