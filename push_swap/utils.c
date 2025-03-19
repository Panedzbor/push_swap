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

void    errorexit(int val)
{
    write(2, "Error\n", 6);
    exit(val);
}

void    save_stacks(t_stks *stacks, t_stack **A, t_stack **B)
{
    stacks->A = A;
    stacks->B = B;
}


