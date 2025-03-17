/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:22:35 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/13 13:22:41 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** *//////////////////////

#include "push_swap.h"

int checkpush(t_stack *first, int val, unsigned int size, unsigned int pos);

void    bubblesort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
  //  t_stack         *constfirst;
    unsigned int    i;
    unsigned int    j;
    unsigned int    k;

//    constfirst = *Afirst;
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

void    radixsort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    unsigned int    maxbits;
    unsigned int    i;
    unsigned int    j;
    unsigned int count = 0;
    char mode;


    maxbits = 0;
    i = size;
    mode = 'a';
    while (i > 0)
    {
        maxbits++;
        i >>= 1;
    }
    while (i < maxbits)
    {
        j = 0; count = 0;
        if (*Afirst)
        {
            mode = 'a';
            while (j < size)
            {
                if ((((*Afirst)->p >> i) & 1) == 0)
                {
                    if (!checkpush(*Afirst, 0, size, j) && !*Bfirst)
                        break ;
                    push(Afirst, Bfirst, 'b');
                    count++;
                }
                else
                {
                        rotate(Afirst, Bfirst, 'a');
                }
                j++;
            }
        }
        else
        {
            mode = 'b';
            while (j < size)
            {
                if ((((*Bfirst)->p >> i) & 1) == 1)
                {
                    if (!checkpush(*Bfirst, 1, size, j) && !*Afirst)
                        break ;
                    push(Afirst, Bfirst, 'a');
                    count++;
                }
                else
                {
                        rotate(Afirst, Bfirst, 'b'); 
                }
                j++;
            }
        }
        if ((mode == 'a' && size - count >= size / 2) || (mode == 'b' && size - count < size / 2) || (i + 1 == maxbits))
        {
            while (*Bfirst)
                push(Afirst, Bfirst, 'a');
        }
        else
        {
            while (*Afirst)
                push(Afirst, Bfirst, 'b');
        }
        i++;
    }
}

void printstacks(t_stack *Afirst, t_stack *Bfirst)
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

int checkpush(t_stack *first, int val, unsigned int size, unsigned int pos)
{
    //unsigned int    i;
    t_stack         *curr;
    bool            flag;

    curr = first;
    /* i = 0;
    while (i <= pos)
    {
        curr = curr->next;
        i++;
    } */
    flag = true;
    while (pos < size)
    {
        if ((((curr->p >> pos) & 1) == (unsigned int)val) && !flag)
            return (1);
        if (((curr->p >> pos) & 1) != (unsigned int)val)
            flag = false;
        curr = curr->next;
        pos++;
    }
    return (0);
}

void    turksort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    //if 3 or less => go with another algorythm
    unsigned int    i;
    unsigned int    count;
    t_stack         *cur;

    i = 1;
    while (i < size)
    {
        push(Afirst, Bfirst, 'b');
        i++;
    } 
}

//cycle through each num in A
//count steps to bring to top
//count steps to rotate B
//if rotation is in same direction, deduct the smaller amount from sum of rotations
//+push
//push the cheapest
//stop
