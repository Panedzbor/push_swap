/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/25 15:59:20 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*removefromlist(t_stack **list);
t_stack	*removefromlist2(t_stack **list);
void	addtolist(t_stack **list, t_stack *temp);

void	push(t_stack **Afirst, t_stack **Bfirst, char mode)
{
	t_stack	*temp;
	char	buf[4];

	if (mode == 'a')
	{
		temp = removefromlist(Bfirst);
		addtolist(Afirst, temp);
	}
	else if (mode == 'b')
	{
		temp = removefromlist(Afirst);
		addtolist(Bfirst, temp);
	}
	buf[0] = 'p';
	buf[1] = mode;
	buf[2] = '\n';
	buf[3] = '\0';
	write(1, buf, 3);
}

t_stack	*removefromlist(t_stack **list)
{
	t_stack	*temp;

	temp = NULL;
	if (!*list)
		return (temp);
	if (*list == (*list)->next)
	{
		temp = *list;
		*list = NULL;
	}
	else if ((*list)->next == (*list)->prev)
	{
		temp = *list;
		*list = (*list)->next;
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else
		temp = removefromlist2(list);
	return (temp);
}

t_stack	*removefromlist2(t_stack **list)
{
	t_stack	*last;
	t_stack	*b;
	t_stack	*temp;

	last = (*list)->prev;
	b = (*list)->next;
	last->next = b;
	b->prev = last;
	(*list)->prev = *list;
	(*list)->next = *list;
	temp = *list;
	*list = b;
	return (temp);
}

void	addtolist(t_stack **list, t_stack *temp)
{
	if (!*list)
	{
		*list = temp;
		return ;
	}
	if (*list == (*list)->next)
	{
		(*list)->next = temp;
		(*list)->prev = temp;
		temp->next = *list;
		temp->prev = *list;
		*list = temp;
		return ;
	}
	temp->next = *list;
	temp->prev = (*list)->prev;
	(*list)->prev->next = temp;
	(*list)->prev = temp;
	*list = temp;
}
