/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyberoot <cyberoot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:06:01 by mquiroga          #+#    #+#             */
/*   Updated: 2022/10/19 09:06:18 by cyberoot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_psList	*ps_lstlast(t_psList *lst)
{
	t_psList	*aux;

	aux = lst;
	while (aux)
	{
		if (aux->next)
			aux = aux->next;
		else
			break ;
	}
	return (aux);
}

void	ps_lstadd_back(t_psList **lst, t_psList *new)
{
	t_psList	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ps_lstlast(*(lst));
		tmp->next = new;
	}
}

t_psList	*ps_lstnew(int content)
{
	t_psList	*response;

	response = (t_psList *)malloc(sizeof(t_psList));
	if (!response)
		return (0);
	response->content = content;
	response->next = NULL;
	return (response);
}
