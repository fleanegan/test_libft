#include <criterion/criterion.h>
#include <bsd/string.h>
#include "../src/libft.h"

Test(test_strlcat, appending_an_empty_string_to_an_emptystring)
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

Test(test_strlcat, appending_an_empty_string_to_a_string_bigger_than_size)
{
	char	*src = "";
	char	dest_own[] = "a";
	//char	dest_orig[3] = "a";

	size_t	ret_own = ft_strlcat(dest_own, src, 1);
	//size_t	ret_orig = strlcat(dest_orig, src, 1);

	cr_assert_eq(ret_own, 1, "The result was %d. Expected %d", 1, (int) ret_own);
	//cr_assert_eq(ret_orig, ret_own);
}

// src: "12345" && 		app ""			&&			size = 5		->		ret = 5		src = "12345"
// src: "123" 	&& 		app ""			&&			size = 5		->		ret = 3		src = "123\0"
// src: "" 		&& 		app "12345"		&&			size = 5		->		ret = 5		src = "1234\0"
// src: "123" 	&& 		app "45"		&&			size = 5		->		ret = 5		src = "1234\0"

