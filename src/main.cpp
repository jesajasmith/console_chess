﻿#include <iostream>
#include "Game.h"

#define NUM_GAMES 50
#define min_board 1
#define max_board 8

using namespace std;

int hi;

int main() {
	
	Game newgame;

	newgame.visualise();
	
	newgame.playmove(21, 31, 1);

	newgame.visualise();


	return 0;
}
