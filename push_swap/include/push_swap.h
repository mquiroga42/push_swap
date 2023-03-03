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

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/include/libft.h"

typedef struct s_list_ps
{
	void				*content;
	struct s_list_ps	*next;
}						t_list_ps;

int		is_error(int argc, char **argv);
void	push_swap(t_list_ps **bloq_a, t_list_ps **bloq_b);

#endif