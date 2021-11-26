#include "test_utils.h"

Test(test_ft_lstget_element_by_index, get_element_zero)
{
	t_list	*first = ft_lstnew(NULL);

	t_list	*res_act = ft_lstget_element_by_index(first, 0);
	cr_assert_eq(res_act, first);
}

Test(test_ft_lstget_element_by_index, get_element_one)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*second = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	t_list	*res_act = ft_lstget_element_by_index(first, 1);
	cr_assert_eq(res_act, second);
}

Test(test_ft_lstget_element_by_index, if_id_out_of_range_return_NULL)
{
	t_list	*first = ft_lstnew(NULL);

	t_list	*res_act = ft_lstget_element_by_index(first, 1);
	cr_assert_null(res_act);
}