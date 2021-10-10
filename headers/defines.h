#ifndef DEFINES_H
# define DEFINES_H

# define S_WIDTH 			2000
# define S_HEIGHT 			1200
# define W_TITLE 			"gui demo"
# define C_WALL 			'1'
# define C_PLAYER 			'P'
# define C_EMPTY			'0'
# define COLOR_WALL			GRAY
# define G					400
# define PLAYER_INIT_SPD	0
# define PLAYER_JUMP_SPD	350.0f
# define PLAYER_HOR_SPD		200.0f
# define CAMERA_ZOOM_INIT	1.0f
# define CAMERA_ROTATE_INIT	0.0f

// Controls
# define LEFT_MOVEMENT			KEY_LEFT
# define RIGHT_MOVEMENT			KEY_RIGHT
# define JUMP_KEY				KEY_SPACE
# define CAMERA_ROTATE_LEFT		KEY_A
# define CAMERA_ROTATE_RIGHT	KEY_S
# define RESET_KEY				KEY_R

// debugging
# define PRINT_HERE() (printf("Line: %d, File: %s\n", __LINE__, __FILE__))

#endif
