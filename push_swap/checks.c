/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:06:44 by earutiun          #+#    #+#             */
/*   Updated: 2025/03/19 15:06:49 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define intmax "2147483647"
#define intmin "-2147483648"

static int checkoverflow(char *num);
static int checkmax(char *num, int len);
static int checkmin(char *num, int len);
static int checkduplicates(int size, char *stack[], char *num);

int    checkinput(int argc, char *argv[])
{
    int i;
    int j;

    if (argc < 2)
        errorexit(-1);
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (!ft_isdigit(argv[i][j]))
                errorexit(-1);
            j++;
        }
        if (!checkoverflow(argv[i]))
            errorexit(-1);
        if (!checkduplicates(argc, argv, argv[i]))
            errorexit(-1);
        i++;
    }
    return (1);
}

static int checkoverflow(char *num)
{
    int len;

    len = ft_strlen(num);
    if (num[0] != '-')
    {
        if (!checkmax(num, len))
            return (0);
    }
    else
    {
        if (!checkmin(num, len))
            return (0);
    }
    return (1);
}

static int checkmax(char *num, int len)
{
    int i;

    if (len > 10)
            return (0);
    else if(len == 10)
    {
        i = 0;
        while (i < 10)
        {
            if (num[i] > intmax[i])
                return (0);
            i++;
        }
    }
    return (1);
}

static int checkmin(char *num, int len)
{
    int i;

    if (len > 11)
            return (0);
    else if (len == 11)
    {
        i = 1;
        while (i < 11)
        {
            if (num[i] > intmin[i])
                return (0);
            i++;
        }
    }
    return (1);
}

static int checkduplicates(int size, char *stack[], char *num)
{
    int i;
    int matches;
    int len1;
    int len2;
    int lenmax;

    len1 = ft_strlen(num);
    matches = 0;
    i = 1;
    while (i < size)
    {
        len2 = ft_strlen(stack[i]);
        if (len1 >= len2)
            lenmax = len1;
        else
            lenmax = len2;
        if (!ft_strncmp(num, stack[i], lenmax))
            matches++;
        if (matches > 1)
            return (0);
        i++;
    }
    return (1);
}
