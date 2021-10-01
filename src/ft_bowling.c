#include "bowling.h"
#include <stddef.h>

#define TRUE 1
#define FALSE 0

int		roll_count = 0;
t_frame	history[10];
int		current_frame = 0;
int		valid = TRUE;

void init()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 3; j++)
			history->pins[j] = 0;
		history->score = 0;
}

int	end_frame(int pins[3])
{
	return (roll_count == 2 || pins[0] + pins[1] == 10);
}

void	roll(int knocked_pins)
{
	history[current_frame].pins[roll_count] = knocked_pins;
	if (end_frame(history[current_frame].pins))
	{
		current_frame++;
		roll_count = 0;
	}
	else
		roll_count++;
}

// 5 5
// 15

// 5 5   1
// 10+1  1

int score(void)
{
	int total_score = 0;
	
	for (int i = 0; i < 10; i++)
	{
		// curr frame
		if (is_spare()) // next roll
		else if (is_strike()) // next 2 rolls
	}
}