#include "demo.h"

static void	unload_img_text(t_img_text img_text)
{
	UnloadTexture(img_text.texture);
	UnloadImage(img_text.img);
}

void	destroy_mystruct(t_mystruct *mystruct)
{
	for (int i = 0; i < mystruct->map.height; i++)
		free(mystruct->map.map[i]);
	free(mystruct->map.map);
	ft_lstclear(&mystruct->envItems, ft_lstdel);
	unload_img_text(mystruct->textures.player);
	unload_img_text(mystruct->textures.sand0);
	unload_img_text(mystruct->textures.empty);
	unload_img_text(mystruct->textures.background);
	ft_bzero(mystruct, sizeof(*mystruct));
}
