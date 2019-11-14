
#pragma once
#include "Game.h"
#include <iostream>
#include <string>
#include <windows.h>   // WinApi header
using namespace std;    // std::cout, std::cin

using namespace std;
class Game
{
public:
	Game();
	virtual ~Game();
	enum Figures {
		empty = 0, w_pawn = 1, w_knight = 2, w_bishop = 3, w_rook = 4, w_queen = 5, 
		w_king = 6, b_pawn = 7, b_knight = 8, b_bishop = 9, b_rook = 10, b_queen = 11 , b_king = 12};

	int board_position[89] = {0};
	void output_board();
	//bool save_game();
	void initialise_board();
	string board_pos_to_figure(short board);

	//Leo is the best
	char inttochar(int inttemp);
	void visualise();
};



	

