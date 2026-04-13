#include "push_swap.h"

/*
** ft_strlen — string uzunluğu
** Kullanım: argüman kontrolünde boş string tespiti için
*/
int     ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

/*
** ft_strncmp — iki string'i n karaktere kadar karşılaştır
** Kullanım: --simple, --medium, --complex, --adaptive flag kontrolü
*/
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

/*
** ft_putchar_fd — tek karakter yaz
** Kullanım: ft_putstr_fd'nin temel yapı taşı
*/
void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

/*
** ft_putstr_fd — string yaz (belirli fd'ye)
** Kullanım: error_exit() içinde "Error\n" → stderr (fd=2)
**           checker bonus'unda "OK\n" / "KO\n" → stdout (fd=1)
*/
void    ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return ;
    while (*s)
        ft_putchar_fd(*s++, fd);
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
        if (val * sign > INT_MAX || val * sign < INT_MIN)
            error_exit(a, NULL);
        i++;
    }
    if (str[i] != '\0')
        error_exit(a, NULL);
    *result = (int)(val * sign);
}