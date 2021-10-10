#ifndef STRUCTS_H
# define STRUCTS_H

# include "raylib.h"

typedef struct Player
{
	Vector2	position;
	float	speed;
	bool	canJump;
}	Player;

typedef struct EnvItem
{
	Rectangle	rect;
	int			blocking;
	Color		color;
}	EnvItem;

typedef struct s_img_text
{
	Image		img;
	Texture2D	texture;
}	t_img_text;

typedef struct s_textures
{
	t_img_text	player;
	t_img_text	sand0;
	t_img_text	empty;
	t_img_text	background;
	t_img_text	gui;
	t_img_text	midground;
	t_img_text	foreground;
}	t_textures;

typedef struct s_map
{
	char	**map;
	int		max_width;
	int		height;
}	t_map;

typedef struct s_player
{
	Player	initPlayer;
	Player	curPlayer;
}	t_player;

typedef struct s_camera
{
	Camera2D	initCamera;
	Camera2D	curCamera;
}	t_camera;

typedef struct s_delta_vars
{
	float	time;
	float	scrollingBack;
	float	scrollingMid;
	float	scrollingFore;
}	t_delta_vars;

typedef struct s_mystruct
{
	t_map			map;
	t_textures		textures;
	t_list			*envItems;
	t_player		player;
	t_camera		camera;
	t_delta_vars	delta;
}	t_mystruct;

#endif
