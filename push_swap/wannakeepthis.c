/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wannakeepthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:17:47 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/19 15:17:50 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void    printstacks(t_stack *Afirst, t_stack *Bfirst)
{
    t_stack *temp = Afirst;
    printf("A: ");
    if (Afirst)
    {
        while (temp->next != Afirst)
        {
            printf("%d ", temp->p);
            temp = temp->next;
        }
        printf("%d", temp->p);
    }
    printf("\n");
    temp = Bfirst;
    printf("B: ");
    if (Bfirst)
    {
        while (temp->next != Bfirst)
        {
            printf("%d ", temp->p);
            temp = temp->next;
        }
        printf("%d", temp->p);
    }
    printf("\n");fflush(stdout);
}

void    bubblesort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    unsigned int    i;
    unsigned int    j;
    unsigned int    k;

    i = 1;
    while (i < size)
    {
        j = 0;
        while (j < size - i)
        {
            if ((*Afirst)->x > (*Afirst)->next->x)
                s(Afirst, Bfirst, 'a');
            rotate(Afirst, Bfirst, 'a');
            j++;
        }
        k = i;
        while (k > 0)
        {
            rotate(Afirst, Bfirst, 'a');
            k--;
        }
        i++;
    }
}

void    minsort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    unsigned int    i;
    unsigned int    count;
    t_stack         *cur;

    i = 1;
    while (i < size)
    {
        cur = *Afirst;
        count = 0;
        while (cur->p != i)
        {
            cur = cur->next;
            count++;
        }
        while ((*Afirst)->p != i)
        {
            if ((size - count) >= size / 2)
                rotate(Afirst, Bfirst, 'a');
            else
                rev_rotate(Afirst, Bfirst, 'a');
        }
        push(Afirst, Bfirst, 'b');
        i++;
    }
    while (*Bfirst)
        push(Afirst, Bfirst, 'a');
}
*/
