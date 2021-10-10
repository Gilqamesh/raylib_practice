#include "demo.h"

int grid_size = 0;

void	parse_map(t_mystruct *mystruct, char *mapPath)
{
	char	*line;
	int		fd;
	int		ret;

	if ((fd = open(mapPath, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (get_next_line(fd, &line) < 0)
			exit(EXIT_FAILURE);
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		mystruct->map.map = realloc(mystruct->map.map,
			++mystruct->map.height * sizeof(*mystruct->map.map));
		mystruct->map.map[mystruct->map.height - 1] = line;
		int	cur_len = ft_strlen(line);
		if (cur_len > mystruct->map.max_width)
			mystruct->map.max_width = cur_len;
	}
	grid_size = ft_maxofint(S_WIDTH, S_HEIGHT)
		/ ft_maxofint(mystruct->map.max_width, mystruct->map.height);
}
