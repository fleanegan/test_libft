#include <stddef.h>

int	roll_count = 0;
int history[21];

void init()
{
	for (int i = 0; i < 21; i++)
		history[i] = 0;
}

void	roll(int knocked_pins)
{
	history[roll_count] = knocked_pins;
	roll_count++;
}

int score(void)
{
	int total_score;
	for (roll_count = 0; roll_count < 21; roll_count++)
		total_score += history[roll_count];
	return total_score;
}