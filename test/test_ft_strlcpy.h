#include <criterion/criterion.h>
#include <bsd/string.h>
#include "../src/libft.h"

Test(test_strlcpy, copy_empty_string)
{
	char	*src = "";
	int 	buf_size = ft_strlen(src) + 1;
	char	dest[] = {1};

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, 0);
}

Test(test_strlcpy, copy_one_char_string)
{
	char	*src = "1";
	int 	buf_size = ft_strlen(src) + 1;
	char	dest[] = {1};

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], '1');
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, 1);
}

Test(test_strlcpy, copy_two_char_string)
{
	char	*src = "12";
	int 	buf_size = ft_strlen(src) + 1;
	char	dest[buf_size];

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], '1');
	cr_assert_eq(dest[1], '2');
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, 2);
}

Test(test_strlcpy, copy_only_if_within_buf_size)
{
	char	*src = "1";
	int 	buf_size = 1;
	char	dest[buf_size];

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], 0);
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, 0);
}

Test(test_strlcpy, copy_empty_source)
{
	char	*src = "";
	int 	buf_size = 3;
	char	dest[4] = "abc";

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], 0);
	cr_assert_eq(ret_val, 0);
}
