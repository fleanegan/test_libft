#include <criterion/criterion.h>

Test(test_memcpy, cpy_no_bits_if_byte_number_is_zero) {
	char 	src[] = {69};
	char 	dest[] = {0};
	char 	exp_res[1];
	size_t	n = 0;

	ft_memcpy(dest, src, n);
	memcpy(exp_res, src, n);

	cr_assert_arr_eq(dest, exp_res, 1 * sizeof(char));
}

Test(test_memcpy, returns_pointer) {
	char 	src[] = {69};
	char 	dest[] = {0};
	size_t	n = 0;

	char 	*own_ptr = ft_memcpy(&dest, src, n);
	char 	*orig_ptr = memcpy(&dest, src, n);

	cr_assert_eq(*own_ptr, *orig_ptr);
}

Test(test_memcpy, cpy_one_byte) {
	char 	src[] = {69};
	char 	dest[] = {0};
	char 	exp_res[1];
	size_t	n = 1;

	ft_memcpy(dest, src, n);
	memcpy(exp_res, src, n);

	cr_assert_arr_eq(dest, exp_res, 1 * sizeof(char));
}

Test(test_memcpy, set_two_bytes) {
	char 	src[] = {69, 68};
	char 	dest[] = {0, 0};
	char 	exp_res[2];
	size_t	n = 2;

	ft_memcpy(dest, src, n);
	memcpy(exp_res, src, n);

	cr_assert_arr_eq(dest, exp_res, 2 * sizeof(char));
}

#ifdef own_source


#endif

// what else !?