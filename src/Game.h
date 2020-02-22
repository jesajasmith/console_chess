
#pragma once
#include "Game.h"
#include <iostream>
#include <string>
#include <windows.h>  
#include <list> 
#include <algorithm>
#include <array>

class Game 
{
public:
	Game();
	enum Figures {
		empty = 0, 
		w_pawn = 1, w_knight = 2, w_bishop = 3, w_rook = 4 , w_queen = 5 , w_king = 6, 
		b_pawn = 7, b_knight = 8, b_bishop = 9, b_rook = 10, b_queen = 11, b_king = 12};

	using Board = std::array<int,89>;
	Board board{};
	//bool save_game();
	void initialise_board();
	std::list<int> list_of_valid_moves(int position_now);
	bool is_position_in_board(int position) const;
	bool is_black(int const position) const;
	bool is_white(int const position) const;
	void error_output(int const error_num) const;
	bool is_king(int const position) const;
	bool is_king(int const position, Board const& temp_board) const;
	int find_king(int const color_king) const;
	std::list<int> list_of_king_attakers(int const color_king);

	std::string board_pos_to_figure(short board);

	//Leo is the best
	//Theme one standart
	int colorbonw = 112;
	int colorbonb = 96;
	int colorwonw = 127;
	int colorwonb = 111;
	int colorleg = 15;

	int boardtheme = 2;
	HANDLE hConsole;
	void set_console_color(int const color);
	std::string inttochar(int const inttemp) const;
	void visualise();
	void visualisemoves(std::list<int> return_list);
	int quersum(int intemp);
	int playmove(int movefrom, int moveto,int valid);
	
};



	

