#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_tolower, single_letter_tolower)
{
	char 	src[] = "A";
	char 	res[] = "a";

	char 	*res_real = ft_tolower((char *) &src);
	cr_assert_arr_eq(res_real, res, sizeof(char));
}

Test(test_tolower, two_letter_tolower)
{
	char 	src[] = "aB";
	char 	res[] = "ab";

	char 	*res_real = ft_tolower((char *) &src);
	cr_assert_str_eq(res_real, res);
}

Test(test_tolower, two_letter_tolower_with_one_digit)
{
	char 	src[] = "A9B";
	char 	res[] = "a9b";

	char 	*res_real = ft_tolower((char *) &src);
	cr_assert_str_eq(res_real, res);
}
