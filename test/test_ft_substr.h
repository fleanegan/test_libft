#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_substr, letter_tolower)
{
	int 	src = 'A';
	int 	res = 'a';

	int 	res_real = ft_tolower(src);
	cr_assert_eq(res_real, res);
}
