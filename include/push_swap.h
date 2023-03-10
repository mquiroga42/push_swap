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

int		is_error(int argc, char **argv, t_list **bloq_a);
void	push_swap(t_list **bloq_a, t_list **bloq_b);

#endif