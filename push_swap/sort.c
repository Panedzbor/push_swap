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

void    bubblesort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
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

void    minsort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    unsigned int    i;
    unsigned int    count;
    t_stack         *cur;

    i = 1;
    while (i < size)
    {
        cur = *Afirst;
        count = 0;
        while (cur->p != i)
        {
            cur = cur->next;
            count++;
        }
        while ((*Afirst)->p != i)
        {
            if ((size - count) >= size / 2)
                rotate(Afirst, Bfirst, 'a');
            else
                rev_rotate(Afirst, Bfirst, 'a');
        }
        push(Afirst, Bfirst, 'b');
        i++;
    }
    while (*Bfirst)
        push(Afirst, Bfirst, 'a');
}


void    radixsort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    unsigned int    maxbits;
    unsigned int    i;
    unsigned int    j;
    unsigned int count = 0;
    unsigned int count2;
    char mode;
    t_stack         *cur;

    maxbits = 0;
    i = size;
    mode = 'a';
    while (i > 0)
    {
        maxbits++;
        i >>= 1;
    }
    while (i < maxbits)
    {
        j = 0; count = 0;
        if (*Afirst)
        {
            mode = 'a';
            while (j < size)
            {
                if ((((*Afirst)->p >> i) & 1) == 0)
                    {push(Afirst, Bfirst, 'b');count++;}
                else
                {
                    cur = *Afirst;
                    count2 = 0;
                    while (((cur->p >> i) & 1) != 0)
                    {
                        cur = cur->next;
                        count2++;
                    }
                    if (count2 <= size / 2)
                        rotate(Afirst, Bfirst, 'a');
                    else
                        rev_rotate(Afirst, Bfirst, 'a');
                }
                j++;
            }
        }
        else
        {
            mode = 'b';
            while (j < size)
            {
                if ((((*Bfirst)->p >> i) & 1) == 1)
                    {push(Afirst, Bfirst, 'a');count++;}
                else
                {
                    cur = *Bfirst;
                    count2 = 0;
                    while (((cur->p >> i) & 1) != 0)
                    {
                        cur = cur->next;
                        count2++;
                    }
                    if (count2 <= size / 2)
                        rotate(Afirst, Bfirst, 'b');
                    else
                        rev_rotate(Afirst, Bfirst, 'b');///!!!!!
                }
                j++;
            }
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
