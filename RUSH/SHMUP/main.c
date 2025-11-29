#include "ft_shmup.h"

int main()
{
	//initialize ncurses
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	//starting position of the players
	int p1_x = (MAP_WIDTH * 3) / 4;
	int p1_y = MAP_HEIGHT - 2;
	int	p2_x = MAP_WIDTH / 4;
	int p2_y = MAP_HEIGHT - 2;

	//initialize bullet list to NULL for each player
	bullet *p1_bullets = NULL;
	bullet *p2_bullets = NULL;
	bullet *enemy_bullets = NULL;
	enemy *enemies = NULL;
	
	long prev_enemy_move = 0;
	long prev_enemy_shoot = 0;
	long prev_enemy_spawn = 0;

	while (1)
	{
		long now = clock();
		clear();
		int ch = getch();

		//option to quit with 'q'
		if (ch == 'q')
			break;
		
		//taking the movement/shooting input for player1
		if (ch == KEY_LEFT)
			p1_x--;
		if (ch == KEY_RIGHT)
			p1_x++;
		if (ch == KEY_UP)
			p1_y--;
		if (ch == KEY_DOWN)
			p1_y++;
		if (ch == '\n')
			add_bullet(&p1_bullets, p1_x, p1_y - 1);
		
		//taking the movement/shooting input for player2
		if (ch == 'a')
			p2_x--;
		if (ch == 'd')
			p2_x++;
		if (ch == 'w')
			p2_y--;
		if (ch == 's')
			p2_y++;
		if (ch == '\t')
			add_bullet(&p2_bullets, p2_x, p2_y - 1);

		//ensure player doesn´t go beyond the map
		if (p1_x < 1)
			p1_x = 1;
		if (p1_x > MAP_WIDTH - 1)
			p1_x = MAP_WIDTH - 1;
		if (p1_y < 1)
			p1_y = 1;
		if (p1_y > MAP_HEIGHT - 2)
			p1_y = MAP_HEIGHT - 2;
		
		if (p2_x < 1)
			p2_x = 0;
		if (p2_x > MAP_WIDTH - 1)
			p2_x = MAP_WIDTH - 1;
		if (p2_y < 1)
			p2_y = 0;
		if (p2_y > MAP_HEIGHT - 2)
			p2_y = MAP_HEIGHT - 2;

		//enemy moving and shooting every 0.5 / 0.2 sec + enemy spawning
		if (now - prev_enemy_move >= CLOCKS_PER_SEC * 0.05)
		{
			update_enemy(enemies);
			prev_enemy_move = now;
		}
		if (now - prev_enemy_shoot >= CLOCKS_PER_SEC * 0.02)
		{
			while (enemies)
			{
				add_bullet(&enemy_bullets, enemies->x, enemies->y + 1);
				enemies = enemies->next;
			}
			prev_enemy_shoot = now;
		}
		if (count_enemy(enemies) < MAX_ENEMY)
		{
			add_enemy(&enemies);
			prev_enemy_spawn = now;
		}
		
		//update the bullets according to the recieved inputs
		update_player_bullet(&p1_bullets);
		update_player_bullet(&p2_bullets);
		update_enemy_bullet(&enemy_bullets);

		//display border
		put_border();

		//display players/enemies and their bullets
		mvaddch(p1_y, p1_x, 'A');
		mvaddch(p2_y, p2_x, 'B');
		display_enemy(enemies);
		display_bullet(p1_bullets);
		display_bullet(p2_bullets);
		display_bullet(enemy_bullets);

		refresh();
		usleep(50000);
	}
	endwin();
	return 0;
}