#ifndef FT_SHMUP_H
# define FT_SHMUP_H

// standard headers
# include <ncurses.h>

//standard headers
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//macros
#define MAP_WIDTH 60
#define MAP_HEIGHT 25
#define MAX_ENEMY 10

//structs
typedef	struct bullet{
	int x;
	int y;
	struct bullet *next;
}	bullet;

typedef struct enemy{
	int	x;
	int y;
	int	direc; // 1 = R, -1 = L
	struct enemy *next;
}	enemy;

//bullets.c
void add_bullet(bullet **lst, int x, int y);
void update_player_bullet(bullet **lst);
void update_enemy_bullet(bullet **lst);
void display_bullet(bullet *lst);

//enemy.c
void add_enemy(enemy **lst);
int  count_enemy(enemy *lst);
void update_enemy(enemy *lst);
void display_enemy(enemy *lst);

//utils.c
void put_border();

#endif
