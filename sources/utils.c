#include "demo.h"

/*
** Allocates and returns an EnvItem pointer.
*/
EnvItem	*createEnvItem(Rectangle rect, int blocking, Color color)
{
	EnvItem	*newEnvItem = malloc(sizeof(*newEnvItem));

	if (newEnvItem == NULL)
		return (NULL);
	newEnvItem->rect = rect;
	newEnvItem->blocking = blocking;
	newEnvItem->color = color;
	return (newEnvItem);
}
