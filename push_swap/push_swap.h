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

typedef struct s_stack
{
    int             x;
    int    p;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

typedef struct s_stks
{
    t_stack **A;
    t_stack **B;
} t_stks;

void    radixsort(t_stks *stacks, int size);
void    s(t_stack **Afirst, t_stack **Bfirst, char mode);
void    push(t_stack **Afirst, t_stack **Bfirst, char mode);
void    rotate(t_stack **Afirst, t_stack **Bfirst, char mode);
void    rev_rotate(t_stack **Afirst, t_stack **Bfirst, char mode);
int     checkinput(int argc, char *argv[]);
#endif
