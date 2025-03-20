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

static void sort_values(char *mode, int *j, int i, int *count);
static void stack_a_move_decision(t_stack **Afirst, t_stack **Bfirst, int i, int *count);
static void stack_b_move_decision(t_stack **Afirst, t_stack **Bfirst, int i, int *count);
static void push_remaining_values(char mode, int count, int i, int maxbits);

void    radixsort(int size)
{
    int    maxbits;
    int    i;
    int    j;
    int count;
    char mode;

    mode = 0;
    maxbits = 0;
    i = countbits(&maxbits, size);
    while (i < maxbits)
    {
        count = 0;
        j = 0;
        sort_values(&mode, &j, i, &count);
        push_remaining_values(mode, count, i, maxbits);
        i++;
    }
}

static void    sort_values(char *mode, int *j, int i, int *count)
{
    t_stks  *stacks;
    int     size;

    stacks = save_stacks(NULL, NULL, NULL);
    if (*(stacks->A))
        size = (*(stacks->A))->size;
    else
        size = (*(stacks->B))->size;
    if (*(stacks->A))
    {
        *mode = 'a';
        while ((*j)++ < size)
            stack_a_move_decision(stacks->A, stacks->B, i, count);
    }
    else
    {
        *mode = 'b';
        while ((*j)++ < size)
            stack_b_move_decision(stacks->A, stacks->B, i, count);
    }
}

static void    stack_a_move_decision(t_stack **Afirst, t_stack **Bfirst, int i, int *count)
{
    if ((((*Afirst)->p >> i) & 1) == 0)
    {
        push(Afirst, Bfirst, 'b');
        (*count)++;
    }
    else
        rotate(Afirst, Bfirst, 'a');
}

static void    stack_b_move_decision(t_stack **Afirst, t_stack **Bfirst, int i, int *count)
{
    if ((((*Bfirst)->p >> i) & 1) == 1)
    {
        push(Afirst, Bfirst, 'a');
        (*count)++;
    }
    else
        rotate(Afirst, Bfirst, 'b');
}

static void    push_remaining_values(char mode, int count, int i, int maxbits)
{
    t_stks  *stacks;
    int     size;

    stacks = save_stacks(NULL, NULL, NULL);
    if (*(stacks->A))
        size = (*(stacks->A))->size;
    else
        size = (*(stacks->B))->size;
    if ((mode == 'a' && size - count >= size / 2) || (mode == 'b' && size - count < size / 2) || (i + 1 == maxbits))
    {
        while (*(stacks->B))
            push(stacks->A, stacks->B, 'a');
    }
    else
    {
        while (*(stacks->A))
            push(stacks->A, stacks->B, 'b');
    }
}
