/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:01:52 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/13 14:02:02 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_stack
{
	int				x;
	int				p;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				size;
}	t_stack;

typedef struct s_stks
{
	t_stack	**a;
	t_stack	**b;
}	t_stks;

void	radixsort(int size);
void	minsort(t_stack **afirst, t_stack **bfirst, int size);
void	s(t_stack **afirst, t_stack **bfirst, char mode);
void	push(t_stack **afirst, t_stack **bfirst, char mode);
void	rotate(t_stack **afirst, t_stack **bfirst, char mode);
void	rev_rotate(t_stack **afirst, t_stack **bfirst, char mode);
int		checkinput(int argc, char *argv[]);
int		check_if_sorted(int size, char *array[]);
int		countbits(int *maxbits, int size);
t_stks	*save_stacks(t_stks *stacks, t_stack **A, t_stack **B);
void	errorexit(int val);
void	check_recording_poss(t_stack *afirst);
void	record_result(t_stack *afirst);
#endif
