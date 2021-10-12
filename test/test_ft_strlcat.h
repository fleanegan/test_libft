#include <criterion/criterion.h>
#include <bsd/string.h>
#include "../src/libft.h"
#include "test_utils.h"

Test(test_strlcat, appending_an_empty_src_to_an_empty_dest_does_nothing_and_returns_zero)
{
	char	*src = "";
	char	dest_own[2] = "";
	char	dest_orig[2] = "";

	size_t	ret_own = ft_strlcat(dest_own, src, 2);
	size_t	ret_orig = strlcat(dest_orig, src, 2);

	cr_assert_eq(dest_own[0], 0);
	cr_assert_eq(ret_own, 0);
	cr_assert_eq(ret_orig, ret_own);
}

Test(test_strlcat, appending_an_empty_src_to_a_dest_bigger_than_size_does_nothing_and_returns_size)
{
	char	*src = "";
	char	dest_own[3] = "ai";
	char	dest_orig[3] = "ai";

	size_t	ret_own = ft_strlcat(dest_own, src, 1);
	size_t	ret_orig = strlcat(dest_orig, src, 1);

	cr_assert_eq(ret_own, 1, "The result was %d. Expected %d", 1, (int) ret_own);
	cr_assert_eq(ret_orig, ret_own);
}

Test(test_strlcat, appending_an_empty_src_to_a_dest_smaller_than_size_does_nothing_and_returns_len_of_dest)
{
	char	*src = "";
	char	dest_own[3] = "ai";
	char	dest_orig[3] = "ai";

	size_t	ret_own = ft_strlcat(dest_own, src, 3);
	size_t	ret_orig = strlcat(dest_orig, src, 3);

	cr_assert_eq(ret_own, 2, "The result was %d. Expected %d", 2, (int) ret_own);
	cr_assert_eq(ret_orig, ret_own);
}

Test(test_strlcat, appending_a_src_to_a_dest_smaller_than_size_appends_src_to_dest_and_returns_total_len)
{
	char	*src = "b";
	char	dest_own[3] = "a";
	char	dest_orig[3] = "a";

	size_t	ret_own = ft_strlcat(dest_own, src, 3);
	size_t	ret_orig = strlcat(dest_orig, src, 3);

	cr_assert_eq(ret_own, 2, "The result was %d. Expected %d", (int) ret_own, 2);
	cr_assert_eq(ret_own, ret_orig);
	cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, appending_a_src_bigger_than_size_to_an_empty_dest_appends_a_truncated_src_to_dest_and_returns_succeeded_len)
{
	char	*src = "ab";
	char	dest_own[2] = {0, 0};
	char	dest_orig[2] = {0, 0};

	size_t	ret_own = ft_strlcat(dest_own, src, 2);
	size_t	ret_orig = strlcat(dest_orig, src, 2);

	cr_assert_eq(ret_own, 2, "The result was %d. Expected %d", (int) ret_own, 2);
	cr_assert_eq(ret_own, ret_orig);
	cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, appending_a_src_to_a_dest_in_sum_bigger_than_size_appends_a_truncated_src_to_dest_and_returns_succeeded_len) {
	char *src = "bc";
	char dest_own[3] = {'a', 0, 0};
	char dest_orig[3] = {'a', 0, 0};

	size_t ret_own = ft_strlcat(dest_own, src, 3);
	size_t ret_orig = strlcat(dest_orig, src, 3);

	cr_assert_eq(ret_own, 3, "the result was %d. expected %d", (int) ret_own, 3);
	cr_assert_eq(ret_own, ret_orig, "expected %d", (int) ret_orig);
	cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, appending_a_src_to_a_dest_in_sum_smaller_than_size_appends_a_non_truncated_src_to_dest_and_returns_succeeded_len) {
char *src = "bc";
char dest_own[4] = {'a', 0, 0, 0};
char dest_orig[4] = {'a', 0, 0, 0};

size_t ret_own = ft_strlcat(dest_own, src, 4);
size_t ret_orig = strlcat(dest_orig, src, 4);

cr_assert_eq(ret_own, 3, "the result was %d. expected %d", (int) ret_own, 3);
cr_assert_eq(ret_own, ret_orig, "expected %d", (int) ret_orig);
cr_assert_str_eq(dest_own, dest_orig);
}

