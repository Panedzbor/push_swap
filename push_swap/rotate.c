/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/25 16:06:45 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **afirst, t_stack **bfirst, char mode)
{
	char	buf[4];

	if (mode == 'a')
	{
		if (*afirst)
			*afirst = (*afirst)->next;
	}
	else if (mode == 'b')
	{
		if (*bfirst)
			*bfirst = (*bfirst)->next;
	}
	else if (mode == 'r')
	{
		if (*afirst)
			*afirst = (*afirst)->next;
		if (*bfirst)
			*bfirst = (*bfirst)->next;
	}
	buf[0] = 'r';
	buf[1] = mode;
	buf[2] = '\n';
	buf[3] = '\0';
	write(1, buf, 3);
}

void	rev_rotate(t_stack **afirst, t_stack **bfirst, char mode)
{
	char	buf[5];

	if (mode == 'a')
	{
		if (*afirst)
			*afirst = (*afirst)->prev;
	}
	else if (mode == 'b')
	{
		if (*bfirst)
			*bfirst = (*bfirst)->prev;
	}
	else if (mode == 'r')
	{
		if (*afirst)
			*afirst = (*afirst)->prev;
		if (*bfirst)
			*bfirst = (*bfirst)->prev;
	}
	buf[0] = 'r';
	buf[1] = 'r';
	buf[2] = mode;
	buf[3] = '\n';
	buf[4] = '\0';
	write(1, buf, 4);
}
