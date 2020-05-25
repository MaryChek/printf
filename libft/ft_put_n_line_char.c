#include "libft.h"

int 	ft_put_n_line_char(char const *s, int n)
{
    int i;

    i = 0;
	if (s && n > 0)
		while (*s && n--)
        {
            i++;
			ft_putchar_fd(*s++, 1);
        }
    return (i);
}