typedef struct strcat_obj
{
	char 	*src;
	char 	*dst_own;
	char 	*dst_orig;
	size_t	size_parameter;
} *strcat_obj_ptr;

int calc_dst_memory(size_t src_len_var, size_t dst_len_var) {
	return (int) src_len_var + (int) dst_len_var + SPACE_FOR_TERMINATING_CHAR;
}

void allocate_test_object_memory(size_t src_len_var, size_t dst_len_var, strcat_obj_ptr result) {
	result->src = (char *) malloc(sizeof(char) * src_len_var);
	result->dst_orig = (char *) malloc(sizeof(char) * calc_dst_memory(src_len_var, dst_len_var));
	result->dst_own = (char *) malloc(sizeof(char) * calc_dst_memory(src_len_var, dst_len_var));
}

void zero_init_test_object_memory(size_t src_len_var, size_t dst_len_var, strcat_obj_ptr result) {
	zero_array(result->dst_own, calc_dst_memory(src_len_var, dst_len_var));
	zero_array(result->dst_orig, calc_dst_memory(src_len_var, dst_len_var));
	zero_array(result->src, src_len_var);
}

void fill_test_object_data(const char *rand_string_dst, const char *rand_string_src, size_t src_len_var,
					  size_t dst_len_var, size_t size_var, strcat_obj_ptr result) {
	result->size_parameter = size_var;
	strlcpy(result->src, rand_string_src, src_len_var + SPACE_FOR_TERMINATING_CHAR);
	strlcpy(result->dst_own, rand_string_dst, dst_len_var + SPACE_FOR_TERMINATING_CHAR);
	strlcpy(result->dst_orig, rand_string_dst, dst_len_var + SPACE_FOR_TERMINATING_CHAR);
}

strcat_obj_ptr populate_one_test_object(const char *rand_string_dst, const char *rand_string_src,
										size_t src_len_var, size_t dst_len_var, size_t size_var) {
	strcat_obj_ptr result = (strcat_obj_ptr) malloc(sizeof(struct strcat_obj));
	allocate_test_object_memory(src_len_var, dst_len_var, result);
	zero_init_test_object_memory(src_len_var, dst_len_var, result);
	fill_test_object_data(rand_string_dst, rand_string_src, src_len_var, dst_len_var, size_var, result);
	return result;
}

strcat_obj_ptr generate_test_strings(size_t max_length)
{
	size_t	dst_max_length = max_length * 2 + SPACE_FOR_TERMINATING_CHAR;
	char 	*rand_string_dst = generate_random_string(max_length);
	char 	*rand_string_src = generate_random_string(max_length);
	int 	ctr = 0;
	int 	test_permutation_count = (int) ((max_length + SPACE_FOR_TERMINATING_CHAR) *
											(max_length + SPACE_FOR_TERMINATING_CHAR) *
											(dst_max_length + 2) + SPACE_FOR_TERMINATING_CHAR);
	strcat_obj_ptr result = (strcat_obj_ptr) malloc(sizeof(struct strcat_obj) * test_permutation_count);

	for (size_t src_len_var = 0; src_len_var < max_length + SPACE_FOR_TERMINATING_CHAR; src_len_var++) {
		for (size_t dst_len_var = 0; dst_len_var < max_length + SPACE_FOR_TERMINATING_CHAR; dst_len_var++) {
			for (size_t size_var = 0; size_var < dst_max_length + SPACE_FOR_TERMINATING_CHAR + 1; size_var++) {
				result[ctr] = *populate_one_test_object(rand_string_dst, rand_string_src, src_len_var, dst_len_var, size_var);
				ctr++;
			}
		}
		result[ctr].src = NULL;
	}
	return result;
}

Test(test_strlcat, brute_force)
{
	strcat_obj_ptr result = generate_test_strings(3);
	while (result->src) {
		size_t ret_own = ft_strlcat(result->dst_own, result->src, result->size_parameter);
		size_t ret_orig = strlcat(result->dst_orig, result->src, result->size_parameter);

		//printf("src %s, dst %s, size %d\n ", result->src, result->dst_own, (int) result->size_parameter);

		cr_expect_eq(ret_own, ret_orig);
		cr_expect_str_eq(result->dst_own, result->dst_orig, "own: %s \n act: %s", result->dst_own, result->dst_orig);
		result++;
	}
}