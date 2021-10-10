#include "demo.h"

static void	load_and_resize(t_img_text *img_text, char *imagePath,
Vector2 width_height)
{
	img_text->img = LoadImage(imagePath);
	ImageResize(&img_text->img, width_height.x, width_height.y);
	img_text->texture = LoadTextureFromImage(img_text->img);
}

void	load_images(t_mystruct *mystruct)
{
	load_and_resize(&mystruct->textures.player,
		"assets/theboy/Idle (1).png", (Vector2){grid_size, grid_size});
	load_and_resize(&mystruct->textures.sand0,
		"assets/tiles/png/Tiles/5.png", (Vector2){grid_size, grid_size});
	load_and_resize(&mystruct->textures.empty,
		"assets/tiles/png/Tiles/18.png", (Vector2){grid_size, grid_size});
	load_and_resize(&mystruct->textures.background,
		"assets/tiles/png/BG/BG.png", (Vector2){S_WIDTH, S_HEIGHT});
	// load_and_resize(&mystruct->textures.gui,
	// 	"assets/gui/tom_gui.png", (Vector2){S_WIDTH, S_HEIGHT});
	load_and_resize(&mystruct->textures.gui,
		"assets/gui/jzhou_gui.png", (Vector2){S_WIDTH, S_HEIGHT});
	load_and_resize(&mystruct->textures.midground,
		"assets/background/cyberpunk_street_midground.png", (Vector2){S_WIDTH, S_HEIGHT});
	load_and_resize(&mystruct->textures.foreground,
		"assets/background/cyberpunk_street_foreground.png", (Vector2){S_WIDTH, S_HEIGHT});
}