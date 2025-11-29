#include "ft_shmup.h"

//function to add bullet to list
void add_bullet(bullet **lst, int x, int y)
{
	bullet *b;

	b = malloc(sizeof(bullet));
	if (!b)
	{
		//function to clear whole list;
		return ;
	}
	b->x = x;
	b->y = y;
	b->next = *lst;
	*lst = b;
}

//update player bullet
void update_player_bullet(bullet **lst)
{
	bullet *prev = NULL;
	bullet *cur = *lst;

	while (cur)
	{
		cur->y--;
		if (cur->y < 0) //if (current bullet reaches the top wall)
		{
			if (prev)
				prev->next = cur->next;
			else
				*lst = cur->next;
			bullet *tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

//update enemy bullet
void update_enemy_bullet(bullet **lst)
{
	bullet *prev = NULL;
	bullet *cur = *lst;

	while (cur)
	{
		cur->y++;
		if (cur->y < 0) //if (current bullet reaches the top wall)
		{
			if (prev)
				prev->next = cur->next;
			else
				*lst = cur->next;
			bullet *tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

//display the bullets on screen
void display_bullet(bullet *lst)
{
	while (lst)
	{
		mvaddch(lst->y, lst->x, '|');
		lst = lst->next;
	}
}