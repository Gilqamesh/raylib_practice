#include "demo.h"

static void	update_camera_zoom(t_mystruct *mystruct)
{
	mystruct->camera.curCamera.zoom += GetMouseWheelMove() * 0.05f;
	if (mystruct->camera.curCamera.zoom > 3.0f)
		mystruct->camera.curCamera.zoom = 3.0f;
	else if (mystruct->camera.curCamera.zoom < 0.25f)
		mystruct->camera.curCamera.zoom = 0.25f;
	if (IsKeyPressed(RESET_KEY))
	{
		mystruct->camera.curCamera = mystruct->camera.initCamera;
		mystruct->player.curPlayer = mystruct->player.initPlayer;
	}
}

static void	update_camera_offset(t_mystruct *mystruct)
{
	mystruct->camera.curCamera.offset = (Vector2){ S_WIDTH / 2.0f, S_HEIGHT / 2.0f };
}

static void	update_camera_rotation(t_mystruct *mystruct)
{
	if (IsKeyDown(CAMERA_ROTATE_LEFT))
		mystruct->camera.curCamera.rotation--;
	else if (IsKeyDown(CAMERA_ROTATE_RIGHT))
		mystruct->camera.curCamera.rotation++;

	if (mystruct->camera.curCamera.rotation > 40)
		mystruct->camera.curCamera.rotation = 40;
	else if (mystruct->camera.curCamera.rotation < -40)
		mystruct->camera.curCamera.rotation = -40;
}

static void	update_camera_target(t_mystruct *mystruct)
{
	mystruct->camera.curCamera.target = mystruct->player.curPlayer.position;
}

void	update_camera(t_mystruct *mystruct)
{
	update_camera_zoom(mystruct);
	update_camera_offset(mystruct);
	update_camera_rotation(mystruct);
	update_camera_target(mystruct);
}

void	update_player(t_mystruct *mystruct)
{
	if (IsKeyDown(LEFT_MOVEMENT))
		mystruct->player.curPlayer.position.x -= PLAYER_HOR_SPD * mystruct->delta.time;
	if (IsKeyDown(RIGHT_MOVEMENT))
		mystruct->player.curPlayer.position.x += PLAYER_HOR_SPD * mystruct->delta.time;
	if (IsKeyDown(JUMP_KEY))
	{
		mystruct->player.curPlayer.speed = -PLAYER_JUMP_SPD;
		mystruct->player.curPlayer.canJump = false;
	}
	int hitObstacle = 0;
	t_list	*curEnvItem = mystruct->envItems;
	while (curEnvItem)
	{
		EnvItem	*ei = (EnvItem *)curEnvItem->content;
		Vector2 *p = &mystruct->player.curPlayer.position;
		if (ei->blocking && ei->rect.x <= p->x
			&& ei->rect.x + ei->rect.width >= p->x && ei->rect.y >= p->y
			&& ei->rect.y < p->y + mystruct->player.curPlayer.speed * mystruct->delta.time)
		{
			hitObstacle = 1;
			mystruct->player.curPlayer.speed = 0.0f;
			p->y = ei->rect.y;
		}
		curEnvItem = curEnvItem->next;
	}
	if (!hitObstacle)
	{
		mystruct->player.curPlayer.position.y
			+= mystruct->player.curPlayer.speed * mystruct->delta.time;
		mystruct->player.curPlayer.speed += G * mystruct->delta.time;
		mystruct->player.curPlayer.canJump = false;
	}
	else
		mystruct->player.curPlayer.canJump = true;
}

void	update_delta(t_mystruct *mystruct)
{
	mystruct->delta.time = GetFrameTime();
	mystruct->delta.scrollingBack -= 0.1f;
	mystruct->delta.scrollingMid -= 0.5f;
	mystruct->delta.scrollingFore -= 1.0f;

	if (mystruct->delta.scrollingBack <= -mystruct->textures.background.texture.width)
		mystruct->delta.scrollingBack = 0;
	if (mystruct->delta.scrollingMid <= -mystruct->textures.midground.texture.width)
		mystruct->delta.scrollingMid = 0;
	if (mystruct->delta.scrollingFore <= -mystruct->textures.foreground.texture.width)
		mystruct->delta.scrollingFore = 0;
}
