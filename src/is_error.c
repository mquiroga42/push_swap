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

static int checkLinealList(char *argv)
{
    int x;
    int f_symbol;
    int f_space;

    x = 0;
    f_symbol = 0;
    f_space = 0;
    while (argv[x])
    {
        if (!ft_isdigit(argv[x]) && argv[x] != '-' && argv[x] != ' ')
            return (1);
        else if (argv[x] == '-')
        {
            if (f_symbol)
                return (1);
            f_symbol = 1;
        }
        else if (argv[x] == ' ')
        {
            if (f_space)
                return (1);
            f_space = 1;
        }
        else
        {
            f_symbol = 0;
            f_space = 0;
        }
        x++;
    }
    if (f_symbol || f_space)
        return (1);
   return (0);
}

static int checkMultilinealList(int argc, char **argv)
{
    int y;

    y = 0;
    while (argv[++y] && y < argc)
        if (checkLinealList(argv[y]))
            return (1);
    return (0);
}

int	is_error(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    else if (argc == 2)
        return (checkLinealList(argv[1]));
    else
        return (checkMultilinealList(argc, argv));
}
