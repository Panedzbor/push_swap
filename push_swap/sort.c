/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/19 15:07:21 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    radixsort(t_stks *stacks, int size)
{
    int    maxbits;
    int    i;
    int    j;
    int count;
    char mode;

    maxbits = 0;
    i = countbits(&maxbits, size);
    while (i < maxbits)
    {
        count = 0;
        j = 0;
        if (*(stacks->A))
        {
            mode = 'a';
            while (j++ < size)
                stack_a_move_decision(stacks->A, stacks->B, i, &count);
        }
        else
        {
            mode = 'b';
            while (j++ < size)
                stack_b_move_decision(Afirst, Bfirst, i, &count);
        }
        if ((mode == 'a' && size - count >= size / 2) || (mode == 'b' && size - count < size / 2) || (i + 1 == maxbits))
        {
            while (*Bfirst)
                push(Afirst, Bfirst, 'a');
        }
        else
        {
            while (*Afirst)
                push(Afirst, Bfirst, 'b');
        }
        i++;
    }
}

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

void    stack_a_move_decision(t_stack **Afirst, t_stack **Bfirst, int i, int *count)
{
    if ((((*Afirst)->p >> i) & 1) == 0)
    {
        push(Afirst, Bfirst, 'b');
        count++;
    }
    else
        rotate(Afirst, Bfirst, 'a');
}

void    stack_b_move_decision(t_stack **Afirst, t_stack **Bfirst, int i, int *count)
{
    if ((((*Bfirst)->p >> i) & 1) == 1)
    {
        push(Afirst, Bfirst, 'a');
        count++;
    }
    else
        rotate(Afirst, Bfirst, 'b');
}
