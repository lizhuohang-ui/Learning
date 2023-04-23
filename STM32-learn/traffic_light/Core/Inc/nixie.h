#ifndef __NIXIE__
#define __NIXIE__

#include "main.h"

void Nixie_display(int num);
void Nixie_east_run(void);
void Nixie_west_run(void);
void Nixie_south_run(void);
void Nixie_north_run(void);
void Nixie_display_count(int east_count, int west_count, int south_count, int north_count);

#endif
