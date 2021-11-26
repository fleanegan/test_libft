#include "test_utils.h"

Test(test_trim, trimmed_empty_string_stays_empty_string)
{
	char	*src = "";
	char	*set = "";
	char	*res_exp = "";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_trim, trim_string_with_only_leading_chars)
{
	char	*src = ".....a";
	char	*set = ".";
	char	*res_exp = "a";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_trim, trim_string_with_only_trailing_chars)
{
	char	*src = "a.....";
	char	*set = ".";
	char	*res_exp = "a";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_trim, trim_string_with_leading_and_trailing_chars)
{
	char	*src = "..a.....";
	char	*set = ".";
	char	*res_exp = "a";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_trim, trimmable_chars_in_middle_stay)
{
	char	*src = ".a.a.";
	char	*set = ".";
	char	*res_exp = "a.a";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_trim, trim_complex_string)
{
	char	*src = ".|.a.a.|.";
	char	*set = ".|";
	char	*res_exp = "a.a";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_trim, pure_space)
{
	char	*src = "......";
	char	*set = ".|";
	char	*res_exp = "";

	char 	*res_act = ft_strtrim(src, set);
	cr_assert_str_eq(res_act, res_exp);
}
