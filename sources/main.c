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
	initialize_mystruct(&mystruct, argv[1]);
	while (WindowShouldClose() == false)
	{
		update_delta(&mystruct);
		update_player(&mystruct);
		update_camera(&mystruct);
		BeginDrawing();
			ClearBackground(RAYWHITE);
			draw_background(&mystruct);
			BeginMode2D(mystruct.camera.curCamera);
				draw_map(&mystruct);
			EndMode2D();
			draw_gui(&mystruct);
		EndDrawing();
	}
	CloseWindow();
	destroy_mystruct(&mystruct);
	return (0);
}
