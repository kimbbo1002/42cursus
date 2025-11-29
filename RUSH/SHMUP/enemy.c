#include "ft_shmup.h"

//function that adds enemy
void add_enemy(enemy **lst)
{
	enemy *e;

	e = malloc(sizeof(char));
	if (!e)
	{
		//function to clear whole list
		return ;
	}
	e->x = rand() % (MAP_WIDTH - 2) + 1;
	e->y = 1;
	if (rand() % 2)
		e->direc = 1;
	else
		e->direc = -1;
	e->next = *lst;
	*lst = e;
}

//counts how many enemies there are to not add more than MAX_ENEMY
int count_enemy(enemy *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void update_enemy(enemy *lst)
{
	while (lst)
	{
		lst->x += lst->direc * 2;
		if (lst->x <= 1)
			lst->direc = 1;
		if (lst->x >= MAP_WIDTH - 2)
			lst->direc = -1;
		lst = lst->next;
	}
}

void display_enemy(enemy *lst)
{
	while (lst)
	{
		mvaddch(lst->y, lst->x, 'V');
		lst = lst->next;
	}
}