#include <criterion/criterion.h>
#include <unistd.h>
#include "../src/gossip.h"

Test(test_gossip, get_positions)
{
	total_driver_count = 2;
	init();
	int	route_a[1] = {1};
	int route_b[1] = {1};
	t_driver	*driver_a;
	t_driver	*driver_b;
	driver_a = create_driver(route_a, 1);
	driver_b = create_driver(route_b, 1);
	int expected_positions[] = {1, 1};
	drivers[0] = *driver_a;
	drivers[1] = *driver_b;

	get_positions(0);
	cr_assert_arr_eq(current_positions, expected_positions, sizeof(int) * 1);
}

Test(test_gossip, one_move, .disabled = false) {
	total_driver_count = 2;
	init();
	int	route_a[1] = {1};
	int route_b[1] = {1};
	t_driver	*driver_a;
	t_driver	*driver_b;
	driver_a = create_driver(route_a, 1);
	driver_b = create_driver(route_b, 1);
	int expected_positions[] = {1, 1};
	drivers[0] = *driver_a;
	drivers[1] = *driver_b;

	cr_assert_eq(move(), 1);
	cr_assert_eq(driver_a->gossip_ids[1], 1);
	cr_assert_eq(driver_b->gossip_ids[0], 1);
}

Test(test_gossip, two_moves, .disabled = false) {
	total_driver_count = 2;
	init();
	int	route_a[2] = {1, 3};
	int route_b[2] = {2, 3};
	t_driver	*driver_a;
	t_driver	*driver_b;
	driver_a = create_driver(route_a, 2);
	driver_b = create_driver(route_b, 2);
	int expected_positions[] = {1, 1};
	drivers[0] = *driver_a;
	drivers[1] = *driver_b;

	cr_assert_eq(move(), 0);
	cr_assert_eq(move(), 2);
}

Test(test_gossip, no_solution, .disabled = false) {
	total_driver_count = 2;
	init();
	int	route_a[2] = {1, 3};
	int route_b[2] = {2, 4};
	t_driver	*driver_a;
	t_driver	*driver_b;
	driver_a = create_driver(route_a, 2);
	driver_b = create_driver(route_b, 2);
	int expected_positions[] = {1, 1};
	drivers[0] = *driver_a;
	drivers[1] = *driver_b;

	cr_assert_eq(move(), 0);
	cr_assert_eq(move(), -1);
	
}

// 