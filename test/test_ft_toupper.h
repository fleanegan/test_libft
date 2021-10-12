#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_toupper, letter_toupper)
{
	int 	src = 'a';
	int 	res = 'A';

	int 	res_real = ft_toupper(src);
	cr_assert_eq(res_real, res);
}

Test(test_toupper, non_letter_toupper)
{
	int 	src = '3';
	int 	res = '3';

	int 	res_real = ft_toupper(src);
	cr_assert_eq(res_real, res);
}
