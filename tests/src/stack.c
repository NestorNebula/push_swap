#include "stack.h"
#include "parse.h"
#include "libft.h"
#include "libtests.h"

#define SIZE 5
#define ARGS (const char *[]){"1", "2", "3", "4", "5"}
#define REV_ARGS (const char *[]){"5", "4", "3", "2", "1"}
#define INT_TO_PUSH 42

void	test_init_stack(void)
{
    int		errors;
    t_stack	*stack;

    errors = 0;
    stack = init_stack(SIZE);
    errors += expect_not_null(stack, "init_stack (returns a new stack)");
    errors += expect_not_null(stack->content,
		"init_stack (inits stack's content)");
    errors += expect_eq_int(stack->size, SIZE,
		"init_stack (sets stack's size to the given size)");
    errors += expect_eq_int(stack->top, 0,
		"init_stack (sets stack's top to 0)");
    errors += expect_eq_int(stack->bottom, 0,
		"init_stack (sets stack's bottom to 0)");
    free_stack(stack);
    if (errors == 0)
        ft_printf("\ninit_stack: Success\n");
}

void	test_push_stack(void)
{
	int		errors;
	t_stack	*stack;

	errors = 0;
	stack = init_stack(SIZE);
	errors += expect_not_null(stack, "push_stack (stack initialization error)");
	(void) parse_args(ARGS, SIZE, stack);
	push_stack(stack, INT_TO_PUSH);
	errors += expect_eq_int(get_stack_len(stack), SIZE,
		"push_stack (does nothing when stack is full)");
	errors += expect_eq_int(stack->content[stack->top - 1], 1,
		"push_stack (left integer at the top unchanged on failed push)");
	stack->top--;
	push_stack(stack, INT_TO_PUSH);
	errors += expect_eq_int(get_stack_len(stack), SIZE,
		"push_stack (update stack top position on successful push)");
	errors += expect_eq_int(stack->content[stack->top - 1], INT_TO_PUSH,
		"push_stack (push expected integer to stack)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\npush_stack: Success\n");
}

void	test_pop_stack(void)
{
	int		errors;
	t_stack	*stack;
	size_t	i;

	errors = 0;
	stack = init_stack(SIZE);
	errors += expect_not_null(stack, "pop_stack (stack initialization error)");
	(void) parse_args(ARGS, SIZE, stack);
	i = 0;
	while (get_stack_len(stack) > 0)
	{
		errors += expect_eq_int(pop_stack(stack), ++i,
			"pop_stack (returns integer at the top of stack)");
		errors += expect_eq_int(stack->top, get_stack_len(stack),
			"pop_stack (updates stack top position on successful pop)");
	}
	(void) pop_stack(stack);
	errors += expect_eq_int(stack->top, 0, "pop_stack (does nothing on failed pop)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\npop_stack: Success\n");
}

void	test_get_stack_len(void)
{
	int		errors;
	t_stack	*stack;
	size_t	i;

	errors = 0;
	stack = init_stack(SIZE);
	errors += expect_not_null(stack,
		"get_stack_len (stack initialization error)");
	errors += expect_eq_int(get_stack_len(stack), 0,
		"get_stack_len (returns 0 when stack is empty)");
	(void) parse_args(ARGS, SIZE, stack);
	errors += expect_eq_int(get_stack_len(stack), SIZE,
		"get_stack_len (returns number of integers currently in the stack)");
	i = SIZE;
	while (i > 0)
	{
		(void) pop_stack(stack);
		errors += expect_eq_int(get_stack_len(stack), --i,
			"get_stack_len (returns correct value after successful pop)");
	}
	while (i < SIZE)
	{
		push_stack(stack, i + 1);
		errors += expect_eq_int(get_stack_len(stack), ++i,
			"get_stack_len (returns correct value after successful push)");
	}
	free_stack(stack);
	if (errors == 0)
		ft_printf("\nget_stack_len: Success\n");
}

