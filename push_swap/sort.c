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

static void	sort_values(char *mode, int *j, int i, int *count);
static void	stack_a_move_decision(
				t_stack **afirst, t_stack **bfirst, int i, int *count);
static void	stack_b_move_decision(
				t_stack **afirst, t_stack **bfirst, int i, int *count);
static void	push_remaining_values(char mode, int count, int i, int maxbits);

void	radixsort(int size)
{
	int		maxbits;
	int		i;
	int		j;
	int		count;
	char	mode;

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

static void	sort_values(char *mode, int *j, int i, int *count)
{
	t_stks	*stacks;
	int		size;

	stacks = save_stacks(NULL, NULL, NULL);
	if (*(stacks->a))
		size = (*(stacks->a))->size;
	else
		size = (*(stacks->b))->size;
	if (*(stacks->a))
	{
		*mode = 'a';
		while ((*j)++ < size)
			stack_a_move_decision(stacks->a, stacks->b, i, count);
	}
	else
	{
		*mode = 'b';
		while ((*j)++ < size)
			stack_b_move_decision(stacks->a, stacks->b, i, count);
	}
}

static void	stack_a_move_decision(
				t_stack **afirst, t_stack **bfirst, int i, int *count)
{
	if ((((*afirst)->p >> i) & 1) == 0)
	{
		push(afirst, bfirst, 'b');
		(*count)++;
	}
	else
		rotate(afirst, bfirst, 'a');
}

static void	stack_b_move_decision(
				t_stack **afirst, t_stack **bfirst, int i, int *count)
{
	if ((((*bfirst)->p >> i) & 1) == 1)
	{
		push(afirst, bfirst, 'a');
		(*count)++;
	}
	else
		rotate(afirst, bfirst, 'b');
}

static void	push_remaining_values(char mode, int count, int i, int maxbits)
{
	t_stks	*stacks;
	int		size;

	stacks = save_stacks(NULL, NULL, NULL);
	if (*(stacks->a))
		size = (*(stacks->a))->size;
	else
		size = (*(stacks->b))->size;
	if ((mode == 'a' && size - count >= size / 2)
		|| (mode == 'b' && size - count < size / 2) || (i + 1 == maxbits))
	{
		while (*(stacks->b))
			push(stacks->a, stacks->b, 'a');
	}
	else
	{
		while (*(stacks->a))
			push(stacks->a, stacks->b, 'b');
	}
}
