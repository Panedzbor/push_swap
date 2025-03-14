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

int main(int argc, char *argv[])
{
    t_stack *first;

    first = create_list(argc, argv);
    return (0);
}

t_stack *create_list(argc, argv)
{
    int i;
    t_stack *first;
    t_stack *temp;

    first = NULL;
    i = 0;
    while (i < argc)
    {
        temp = (t_stack *)ft_calloc(1, sizeof(t_stack));
        if (!temp)
            exit (-1);
        init_struct(first, temp);
        if (!first)
            first = temp;
        i++;
    }
}

void    init_struct(t_stack *first, t_stack *new)
{
    t_stack *curr;

    if (!first)
    {
        new->prev = NULL;
        new->next = NULL;
        return ;
    }
    curr = first;
    while (curr->next)
        curr = curr->next;
    curr->next = new;
    new->prev = curr;
    new->next = NULL;
}
