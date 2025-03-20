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
/* ************************************************************************** */

#include "push_swap.h"

static t_stack  *create_list(int argc, char *argv[]);
void            init_struct(t_stack *last, t_stack *new, char *numstr, int stack_size);
void            assign_pos(t_stack *first, int size);
void            free_stack(t_stack **Afirst);

int main(int argc, char *argv[])
{
    t_stack *Afirst;
    t_stack *Bfirst;
    t_stks  stacks;
    int     size;

    checkinput(argc, argv);
    Afirst = create_list(argc, argv);
    Bfirst = NULL;
    save_stacks(&stacks, &Afirst, &Bfirst);
    size = argc - 1;
    assign_pos(Afirst, size);
    radixsort(size);
    record_result(Afirst);
    free_stack(&Afirst);
    return (0);
}

static t_stack *create_list(int argc, char *argv[])
{
    int     i;
    t_stack *first;
    t_stack *temp;
    t_stack *last;

    first = NULL;
    last = NULL;
    i = 1;
    while (i < argc)
    {
        temp = (t_stack *)ft_calloc(1, sizeof(t_stack));
        if (!temp)
            errorexit(-2);
        init_struct(last, temp, argv[i], argc - 1);
        if (!first)
            first = temp;
        last = temp;
        i++;
    }
    if (!first)
        errorexit(-2);
    last->next = first;
    first->prev = last;
    return (first);
}

void    init_struct(t_stack *last, t_stack *new, char *numstr, int stack_size)
{
    int     num;

    num = ft_atoi(numstr);
    new->x = num;
    new->p = 0;
    new->size = stack_size;
    new->next = NULL;
    if (!last)
    {
        new->prev = NULL;
        return ;
    }
    last->next = new;
    new->prev = last;
}

void    assign_pos(t_stack *first, int size)
{
    t_stack *temp;
    t_stack *min;
    int     pos;

    if (!first)
        errorexit(-3);
    pos = 1;
    while (pos <= size)
    {
        min = first;
        temp = first->next;
        while (temp != first)
        {
            if ((temp->x < min->x && temp->p == 0) || min->p > 0)
                min = temp;
            temp = temp->next;
        }
        min->p = pos++;
    }
}

void    free_stack(t_stack **Afirst)
{
    t_stack         *temp;

    temp = (*Afirst)->prev;
    while (temp != *Afirst)
    {
        temp = temp->prev;
        free((void *)temp->next);
        temp->next = NULL;
    }
    free((void *)temp);
    temp = NULL;
    *Afirst = NULL;
}
