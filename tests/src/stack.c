#include "stack.h"
#include "libft.h"
#include "libtests.h"

#define SIZE 42

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

int		main(void)
{
    test_init_stack();
	return (0);
}
