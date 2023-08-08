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

int check(t_psList **bloq_a)
{
    t_psList	*aux;
    int			response;

	aux = (*bloq_a);
    response = 0;
    while (aux->next)
    {
		if (aux->content > aux->next->content)
			return (0);
		aux = aux->next;
    }
	return (1);
}


int	*getNumInfo(t_psList *bloq_a)
{
	int		*response;
	t_psList	*aux;

	aux = bloq_a;
	response = malloc(sizeof(int) * 3);
	response[0] = 0;
	response[1] = (int)(aux->content);
	response[2] = 0;
	while (aux->next)
	{
		if (response[1] > (int)(aux->content))
		{
			response[1] = (int)(aux->content);
			response[2] = response[0];
		}
			
		aux = aux->next;
		response[0]++;
	}
	if (response[1] > (int)(aux->content))
	{
		response[1] = (int)(aux->content);
		response[2] = response[0];
	}
	return (response);
}

void	push_swap(t_psList **bloq_a, t_psList **bloq_b)
{
    int status;
	int	*tmp;
	int	size;

	tmp = getNumInfo((*bloq_a)); // MAX
    status = 1;
	size = tmp[0] + 1;
	free(tmp);
    while (size)
    {
		tmp = getNumInfo((*bloq_a)); // MAX
		if ((*bloq_a)->content == tmp[1])
		{
			push(&(*bloq_a), &(*bloq_b), "pb");
			size--;
		}
		else if ((*bloq_a)->next)
			rotate(&(*bloq_a), "ra");
		free(tmp);
    }
	tmp = getNumInfo((*bloq_b)); // MAX
	size = tmp[0] + 1;
	while(size--)
		push(&(*bloq_b), &(*bloq_a), "pa");
	free(tmp);

}

/**
 * 
 * tamaño de array
 * numero mas pequeño
 * posicion pequeño
 * 
 * si num_min < 1/2 tamaño 
 * 
*/