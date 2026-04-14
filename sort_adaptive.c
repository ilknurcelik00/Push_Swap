#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b)
{
	double    disorder;

	if (stack_size(*a) <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
