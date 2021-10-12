#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_tolower, letter_tolower)
{
	int 	src = 'A';
	int 	res = 'a';

	int 	res_real = ft_tolower(src);
	cr_assert_eq(res_real, res);
}

Test(test_tolower, non_letter_tolower)
{
	int 	src = '3';
	int 	res = '3';

	int 	res_real = ft_tolower(src);
	cr_assert_eq(res_real, res);
}
