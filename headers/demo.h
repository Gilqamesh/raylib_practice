#ifndef DEMO_H
# define DEMO_H

# include <stdio.h>
# include <stdlib.h>
# include "raylib.h"
# include "../library/mylib/mylib.h"
# include <fcntl.h>

# define W_WIDTH 2000
# define W_HEIGHT 1200
# define W_TITLE "gui demo"
// debugging
# define PRINT_HERE() (printf("Line: %d, File: %s\n", __LINE__, __FILE__))

extern int grid_size;

typedef struct s_img_text
{
	Image		img;
	Image		resizedImg;
	Texture2D	texture;
}	t_img_text;

typedef struct s_textures
{
	t_img_text	player;
	t_img_text	sand0;
	t_img_text	empty;
	t_img_text	background;
}	t_textures;

typedef struct s_map
{
	char	**map;
	int		max_width;
	int		height;
}	t_map;

typedef struct s_mystruct
{
	t_map		map;
	t_textures	textures;
}	t_mystruct;

// Parsing functions
void	parse_map(t_mystruct *mystruct, char *mapPath);

// Initializing / Destroy functions
void	load_images(t_mystruct *mystruct);
void	destroy_mystruct(t_mystruct *mystruct);

// Drawing functions
void	draw_background(t_mystruct *mystruct);
void	draw_map(t_mystruct *mystruct);

#endif
