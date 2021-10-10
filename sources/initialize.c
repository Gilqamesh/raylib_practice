#include "demo.h"

void	initialize_mystruct(t_mystruct *mystruct, char *mapPath)
{
	ft_bzero(mystruct, sizeof(*mystruct));
	parse_map(mystruct, mapPath);
	init_envItems(mystruct);
	init_player(mystruct);
	init_camera(mystruct);
	InitWindow(S_WIDTH, S_HEIGHT, W_TITLE);
	SetTargetFPS(60);
	load_images(mystruct);
}

void	init_envItems(t_mystruct *mystruct)
{
	for (int y = 0; y < mystruct->map.height; y++)
	{
		int	cur_len = ft_strlen(mystruct->map.map[y]);
		for (int x = 0; x < cur_len; x++)
		{
			if (mystruct->map.map[y][x] == C_WALL)
				ft_lstadd_front(&mystruct->envItems, ft_lstnew(createEnvItem
				((Rectangle){x * grid_size, y * grid_size, grid_size, grid_size}, 1, COLOR_WALL)));
		}
	}
}

void	init_player(t_mystruct *mystruct)
{
	for (int y = 0; y < mystruct->map.height; y++)
	{
		int	cur_len = ft_strlen(mystruct->map.map[y]);
		for (int x = 0; x < cur_len; x++)
		{
			if (mystruct->map.map[y][x] == C_PLAYER)
				mystruct->player.initPlayer.position = (Vector2){(x + 0.5) * grid_size,
					y * grid_size};
		}
	}
	mystruct->player.initPlayer.speed = PLAYER_INIT_SPD;
	mystruct->player.initPlayer.canJump = false;
	mystruct->player.curPlayer = mystruct->player.initPlayer;
}

void	init_camera(t_mystruct *mystruct)
{
	mystruct->camera.initCamera.target = mystruct->player.initPlayer.position;
	mystruct->camera.initCamera.offset = (Vector2){ S_WIDTH / 2.0f, S_HEIGHT / 2.0f };
	mystruct->camera.initCamera.rotation = CAMERA_ROTATE_INIT;
	mystruct->camera.initCamera.zoom = CAMERA_ZOOM_INIT;
	mystruct->camera.curCamera = mystruct->camera.initCamera;
}
