#include "ft_shmup.h"

void put_border()
{
	int x = 0;
		while (x < MAP_WIDTH)
		{
			mvaddch(0, x, '-');
			mvaddch(MAP_HEIGHT - 1, x, '-');
			x++;
		}
		int y = 0;
		while (y < MAP_HEIGHT)
		{
			mvaddch(y, 0, '|');
			mvaddch(y, MAP_WIDTH, '|');
			y++;
		}
}