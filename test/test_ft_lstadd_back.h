#include "test_utils.h"

Test(test_lstadd_back, next_of_first_element_is_new_if_list_only_one_element)
{
	t_list *first = ft_lstnew(NULL);
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_back(&first, new);

	cr_assert_eq(first->next, new);
}

Test(test_lstadd_back, next_of_first_element_stays_second_if_list_has_multiple_elements)
{
	t_list *first = ft_lstnew(NULL);
	t_list *second = ft_lstnew(NULL);
	t_list *new = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	ft_lstadd_back(&first, new);

	cr_assert_eq(first->next, second);
}

Test(test_lstadd_back, last_element_is_new)
{
	t_list *first = ft_lstnew(NULL);
	t_list *second = ft_lstnew(NULL);
	t_list *new = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	ft_lstadd_back(&first, new);

	cr_assert_eq(second->next, new);
}