/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/13 13:22:41 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** *//////////////////////

#include "push_swap.h"
/*extern unsigned int test;*/
void    swap(t_stack **first)
{
    t_stack *last;
    t_stack *b;
    t_stack *c;

    if (!*first)
        return ;
    if ((*first)->next == (*first)->prev)
    {
        *first = (*first)->next;
        return ;
    }
    last = (*first)->prev;
    b = (*first)->next;
    c = b->next;
    last->next = b;
    b->prev = last;
    (*first)->prev = b;
    b->next = *first;
    (*first)->next = c;
    c->prev = *first;
    *first = b;
}

void    s(t_stack **Afirst, t_stack **Bfirst, char mode)
{
    char buf[4];

    if (mode == 'a')
        swap(Afirst);
    else if (mode == 'b')
        swap(Bfirst);
    else
    {
        swap(Afirst);
        swap(Bfirst);
    }
    buf[0] = 's';
    buf[1] = mode;
    buf[2] = '\n';
    buf[3] = '\0';
    write(1, buf, 3);/*test++;printstacks(*Afirst, *Bfirst);*/
}


