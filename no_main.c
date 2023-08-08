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
	char	**aux;
	size_t	pos;
	size_t	i;
	int		nb;

	pos = 0;
	while (argv[++pos] && pos < argc)
	{
		aux = ft_split(argv[pos], ' ');
		i = -1;
		while (aux[++i])
		{
			nb = ft_atoi(aux[i]);
			if ((!nb && (ft_strncmp(aux[i], "0", 1) != 0)
					&& (ft_strncmp(aux[i], " 0", 2) != 0)
					&& (ft_strncmp(aux[i], "0 ", 2) != 0)
					&& (ft_strncmp(aux[i], " 0 ", 3) != 0))
				|| ps_lstFindContent((*bloq_a), nb))
				return (free(aux[i]), free(aux), 1);
			ps_lstadd_back(&(*bloq_a), ps_lstnew((nb)));
		}
		free(aux);
	}
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
			return (write(2, "error2\n", 7), 0);
		push_swap(&bloq_a, &bloq_b);
		print_list(bloq_a, "\nBLOQ_A\n");
		print_list(bloq_b, "\nBLOQ_B\n");
	}
	ps_lstcleaner(&bloq_a);
	ps_lstcleaner(&bloq_b);
	return (0);
}
