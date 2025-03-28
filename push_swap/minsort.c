/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:17:34 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/25 20:17:36 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*findmin(t_stack *cur, int i, int *count);
static void		rotation_direction(
					int size, int count, t_stack **afirst, t_stack **bfirst);

void	minsort(t_stack **afirst, t_stack **bfirst, int size)
{
	int		i;
	int		count;
	int		pushed;
	t_stack	*cur;

	i = 1;
	pushed = 0;
	while (size - i >= 2)
	{
		cur = *afirst;
		count = 0;
		cur = findmin(cur, i, &count);
		while ((*afirst)->p != i)
			rotation_direction(size - pushed, count, afirst, bfirst);
		push(afirst, bfirst, 'b');
		pushed++;
		i++;
	}
	if ((*afirst)->p > (*afirst)->next->p)
		rotate(afirst, bfirst, 'a');
	while (*bfirst)
		push(afirst, bfirst, 'a');
}

static t_stack	*findmin(t_stack *cur, int i, int *count)
{
	while (cur->p != i)
	{
		cur = cur->next;
		(*count)++;
	}
	return (cur);
}

static void	rotation_direction(
				int size, int count, t_stack **afirst, t_stack **bfirst)
{
	if ((size - count) >= size / 2)
		rotate(afirst, bfirst, 'a');
	else
		rev_rotate(afirst, bfirst, 'a');
}
