#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* Global op counter for count-only / bench mode */
extern int  g_op_count;
extern int  g_count_only;

/* Individual op counters for bench */
extern int  g_cnt_sa;
extern int  g_cnt_sb;
extern int  g_cnt_ss;
extern int  g_cnt_pa;
extern int  g_cnt_pb;
extern int  g_cnt_ra;
extern int  g_cnt_rb;
extern int  g_cnt_rr;
extern int  g_cnt_rra;
extern int  g_cnt_rrb;
extern int  g_cnt_rrr;

/* ---- Veri yapısı ---- */
typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *prev;
    struct s_stack  *next;
}   t_stack;

/* ---- Stack yardımcı ---- */
t_stack *new_node(int value);
void    push_front(t_stack **stack, t_stack *node);
t_stack *pop_front(t_stack **stack);
int     stack_size(t_stack *stack);
t_stack *stack_last(t_stack *stack);
void    free_stack(t_stack **stack);
int     is_sorted(t_stack *stack);
void    reverse_stack(t_stack **stack);
void    normalize_stack(t_stack *stack);

/* ---- Operasyonlar ---- */
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

/* ---- Parsing & hata ---- */
void    error_exit(t_stack **a, t_stack **b);
void    parse_args(int argc, char **argv, t_stack **a,
                    char **strategy, int *count_only, int *bench_mode);

/* ---- Algoritmalar ---- */
double  compute_disorder(t_stack *a);
void    sort_simple(t_stack **a, t_stack **b);
void    sort_medium(t_stack **a, t_stack **b);
void    sort_complex(t_stack **a, t_stack **b);
void    sort_adaptive(t_stack **a, t_stack **b);

/* ---- ft_utils ---- */
int     ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, int n);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_parse_int(const char *str, int *result, t_stack **a);

/* ---- Benchmark ---- */
void    print_bench(char *strategy, double disorder);

#endif
