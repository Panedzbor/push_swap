/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:49:08 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/25 19:49:10 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(int size, char *array[])
{
	int	i;

	i = 2;
	while (i < size)
	{
		if (ft_atoi(array[i]) <= ft_atoi(array[i - 1]))
			return (0);
		i++;
	}
	return (1);
}
