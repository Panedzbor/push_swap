/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/13 13:22:41 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** *//////////////////////

#include "push_swap.h"

void    sort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
  //  t_stack         *constfirst;
    unsigned int    i;
    unsigned int    j;
    unsigned int    k;

//    constfirst = *Afirst;
    i = 1;
    while (i < size)
    {
        j = 0;
        while (j < size - i)
        {
            if ((*Afirst)->x > (*Afirst)->next->x)
                s(Afirst, Bfirst, 'a');
            rotate(Afirst, Bfirst, 'a');
            j++;
        }
        k = i;
        while (k > 0)
        {
            rotate(Afirst, Bfirst, 'a');
            k--;
        }
        i++;
    }    
}
