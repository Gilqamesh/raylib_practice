#include "demo.h"

void	draw_map(t_mystruct *mystruct)
{
	t_list	*envItems = mystruct->envItems;

	while (envItems)
	{
		EnvItem	*curEnvItem = (EnvItem *)envItems->content;
		DrawTextureV(mystruct->textures.sand0.texture, (Vector2){
			curEnvItem->rect.x, curEnvItem->rect.y
		}, RAYWHITE);
		envItems = envItems->next;
	}
	DrawTextureV(mystruct->textures.player.texture, (Vector2){
		mystruct->player.curPlayer.position.x - grid_size / 2.0,
		mystruct->player.curPlayer.position.y - grid_size
	}, RAYWHITE);
}

void	draw_background(t_mystruct *mystruct)
{
	// DrawTextureV(mystruct->textures.background.texture, (Vector2){0, 0}, RAYWHITE);
	DrawTextureEx(mystruct->textures.background.texture,
		(Vector2){mystruct->delta.scrollingBack, 0}, 0.0f, 1.0f, WHITE);
	DrawTextureEx(mystruct->textures.background.texture,
		(Vector2){mystruct->textures.background.texture.width + mystruct->delta.scrollingBack, 0}, 0.0f, 1.0f, WHITE);

	DrawTextureEx(mystruct->textures.midground.texture,
		(Vector2){mystruct->delta.scrollingMid, 0}, 0.0f, 1.0f, WHITE);
	DrawTextureEx(mystruct->textures.midground.texture,
		(Vector2){mystruct->textures.midground.texture.width + mystruct->delta.scrollingMid, 0}, 0.0f, 1.0f, WHITE);

	DrawTextureEx(mystruct->textures.foreground.texture,
		(Vector2){mystruct->delta.scrollingFore, 0}, 0.0f, 1.0f, WHITE);
	DrawTextureEx(mystruct->textures.foreground.texture,
		(Vector2){mystruct->textures.foreground.texture.width + mystruct->delta.scrollingFore, 0}, 0.0f, 1.0f, WHITE);
}

void	draw_abilities(t_mystruct *mystruct)
{
	int	maxSide = ft_maxofint(S_WIDTH, S_HEIGHT);
	Vector2	boxSize = { maxSide / 20, maxSide / 20 };
	DrawRectangleV((Vector2){ S_WIDTH / 2.0 - grid_size * 2, S_HEIGHT - maxSide / 20 }, boxSize, GRAY);
	DrawRectangleV((Vector2){ S_WIDTH / 2.0 - grid_size, S_HEIGHT - maxSide / 20 }, boxSize, GRAY);
	DrawRectangleV((Vector2){ S_WIDTH / 2.0 + grid_size, S_HEIGHT - maxSide / 20}, boxSize, GRAY);
	DrawRectangleV((Vector2){ S_WIDTH / 2.0 + grid_size * 2, S_HEIGHT - maxSide / 20 }, boxSize, GRAY);
}

void	draw_minimap(t_mystruct *mystruct)
{
	int	minimap_size = 3 * grid_size;
	DrawRectangleLinesEx((Rectangle){S_WIDTH - 2.5 * minimap_size, 0, 2.45 * minimap_size, 1.5 * minimap_size}, 2.0f, BLACK);
	DrawEllipseLines(S_WIDTH - minimap_size, minimap_size / 1.5, minimap_size / 1.1, minimap_size / 1.65, GRAY);
	DrawCircleGradient(S_WIDTH - 2.2 * minimap_size, minimap_size * 0.4, minimap_size / 4.0, RED,  MAROON);
	DrawCircleGradient(S_WIDTH - 2.2 * minimap_size, minimap_size * 0.9, minimap_size / 4.0, BLUE,  DARKBLUE);
}

void	draw_menubar(t_mystruct *mystruct)
{
	int	minimap_size = 3 * grid_size;
	DrawRectangleV((Vector2){S_WIDTH - 2.5 * minimap_size, 1.6 * minimap_size},
		(Vector2){2.45 * minimap_size, S_HEIGHT - 1.7 * minimap_size}, LIGHTGRAY);
}

void	draw_gui(t_mystruct *mystruct)
{
	// draw_abilities(mystruct);
	// draw_minimap(mystruct);
	// draw_menubar(mystruct);
	DrawTextureV(mystruct->textures.gui.texture, (Vector2){0, 0}, RAYWHITE);
}