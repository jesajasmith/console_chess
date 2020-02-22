#include <iostream>
#include "Game.h"
#include <list>
#include<stdio.h>
#include<windows.h>

#define NUM_GAMES 50
#define min_board 1
#define max_board 8

using namespace std;

std::string hi;

int main() {

	Game game;

	game.visualise();
    cin >> hi;
	/*list<int> listvalidmoves;
	listvalidmoves.push_front(11);
	listvalidmoves.push_front(88);
	listvalidmoves.push_front(12);
	listvalidmoves.push_front(13);
	listvalidmoves.push_front(45);

	game.visualise();
	game.visualisemoves(listvalidmoves);


	int numtest = game.quersum(13);
	cout << numtest;
	*/

	/*

	// check idea
	list <int> temp_list, zerro_list;
	for (int i = 11; i <= 88; i++)
	{
		temp_list = zerro_list;
		if (game.is_position_in_board(i)) 
		{

			for (int j = 11; j <= 88; j++)
			{
				if (game.is_position_in_board(j))
				{
					int x_square = ((i % 10) - (j % 10)) * ((i % 10) - (j % 10)) * 100;
					int y_square = (((i - (i % 10)) - (j - (j % 10))) * ((i - (i % 10)) - (j - (j % 10))));
					
					if (x_square == y_square) temp_list.push_back(j);
					
				}
			}

			game.visualisemoves(temp_list);
			cout << "Position " << i << " has " << temp_list.size() << " size \n" << endl;

		}

	
	}

	*/

	game.visualisemoves(game.list_of_valid_moves(12));
	//game.visualisemoves(game.list_of_king_attakers(12));

	cin >> hi;

	return 0;
}
