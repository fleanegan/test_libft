#include <criterion/criterion.h>
#include "../src/libft.h"
#include "test_utils.h"

Test(test_generate_random_strings, entered_length_is_correct)
{
	size_t 	len = 3;

	char	*random_string = generate_random_string(len);
	cr_assert_eq(ft_strlen(random_string), len);
}

Test(test_generate_random_strings, return_is_null_terminated)
{
	size_t 	len = 3;

	char	*random_string = generate_random_string(len);
	cr_assert_eq(random_string[3], 0);
}

Test(test_generate_random_strings, two_strings_do_not_equal)
{
	size_t 	len = 3;

	char	*random_string1 = generate_random_string(len);
	char	*random_string2 = generate_random_string(len);
	cr_assert_str_neq(random_string1, random_string2);
}

Test(test_generate_random_strings, all_chars_are_printable)
{
	size_t 	len = 300;

	char	*random_string = generate_random_string(len);
	for (size_t i = 0; i < len; i++)
		cr_assert(ft_isprint(random_string[i]), "char is: %i", random_string[i]);
}
