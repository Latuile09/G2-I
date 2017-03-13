#include <map.h>
#include <player.h>

struct bomb;

// Creates a new bomb
struct bomb* bomb_init();
void bomb_free(struct bomb* bomb);

void set_bomb_range(struct bomb* bomb,int range);

void bomb_set_place_and_time(struct bomb* bomb,int range,int time,int x,int y, struct map* map);

//get if the bomb is active or not
int bomb_get_active(struct bomb* bomb);

void bomb_set_unactive(struct bomb* bomb,struct map* map,struct player* player);

void bomb_set_active(struct bomb* bomb);

// Display the bomb on the screen
int bomb_display(struct bomb* bomb,int timer, struct map* map, struct player* player);

void bomb_destruction(struct bomb* bomb,struct map* map,struct player* player);
