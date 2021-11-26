#include "test_utils.h"

Test(test_lstadd_front, next_of_new_is_old)
{
	t_list *old = ft_lstnew(NULL);
	t_list *lst_pointer = old;
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_front(&lst_pointer, new);

	cr_assert_eq(new->next, old);
}

Test(test_lstadd_front, old_is_second_after_add_front)
{
	t_list *old = ft_lstnew(NULL);
	t_list *lst_pointer = old;
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_front(&lst_pointer, new);

	cr_assert_eq(new, lst_pointer);
}