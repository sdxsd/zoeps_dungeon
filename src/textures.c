#include "../includes/system-killer.h"

int	load_textures(game_data *game) {
	game->images.plyr = LoadImage("assets/plyr.png");
	game->images.wll = LoadImage("assets/flr.png");
	game->images.flr = LoadImage("assets/wll.png");
	ImageResize(&game->images.plyr, TEX_SIZE, TEX_SIZE);
	ImageResize(&game->images.wll, TEX_SIZE, TEX_SIZE);
	ImageResize(&game->images.flr, TEX_SIZE, TEX_SIZE);
	return (TRUE);
}
