#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_atoi, empty_string) {
	char *in = "";
	int exp_res = atoi(in);

	int res = ft_atoi(in);

	cr_assert_eq(exp_res, res, "expected: %d , real: %d", exp_res, res);
}

Test(test_atoi, invalid_input) {
	char *in = "j";
	int exp_res = atoi(in);

	int res = ft_atoi(in);
	
	cr_assert_eq(exp_res, res, "expected: %d , real: %d", exp_res, res);
}

Test(test_atoi, signle_digit_input) {
	char *in = "1";
	int exp_res = atoi(in);

	int res = ft_atoi(in);
	
	cr_assert_eq(exp_res, res, "expected: %d , real: %d", exp_res, res);
}

Test(test_atoi, signle_digit_input_with_signs) {
	char *in1 = "-1";
	int exp_res1 = atoi(in1);
	int res1 = ft_atoi(in1);
	char *in2 = "+1";
	int exp_res2 = atoi(in2);
	int res2 = ft_atoi(in2);

	cr_assert_eq(exp_res1, res1, "expected: %d , real: %d", exp_res1, res1);
	cr_assert_eq(exp_res2, res2, "expected: %d , real: %d", exp_res2, res2);
}

Test(test_atoi, whitespaces_at_begining) {
	char *in1 = "	 -1";
	int exp_res1 = atoi(in1);

	int res1 = ft_atoi(in1);

	cr_assert_eq(exp_res1, res1, "expected: %d , real: %d", exp_res1, res1);
}

Test(test_atoi, multiple_digits) {
	char *in1 = "123";
	int exp_res1 = atoi(in1);

	int res1 = ft_atoi(in1);

	cr_assert_eq(exp_res1, res1, "expected: %d , real: %d", exp_res1, res1);
}

Test(test_atoi, overflow_with_normal_int) {
	char *in1 = "-2147483648";
	long exp_res1 = atoi(in1);

	long res1 = ft_atoi(in1);

	cr_assert_eq(exp_res1, res1);//, "expected: %d , real: %d", exp_res1, res1);
}

Test(test_atoi, undefined_behavior) {
	char *in1 = "-21474836481";
	int exp_res1 = atoi(in1);

	int res1 = ft_atoi(in1);

	cr_assert_eq(exp_res1, res1);//, "expected: %d , real: %d", exp_res1, res1);
}



// what else !?