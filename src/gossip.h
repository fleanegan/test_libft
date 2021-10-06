#ifndef GOSSIP_H
# define GOSSIP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_driver
{
	int *gossip_ids;
	int *route;
	int route_size;

} t_driver;

t_driver	*create_driver(int *route, int route_size);
int		move(void);
void		get_positions(int turn);
void		init(void);
int		is_finished(void);

int	total_driver_count;
t_driver	*drivers;
int			*current_positions;
int			turn;
int			lcm(void);

#endif // GOSSIP_H