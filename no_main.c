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


static void genBloqList(int argc, char **argv, t_psList **bloq_a)
{
    t_psList *list;
    int y;

	list = NULL;
	y = 1;
	while (argv[y] && y < argc)
	{
	   ps_lstadd_back(&list, ps_lstnew(ft_atoi(argv[y])));
	   y++;
	}
	(*bloq_a) = list;
}

int	main(int argc, char **argv)
{
	t_psList	*bloq_a;
	t_psList  *bloq_b;

    if (is_error(argc, argv))
        return (write(2, "error\n", 6), 0);
    else
    {
        genBloqList(argc, argv, &bloq_a);
		t_psList *current = bloq_a;
        while (current != NULL)
        {
            printf("%d\n", current->content);
            current = current->next;
        }
    }

    return (0);
}