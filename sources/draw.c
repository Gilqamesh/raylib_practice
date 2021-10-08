#include "demo.h"

void	draw_map(t_mystruct *mystruct)
{
	for (int y = 0; y < mystruct->map.height; y++)
	{
		int	cur_len = ft_strlen(mystruct->map.map[y]);
		for (int x = 0; x < cur_len; x++)
		{
			printf("cur character: %c\n", mystruct->map.map[y][x]);
			Vector2	position = {x * grid_size, y * grid_size};
			switch (mystruct->map.map[y][x])
			{
				case 'p':
					ImageDrawPixelV(&mystruct->textures.player.img, position, RAYWHITE);
					// DrawTextureV(mystruct->textures.player.texture, position, RAYWHITE);
					break ;
				case '0':
					ImageDrawPixelV(&mystruct->textures.empty.img, position, RAYWHITE);
					// DrawTextureV(mystruct->textures.empty.texture, position, RAYWHITE);
					break ;
				case '1':
					ImageDrawPixelV(&mystruct->textures.sand0.img, position, RAYWHITE);
					// DrawTextureV(mystruct->textures.sand0.texture, position, RAYWHITE);
					break ;
				default:
					ImageDrawPixelV(&mystruct->textures.empty.img, position, RAYWHITE);
			}
		}
	}
}

void	draw_background(t_mystruct *mystruct)
{
	DrawTextureV(mystruct->textures.background.texture, (Vector2){0, 0}, RAYWHITE);
}
