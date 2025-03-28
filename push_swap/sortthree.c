/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:15:43 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/27 14:15:45 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortthree(t_stack **afirst, t_stack **bfirst, int size)
{
	if (size == 2)
		rotate(afirst, bfirst, 'a');
	else
	{
		if ((*afirst)->p == 1)
		{
			s(afirst, bfirst, 'a');
			rotate(afirst, bfirst, 'a');
		}
		else if ((*afirst)->p == 2 && (*afirst)->next->p == 1)
			s(afirst, bfirst, 'a');
		else if ((*afirst)->p == 2 && (*afirst)->next->p == 3)
			rev_rotate(afirst, bfirst, 'a');
		else if ((*afirst)->p == 3 && (*afirst)->next->p == 1)
			rotate(afirst, bfirst, 'a');
		else
		{
			s(afirst, bfirst, 'a');
			rev_rotate(afirst, bfirst, 'a');
		}
	}
}
