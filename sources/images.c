#include "demo.h"

static void	load_and_resize(t_img_text *img_text, char *imagePath,
Vector2 width_height)
{
	// PRINT_HERE();
	img_text->img = LoadImage(imagePath);
	// PRINT_HERE();
	img_text->resizedImg = ImageCopy(img_text->img);
	ImageResize(&img_text->resizedImg, width_height.x, width_height.y);
	// PRINT_HERE();
	printf("%p", img_text->resizedImg.data);
	img_text->texture = LoadTextureFromImage(img_text->resizedImg);
	// PRINT_HERE();
}

void	load_images(t_mystruct *mystruct)
{
	// PRINT_HERE();
	load_and_resize(&mystruct->textures.player,
		"assets/theboy/Idle (1).png", (Vector2){grid_size, grid_size});
	// PRINT_HERE();
	load_and_resize(&mystruct->textures.sand0,
		"assets/tiles/png/Tiles/5.png", (Vector2){grid_size, grid_size});
	// PRINT_HERE();
	load_and_resize(&mystruct->textures.empty,
		"assets/tiles/png/Tiles/18.png", (Vector2){grid_size, grid_size});
	load_and_resize(&mystruct->textures.background,
		"assets/tiles/png/BG/BG.png", (Vector2){W_WIDTH, W_HEIGHT});
}
