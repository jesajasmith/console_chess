
#pragma once
#include "Game.h"
#include <iostream>
#include <string>

#include <windows.h>  
#include <list> 
#include <algorithm>

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
	list <int> list_of_valid_moves(int position_now);
	bool is_position_in_board(int position);
	bool is_black(int position);
	bool is_white(int position);
	void error_output(int error_num);
	bool is_king_check(int position);
	bool is_king_check(int position, int * temp_board);
	int find_king(int color_king);

	string board_pos_to_figure(short board);

	//Leo is the best
	int boardtheme = 2;
	char inttochar(int inttemp);
	void visualise();
	void visualisemoves(list<int> return_list);
	int quersum(int intemp);
	int playmove(int movefrom, int moveto,int valid);
	
};



	

