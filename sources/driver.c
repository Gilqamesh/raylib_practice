#include "../headers/demo.h"
// #include "demo.h"

int	main(int argc, char **argv)
{
	t_mystruct	mystruct;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "usage: ./gui_demo <map_path>\n");
		return (1);
	}
	ft_bzero(&mystruct, sizeof(mystruct));
	parse_map(&mystruct, argv[1]);
	load_images(&mystruct);
	InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
	SetTargetFPS(60);
	draw_background(&mystruct);
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		draw_map(&mystruct);
		EndDrawing();
	}
	CloseWindow();
	destroy_mystruct(&mystruct);
	return (0);
}
