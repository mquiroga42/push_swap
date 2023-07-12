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

static int	gen_bloq_list(int argc, char **argv, t_psList **bloq_a)
{
	t_psList	*list;
	char		**aux;
	int			y;
	int			x;
	int			nb;

	list = NULL;
	y = 1;
	while (argv[y] && y < argc)
	{
		x = -1;
		aux = ft_split(argv[y], ' ');
		while (aux[++x])
		{
			nb = ft_atoi(aux[x]);
			if (ps_lstFindContent(list, nb) || !nb && aux[x] != "0")
				return (free(aux[x]), free(aux), 1);
			ps_lstadd_back(&list, ps_lstnew((nb)));
			free(aux[x]);
		}
		free(aux);
		y++;
	}
	(*bloq_a) = list;
	return (0);
}

void	print_list(t_psList *list, char *msg)
{
	t_psList	*current;

	printf("%s\n", msg);
	current = list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_psList	*bloq_a;
	t_psList	*bloq_b;

	bloq_a = NULL;
	bloq_b = NULL;
	if (is_error(argc, argv))
		return (write(2, "error\n", 6), 0);
	else
	{
		if (gen_bloq_list(argc, argv, &bloq_a))
			return (write(2, "error\n", 6), 0);
		print_list(bloq_a, "BLOQUE A");
		print_list(bloq_b, "BLOQUE B");

		printf("\n");
		swap(&bloq_a, "test");
		push(&bloq_a, &bloq_b, "test");
		rotate(&bloq_a, "test");
		reverse(&bloq_a, "test");

		printf("\n--------------------\n");
		print_list(bloq_a, "BLOQUE A");
		print_list(bloq_b, "BLOQUE B");

	}
	ps_lstcleaner(&bloq_a);
	ps_lstcleaner(&bloq_b);
	return (0);
}
