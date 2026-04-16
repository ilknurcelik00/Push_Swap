#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b, t_config *cfg)
{
	double	disorder;

	if (stack_size(*a) <= 5)
	{
		cfg->chosen = "--simple";
		sort_simple(a, b, cfg);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		cfg->chosen = "--simple";
		sort_simple(a, b, cfg);
	}
	else if (disorder < 0.5)
	{
		cfg->chosen = "--medium";
		sort_medium(a, b, cfg);
	}
	else
	{
		cfg->chosen = "--complex";
		sort_complex(a, b, cfg);
	}
}
