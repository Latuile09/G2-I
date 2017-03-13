#include <SDL/SDL_image.h>
#include <assert.h>

#include <bomb.h>
#include <sprite.h>
#include <window.h>
#include <misc.h>
#include <constant.h>

struct bomb {
	int x,y;
	int range;
	int time;
	int active;
};

struct bomb* bomb_init(){
	struct bomb* bomb= malloc(sizeof(*bomb));
	if(!bomb)
		error("Memory Error");
// Initialisation is coming
	return bomb;
}

void bomb_free(struct bomb* bomb){
	assert(bomb);
	free(bomb);
}

void set_bomb_range(struct bomb* bomb,int range){
	assert(bomb);
	bomb->range=range;
}

void bomb_set_place_and_time(struct bomb* bomb,int range,int time,int x,int y){
	assert(bomb);
	bomb->x=x;
	bomb->y=y;
	bomb->time=time;
}

int bomb_get_active(struct bomb* bomb){
	assert(bomb);
	return bomb->active;
}

void bomb_set_active(struct bomb* bomb){
	assert(bomb);
	bomb->active=1;
}

void bomb_set_unactive(struct bomb* bomb,struct map* map,struct player* player){
	assert(bomb);
	map_set_cell_type(map, bomb->x, bomb->y, CELL_EMPTY);
	bomb->active=0;
	player_inc_nb_bomb(player);

}

void bomb_destruction(struct bomb* bomb,struct map* map,struct player* player);


void bomb_display(struct bomb* bomb,int timer,struct map* map,struct player* player){
	assert(bomb);
	printf("affichage bombe en ,%d,%d,%d,%d\n",bomb->x,bomb->y,timer,bomb->time);
	//implement the different sprite
	int old_bomb=timer-bomb->time;

	window_display_image(sprite_get_bomb(),bomb->x*SIZE_BLOC,bomb->y*SIZE_BLOC);
	if( old_bomb>3000){
		bomb_set_unactive(bomb,map,player);
	}
	//at the end change the cell by CELL_EMPTY
}
