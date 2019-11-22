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

	/*list<int> listvalidmoves;
	listvalidmoves.push_front(11);
	listvalidmoves.push_front(88);
	listvalidmoves.push_front(12);
	listvalidmoves.push_front(13);
	listvalidmoves.push_front(45);

	newgame.visualise();
	newgame.visualisemoves(listvalidmoves);


	int numtest = newgame.quersum(13);
	cout << numtest;
	*/

	/*

	// check idea
	list <int> temp_list, zerro_list;
	for (int i = 11; i <= 88; i++)
	{
		temp_list = zerro_list;
		if (newgame.is_position_in_board(i)) 
		{

			for (int j = 11; j <= 88; j++)
			{
				if (newgame.is_position_in_board(j))
				{
					int x_square = ((i % 10) - (j % 10)) * ((i % 10) - (j % 10)) * 100;
					int y_square = (((i - (i % 10)) - (j - (j % 10))) * ((i - (i % 10)) - (j - (j % 10))));
					
					if (x_square == y_square) temp_list.push_back(j);
					
				}
			}

			newgame.visualisemoves(temp_list);
			cout << "Position " << i << " has " << temp_list.size() << " size \n" << endl;

		}

	
	}

	*/

	newgame.visualisemoves(newgame.list_of_valid_moves(57));
	cin >> hi;

	return 0;
}
