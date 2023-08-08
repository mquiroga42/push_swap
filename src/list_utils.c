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

void		swap(t_psList **bloq, char *tag)
{
	int 		aux;

	if ((*bloq) && (*bloq)->next)
	{
		aux = (*bloq)->content;
		(*bloq)->content = (*bloq)->next->content;
		(*bloq)->next->content = aux;
		ft_putstr_fd(tag, 1);
		ft_putstr_fd("\n", 1);
	}
}

void		push(t_psList **nlist, t_psList **cache, char *tag)
{
	t_psList	*tmp;
	t_psList	*aux;

	if (*nlist)
	{
		tmp = (*nlist);
		(*nlist) = (*nlist)->next;
		if ((*cache))
		{
			tmp->next = (*cache);
			(*cache) = tmp;
		}
		else
		{
			(*cache) = tmp;
			(*cache)->next = NULL;
		}
		ft_putstr_fd(tag, 1);
		ft_putstr_fd("\n", 1);
	}
}

void		rotate(t_psList **bloq, char *tag)
{
	t_psList	*aux;

	if ((*bloq) && (*bloq)->next)
	{
		aux = (*bloq);
		(*bloq) = (*bloq)->next;
		aux->next = NULL;
		ps_lstlast(*bloq)->next = aux;
		ft_putstr_fd(tag, 1);
		ft_putstr_fd("\n", 1);
	}
}

void		reverse(t_psList **bloq, char *tag)
{	
	t_psList	*aux;
	t_psList	*tmp;

	aux = NULL;
	tmp = NULL;
	if ((*bloq) && (*bloq)->next)
	{
		aux = (*bloq);
		while (aux && aux->next)
		{
			tmp = aux;
			aux = aux->next;
		}
		tmp->next = NULL;
		aux->next = (*bloq);
		(*bloq) = aux;
		ft_putstr_fd(tag, 1);
		ft_putstr_fd("\n", 1);
	}
}

//****//

void	ps_lstClean(t_psList **lst)
{
	t_psList	*tmp;

	if ((*lst) || (*lst)->next)
	{
		tmp = (*lst);
		if (tmp->next)
		{
			(*lst) = (*lst)->next;
		}
		
		tmp->content = NULL;
		tmp = NULL;
		//free(tmp);
	}
}

void	ps_lstcleaner(t_psList **lst)
{
	t_psList	*tmp;
	t_psList	*aux;

	tmp = (*lst);
	if (!*lst)
		return ;
	while (tmp)
	{
		if (tmp->next) {
			aux = tmp;
			tmp = tmp->next;
			free(aux);
		}
		else
			break ;
	}
	free(tmp);
}

//****//




int	ps_lstFindContent(t_psList *lst, int nb)
{
	t_psList	*aux;

	aux = lst;
	while (aux)
	{
		if (aux->content == nb)
			return (1);
		if (aux->next)
			aux = aux->next;
		else
			break ;
	}
	return (0);
}

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

void	ps_lstadd_front(t_psList **lst, t_psList **new)
{
	if (!(*lst))
		(*lst) = malloc(sizeof(t_psList *));
	(*new)->next = (*lst);
	(*lst) = (*new);
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
