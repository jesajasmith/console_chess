#include <iostream>
#include "Game.h"
#include <list>

#define NUM_GAMES 50
#define min_board 1
#define max_board 8

using namespace std;

int hi;

int main() {
	

	Game newgame;

	list<int> listvalidmoves;
	listvalidmoves.push_front(11);
	listvalidmoves.push_front(88);
	listvalidmoves.push_front(12);
	listvalidmoves.push_front(13);
	listvalidmoves.push_front(45);

	newgame.visualise();
	newgame.visualisemoves(listvalidmoves);


	int numtest = newgame.quersum(13);
	cout << numtest;

	return 0;
}
