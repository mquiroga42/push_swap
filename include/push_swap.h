/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyberoot <cyberoot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:26:27 by cyberoot          #+#    #+#             */
/*   Updated: 2023/01/20 09:16:35 by cyberoot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../modules/libft/include/libft.h"

typedef struct s_psList
{
	int 			content;
	struct s_psList	*next;
}					t_psList;

int			is_error(int argc, char **argv);
t_psList	*ps_lstlast(t_psList *lst);
t_psList	*ps_lstnew(int content);
void		swap(t_psList **bloq, char *tag);
void		push(t_psList **bloq01, t_psList **bloq02, char *tag);
void		rotate(t_psList **bloq, char *tag);
void		reverse(t_psList **bloq, char *tag);
int			ps_lstFindContent(t_psList *lst, int nb);
void		ps_lstadd_front(t_psList **lst, t_psList **new);
void		ps_lstadd_back(t_psList **lst, t_psList *new);
void		ps_lstcleaner(t_psList **lst);
void		push_swap(t_psList **bloq_a, t_psList **bloq_b);
void		print_list(t_psList *list, char *msg);

void		ps_lstClearFirstElement(t_psList **lst);
void		ps_lstClean(t_psList **lst);

#endif