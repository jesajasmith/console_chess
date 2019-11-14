#include <iostream>
#include "Game.h"

#define NUM_GAMES 50
#define min_board 1
#define max_board 8

using namespace std;

int hi;

int main() {
	/*{
		for (int i = 0; i <= NUM_GAMES; i++)
		{
			while (true) //game.gamefinished == true
			{

			}
		}


		return 0;
	}
	*/
	Game newgame;
	newgame.output_board();
	cin >> hi;
	return 0;
}
