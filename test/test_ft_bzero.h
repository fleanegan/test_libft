#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_bzero, set_no_bits) {
	char 	dest_own[] = {69, 68};
	char 	exp_res[] = {69, 68};
	size_t	bit_count = 0;

	ft_bzero(&dest_own, bit_count);

	cr_assert_arr_eq(dest_own, exp_res, 2 * sizeof(char));
}

Test(test_bzero, set_one_byte) {
	char 	dest_own[] = {2};
	size_t	bit_count = 1;

	ft_bzero(&dest_own, bit_count);

	cr_assert_eq(dest_own[0], 0);
}

Test(test_bzero, set_two_bytes) {
	char 	dest_own[] = {69, 68};
	char 	exp_res[] = {0, 0};
	size_t	bit_count = 2;

	ft_bzero(&dest_own, bit_count);

	cr_assert_arr_eq(dest_own, exp_res, 2 * sizeof(char));
}

// what else !?