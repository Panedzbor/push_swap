void    radixsort(t_stack **Afirst, t_stack **Bfirst, unsigned int size)
{
    unsigned int    maxbits;
    unsigned int    i;
    unsigned int    j;
    unsigned int count = 0;
    unsigned int count2;
    char mode;
    t_stack         *cur;

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
                    {push(Afirst, Bfirst, 'b');count++;}
                else
                {
                    cur = *Afirst;
                    count2 = 0;
                    while (((cur->p >> i) & 1) != 0)
                    {
                        cur = cur->next;
                        count2++;
                        if (cur == *Afirst)
                            break ;
                    }
                    if (count2 <= (size - count) / 2)
                        rotate(Afirst, Bfirst, 'a');
                    else
                    {
                        unsigned int k = 0;
                        while (k < size - count - count2)
                        {
                            rev_rotate(Afirst, Bfirst, 'a');
                            k++;
                        }
                        j += count2 - 1;
                    }
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
                    {push(Afirst, Bfirst, 'a');count++;}
                else
                {
                    cur = *Bfirst;
                    count2 = 0;
                    while (((cur->p >> i) & 1) != 1)
                    {
                        cur = cur->next;
                        count2++;
                        if (cur == *Bfirst)
                            break ;
                    }
                    if (count2 <= (size - count) / 2)
                        rotate(Afirst, Bfirst, 'b');
                    else
                    {
                        unsigned int k = 0;
                        while (k < size - count - count2)
                        {
                            rev_rotate(Afirst, Bfirst, 'b');///!!!!!
                            k++;
                        }
                        j += count2 - 1;
                    }   
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



