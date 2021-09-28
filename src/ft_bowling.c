#include <stddef.h>

#define TRUE 1
#define FALSE 0

int	roll_count = 0;
int history[21];
int	valid = TRUE;

void init()
{
	for (int i = 0; i < 21; i++)
		history[i] = 0;
}

void	roll(int knocked_pins)
{
	if (roll_count >= 21) {
		valid = FALSE;
		return ;
	}
	history[roll_count] = knocked_pins;
	roll_count++;
}

// 5 5
// 15

// 5 5   1
// 10+1  1

int score(void)
{
	int total_score = 0;

	if (!valid)
		return (-1);
	for (roll_count = 0; roll_count < 21; roll_count++)
	{
		if (roll_count % 2 && history[roll_count - 1] + history[roll_count] == 10)
			total_score += history[roll_count + 1];
		total_score += history[roll_count];
	}
	return total_score;
}