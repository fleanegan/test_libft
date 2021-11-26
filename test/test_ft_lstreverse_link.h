#include "test_utils.h"

Test(test_reverse_link, revert_one_link_lst)
{
	t_list	*first = ft_lstnew(NULL);

	t_list	*new = ft_lstreverse(first);
	cr_assert_eq(first, new);
}

Test(test_reverse_link, revert_two_link_lst)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*second = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	second = ft_lstreverse(first);
	cr_assert_eq(second->next, first);
	cr_assert_eq(first->next, NULL);
}

Test(test_reverse_link, revert_three_link_lst)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*second = ft_lstnew(NULL);
	t_list	*third = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);

	t_list *res_act = ft_lstreverse(first);

	cr_assert_eq(res_act, third);
	cr_assert_eq(res_act->next, second);
	cr_assert_eq(first->next, NULL);
}