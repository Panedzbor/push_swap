/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/13 13:22:41 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** *//////////////////////

#include "push_swap.h"
extern unsigned int test;
void    rotate(t_stack **Afirst, t_stack **Bfirst, char mode)
{
    char buf[4];

    if (mode == 'a')
    {
        if (*Afirst)
            *Afirst = (*Afirst)->next;
    }
    else if (mode == 'b')
    {
        if (*Bfirst)
            *Bfirst = (*Bfirst)->next;
    }
    else if (mode == 'r')
    {
        if (*Afirst)
            *Afirst = (*Afirst)->next;
        if (*Bfirst)
            *Bfirst = (*Bfirst)->next;
    }
    buf[0] = 'r';
    buf[1] = mode;
    buf[2] = '\n';
    buf[3] = '\0';
    write(1, buf, 3);test++;
}

void    rev_rotate(t_stack **Afirst, t_stack **Bfirst, char mode)
{
    char buf[5];

    if (mode == 'a')
    {
        if (*Afirst)
            *Afirst = (*Afirst)->prev;
    }
    else if (mode == 'b')
    {
        if (*Bfirst)
            *Bfirst = (*Bfirst)->prev;
    }
    else if (mode == 'r')
    {
        if (*Afirst)
            *Afirst = (*Afirst)->prev;
        if (*Bfirst)
            *Bfirst = (*Bfirst)->prev;
    }
    buf[0] = 'r';
    buf[1] = 'r';
    buf[2] = mode;
    buf[3] = '\n';
    buf[4] = '\0';
    write(1, buf, 4);test++;
}
