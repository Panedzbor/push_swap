

#include "push_swap.h"

void record_result(t_stack *Afirst)
{
    int fd;
    t_stack *current;
    char *num_str;
    
    if (!Afirst)
        return;
    fd = open("../result.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return;
    current = Afirst;
    while (1)
    {
        num_str = ft_itoa(current->x);
        if (num_str)
        {
            write(fd, num_str, ft_strlen(num_str));
            free(num_str);
            if (current->next != Afirst)
                write(fd, " ", 1);
        }
        current = current->next;
        if (current == Afirst)
            break;
    }
    close(fd);
}