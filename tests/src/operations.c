#include <stdlib.h>
#include "libft.h"
#include "libtests.h"
#include "parse.h"
#include "stack.h"
#include "operations.h"


#define SIZE 5
#define ARGS (const char *[]){"1", "2", "3", "4", "5"}

t_stack	*init_test_stack(const char *test)
{
	t_stack	*stack;

	stack = init_stack(SIZE);
	(void) expect_not_null(stack, test);
	(void) parse_args(ARGS, SIZE, stack);
	return (stack);
}

void	test_op_swap(void)
{
	int		errors;
	t_stack	*stack;
	int		tops[2];

	errors = 0;
	stack = init_test_stack("op_swap (stack initialization error)");
	tops[0] = stack->content[stack->top - 1];
	tops[1] = stack->content[stack->top - 2];
	op_swap(stack);
	errors += expect_eq_int(stack->content[stack->top - 1], tops[1],
		"op_swap (sets second element to the top of the stack)");
	errors += expect_eq_int(stack->content[stack->top - 2], tops[0],
		"op_swap (sets first element below second one in the stack)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\nop_swap: Success\n");
}

void	test_op_push(void)
{
	int		errors;
	int		expected;
	t_stack	*src_stack;
	t_stack	*dest_stack;

	errors = 0;
	src_stack = init_test_stack("op_push (stack initialization error)");
	dest_stack = init_test_stack("op_push(stack initialization error)");
	dest_stack->content[dest_stack->top - 1]--;
	expected = dest_stack->content[dest_stack->top - 1];
	op_push(src_stack, dest_stack);
	errors += expect_eq_int(dest_stack->content[dest_stack->top - 1], expected,
		"op_push (does nothing when dest_stack is full)");
	free_stack(src_stack);
	free_stack(dest_stack);
}

int	main(void)
{
	return (0);
}
