/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:10:52 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/19 15:10:56 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int countbits(int *maxbits, int size)
{
    int i;

    i = size;
    while (i > 0)
    {
        (*maxbits)++;
        i >>= 1;
    }
    return (i);
}

void    errorexit(int val)
{
    write(2, "Error\n", 6);
    exit(val);
}

t_stks    *save_stacks(t_stks *stacks, t_stack **A, t_stack **B)
{
    static t_stks   *holder;

    if (!holder)
        holder = stacks;
    if (stacks)
    {
        stacks->A = A;
        stacks->B = B;
    }
    return (holder);
}


