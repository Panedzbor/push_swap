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

static t_stack *create_list(int argc, char *argv[]);
void    init_struct(t_stack *last, t_stack *new, char *numstr);
unsigned int    count_size(t_stack *first);

unsigned int test = 0;

int main(int argc, char *argv[])
{
    t_stack         *Afirst;
    t_stack         *Bfirst;
    t_stack         *temp;
    unsigned int    size;

    Afirst = create_list(argc, argv);
    Bfirst = NULL;
    size = count_size(Afirst);
    sort(&Afirst, &Bfirst, size);
    temp = Afirst;
    while (temp->next != Afirst)
    {
        printf("%d\n", temp->x);fflush(stdout);
        temp = temp->next;
    }
    printf("%d\n", temp->x);fflush(stdout);
    while (temp != Afirst)
    {
        temp = temp->prev;
        free((void *)temp->next);
    }
    free((void *)temp);printf("instruct count: %u\n", test);
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
            exit (-1);
        init_struct(last, temp, argv[i]);
        if (!first)
            first = temp;
        last = temp;
        i++;
    }
    last->next = first;
    first->prev = last;
    return (first);
}

void    init_struct(t_stack *last, t_stack *new, char *numstr)
{
    int     num;

    num = ft_atoi(numstr);
    new->x = num;
    new->next = NULL;
    if (!last)
    {
        new->prev = NULL;
        return ;
    }
    last->next = new;
    new->prev = last;
}

unsigned int    count_size(t_stack *first)
{
    unsigned int    i;
    t_stack         *temp;

    if (!first)
        return (0);
    temp = first;
    i = 1;
    while (temp->next != first)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}
