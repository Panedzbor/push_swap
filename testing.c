/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:13:53 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/25 16:13:57 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_result(t_stack *afirst)
{
	int		fd;
	t_stack	*current;
	char	*num_str;

	if (!afirst)
		return ;
	fd = open("../result.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	current = afirst;
	while (1)
	{
		num_str = ft_itoa(current->x);
		if (num_str)
		{
			write(fd, num_str, ft_strlen(num_str));
			free(num_str);
			if (current->next != afirst)
				write(fd, " ", 1);
		}
		current = current->next;
		if (current == afirst)
			break ;
	}
	close(fd);
}
