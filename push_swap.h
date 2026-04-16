#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_config
{
	char			*strategy;
	char			*chosen;
	int				bench_mode;
	int				op_count;
	int				count_only;
	int				cnt_sa;
	int				cnt_sb;
	int				cnt_ss;
	int				cnt_pa;
	int				cnt_pb;
	int				cnt_ra;
	int				cnt_rb;
	int				cnt_rr;
	int				cnt_rra;
	int				cnt_rrb;
	int				cnt_rrr;
}					t_config;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack				*new_node(int value);
void				push_front(t_stack **stack, t_stack *node);
t_stack				*pop_front(t_stack **stack);
int					stack_size(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
void				free_stack(t_stack **stack);
int					is_sorted(t_stack *stack);
void				reverse_stack(t_stack **stack);
void				normalize_stack(t_stack *stack);
void				sa(t_stack **a, t_config *cfg);
void				sb(t_stack **b, t_config *cfg);
void				ss(t_stack **a, t_stack **b, t_config *cfg);
void				pa(t_stack **a, t_stack **b, t_config *cfg);
void				pb(t_stack **a, t_stack **b, t_config *cfg);
void				ra(t_stack **a, t_config *cfg);
void				rb(t_stack **b, t_config *cfg);
void				rr(t_stack **a, t_stack **b, t_config *cfg);
void				rra(t_stack **a, t_config *cfg);
void				rrb(t_stack **b, t_config *cfg);
void				rrr(t_stack **a, t_stack **b, t_config *cfg);
void				error_exit(t_stack **a, t_stack **b);
void				parse_args(int argc, char **argv, t_stack **a,
						t_config *config);
double				compute_disorder(t_stack *a);
void				sort_simple(t_stack **a, t_stack **b, t_config *cfg);
void				sort_medium(t_stack **a, t_stack **b, t_config *cfg);
void				sort_complex(t_stack **a, t_stack **b, t_config *cfg);
void				sort_adaptive(t_stack **a, t_stack **b, t_config *cfg);
int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_parse_int(const char *str, int *result, t_stack **a);
void				print_bench(t_config *cfg, double disorder);
int					is_duplicate(t_stack *a, int val);
int					ft_sqrt(int n);
int					find_max_pos(t_stack *stack);
int					find_min_pos(t_stack *stack);

#endif