void	test_is_sorted_stack(void)
{
	int		errors;
	t_stack	*stack;

	errors = 0;
	stack = init_stack(SIZE);
	errors += expect_not_null(stack,
		"is_sorted_stack (stack initialization error)");
	(void) parse_args(ARGS, SIZE, stack);
	errors += expect_true(is_sorted_stack(stack, true),
		"is_sorted_stack (returns true for sorted stack in ascending order)");
	errors += expect_false(is_sorted_stack(stack, false),
		"is_sorted_stack (returns false for unsorted stack in ascending order)");
	stack->content[stack->top - 1] += 2;
	errors += expect_false(is_sorted_stack(stack, true),
		"is_sorted_stack (returns false for unsorted stack in ascending order)");
	(void) parse_args(REV_ARGS, SIZE, stack);
	errors += expect_true(is_sorted_stack(stack, false),
		"is_sorted_stack (returns true for sorted stack in descending order)");
	errors += expect_false(is_sorted_stack(stack, true),
		"is_sorted_stack (returns false for unsorted stack in descending order)");
	stack->content[stack->top - 1] -= 2;
	errors += expect_false(is_sorted_stack(stack, false),
		"is_sorted_stack (returns false for unsorted stack in descending order)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\nis_sorted_stack: Success\n");
}

void	test_find_maximum_smaller(void)
{
	int		errors;
	t_stack	*stack;
	
	errors = 0;
	stack = init_stack(SIZE);
	expect_not_null(stack,
		"find_maximum_smaller (stack initialization error)");
	(void) parse_args(ARGS, SIZE, stack);
	errors += expect_eq_int(find_maximum_smaller(stack, SIZE), SIZE - 2,
		"find_maximum_smaller (returns index of the maximum smaller)");
	errors += expect_eq_int(find_maximum_smaller(stack, -1), SIZE - 1,
		"find_maximum_smaller (returns index of the maximum number when "
		"n is smaller than every number in the stack)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\nfind_maximum_smaller: Success\n");
}

void	test_find_minimum_bigger(void)
{
	int		errors;
	t_stack	*stack;
	
	errors = 0;
	stack = init_stack(SIZE);
	expect_not_null(stack,
		"find_minimum_bigger (stack initialization error)");
	(void) parse_args(ARGS, SIZE, stack);
	errors += expect_eq_int(find_minimum_bigger(stack, SIZE - 1), SIZE - 1,
		"find_minimum_bigger (returns index of the minimum bigger)");
	errors += expect_eq_int(find_minimum_bigger(stack, SIZE + 1), 0,
		"find_minimum_bigger (returns index of the minimum number when "
		"n is bigger than every number in the stack)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\nfind_minimum_bigger: Success\n");
}

void	test_gap_to_top(void)
{
	int		errors;
	t_stack	*stack;
	
	errors = 0;
	stack = init_stack(SIZE);
	expect_not_null(stack,
		"gap_to_top (stack initialization error)");
	(void) parse_args(ARGS, SIZE, stack);
	errors += expect_eq_int(gap_to_top(stack, SIZE - 2, false), 1,
		"gap_to_top (returns gap to top for index between top and bottom)");
	errors += expect_eq_int(gap_to_top(stack, SIZE - 2, true), 1,
		"gap_to_top (do not go down the stack when going up is faster)");
	errors += expect_eq_int(gap_to_top(stack, stack->bottom + 1, false), SIZE - 2,
		"gap_to_top (returns gap to top for index between top and bottom)");
	errors += expect_eq_int(gap_to_top(stack, stack->bottom + 1, true), -2,
		"gap_to_top (go down the stack when going up is longer)");
	errors += expect_eq_int(gap_to_top(stack, stack->bottom, false), SIZE - 1,
		"gap_to_top (returns gap to top for bottom)");
	errors += expect_eq_int(gap_to_top(stack, stack->bottom, true), -1,
		"gap_to_top (returns minus one for bottom when going down is allowed)");
	errors += expect_eq_int(gap_to_top(stack, stack->top - 1, false), 0,
		"gap_to_top (returns zero for element on top of stack)");
	errors += expect_eq_int(gap_to_top(stack, stack->top - 1, true), 0,
		"gap_to_top (returns zero for element on top of stack even when"
		"going down is allowed)");
	free_stack(stack);
	if (errors == 0)
		ft_printf("\ngap_to_top: Success\n");
}

int		main(void)
{
    test_init_stack();
	test_push_stack();
	test_pop_stack();
	test_get_stack_len();
	test_is_sorted_stack();
	test_find_maximum_smaller();
	test_find_minimum_bigger();
	test_gap_to_top();
	return (0);
}
