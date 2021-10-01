typedef struct frame{
	int pins[3]; // {0,0,0} //{10,0,0} //{3,7,0} //{3,0,0} //{}
	int score;
} t_frame;

void roll(int knocked_pins);
int score(void);
void init(void);
