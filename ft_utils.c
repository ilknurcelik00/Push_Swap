#include "push_swap.h"

int     ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     ft_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return ;
    while (*s)
        ft_putchar_fd(*s++, fd);
}

void    ft_putnbr_fd(int n, int fd)
{
    long    nb;
    char    c;

    nb = (long)n;
    if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr_fd((int)(nb / 10), fd);
    c = (char)(nb % 10 + '0');
    ft_putchar_fd(c, fd);
}

void    ft_parse_int(const char *str, int *result, t_stack **a)
{
    long    val;
    int     i;
    int     sign;

    i = 0;
    sign = 1;
    val = 0;
    if (!str || !str[i])
        error_exit(a, NULL);
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        error_exit(a, NULL);
    while (str[i] >= '0' && str[i] <= '9')
    {
        val = val * 10 + (str[i] - '0');
        if (sign == 1 && val > 2147483647)
            error_exit(a, NULL);
        if (sign == -1 && val > 2147483648L)
            error_exit(a, NULL);
        i++;
    }
    if (str[i] != '\0')
        error_exit(a, NULL);
    *result = (int)(val * sign);
}
