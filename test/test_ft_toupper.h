#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_toupper, single_letter_toupper)
{
	char 	src[] = "a";
	char 	res[] = "A";

	char 	*res_real = ft_toupper((char *) &src);
	cr_assert_arr_eq(res_real, res, sizeof(char));
}

Test(test_toupper, two_letter_toupper)
{
	char 	src[] = "ab";
	char 	res[] = "AB";

	char 	*res_real = ft_toupper((char *) &src);
	cr_assert_str_eq(res_real, res);
}

Test(test_toupper, two_letter_toupper_with_one_digit)
{
	char 	src[] = "a9b";
	char 	res[] = "A9B";

	char 	*res_real = ft_toupper((char *) &src);
	cr_assert_str_eq(res_real, res);
}
