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

static int gen_lineal_list(char **argv, t_list **bloq_a)
{
   return (0);
}

static int gen_multilineal_list(int argc, char **argv, t_list **bloq_a)
{
    int y;
    int number;

    y = 1;
    while (y < argc)
    {
        number = 0;
        if (argv[y][0] != '0')
        {
            number = ft_atoi(argv[y]);
            if (!number)
                return (0);
        }
        if (!(*bloq_a))
            (*bloq_a) = ft_lstnew((void *)number);
        else
            ft_lstadd_back(&(*bloq_a), ft_lstnew((void *)number));
        y++;
    }
    return (0);
}

int	is_error(int argc, char **argv, t_list **bloq_a)
{
    (*bloq_a) = 0;
    if (argc < 2)
        return (1);
    else if (argc == 2)
        gen_lineal_list(argv, &(*bloq_a));
    else
        return (gen_multilineal_list(argc, argv, &(*bloq_a)), 0);
    return (0);
}
/*
'\0'=(char)0
0
NULL=(void *)0
        '0'=(char)38
        */