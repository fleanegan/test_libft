#include "gossip.h"


t_driver	*create_driver(int *route, int route_size)
{
	static		int current_driver = 0;
	t_driver	*res = malloc(sizeof(t_driver));
	res->gossip_ids = (int *) malloc(sizeof(t_driver) * total_driver_count);
	for (int i = 0; i < total_driver_count; i++)
		res->gossip_ids[i] = 0;
	res->gossip_ids[current_driver++] = 1;
	res->route = (int *)malloc(sizeof(int) * route_size);
	for (int i = 0; i < route_size; i++)
		res->route[i] = route[i];
	res->route_size = route_size;
	return (res);
}

void	init(void)
{
	drivers = (t_driver *)calloc(total_driver_count, sizeof(t_driver));
	current_positions = (int *)calloc(total_driver_count, sizeof(int));
	turn = 0;
}

void	get_positions(int turn)
{
	t_driver	d;

	for (int i = 0; i < total_driver_count; i++)
	{
		d = drivers[i];
		current_positions[i] = d.route[turn % d.route_size];
	}
}

int		move(void)
{
	t_driver	d1;
	t_driver	d2;

	get_positions(turn++);
	for (int i = 0; i < total_driver_count; i++)
	{
		d1 = drivers[i];
		for (int j = i + 1; j < total_driver_count; j++)
		{
			d2 = drivers[j];
			if (current_positions[i] == current_positions[j])
				for (int g = 0; g < total_driver_count; g++)
					d1.gossip_ids[g] = d2.gossip_ids[g] = d1.gossip_ids[g] + d2.gossip_ids[g];
		}
	}
	if (is_finished())
		return (turn);
	if (lcm() == turn)
		return (-1);
	return (0);
}


int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return (a + b);
	return (gcd(b, a%b));
}

int lcm(void)
{
	int res = drivers[0].route_size;
	t_driver d;

	for (int i = 1; i < total_driver_count; i++)
	{
		d = drivers[i];
		res = (res * d.route_size) / gcd(res, d.route_size);
	}
	return (res);
}

int		is_finished(void)
{
	t_driver	d1;
	t_driver	d2;
	for (int i = 0; i < total_driver_count; i++)
	{
		d1 = drivers[i];
		for (int j = 0; j < total_driver_count; j++)
		{
			if (! d1.gossip_ids[j])
				return (0);
		}
	}
	return (1);
}