
#pragma once
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
		no_piece = 0, 
		w_pawn = 1, w_knight = 2, w_bishop = 3, w_rook = 4 , w_queen = 5 , w_king = 6, 
		b_pawn = 7, b_knight = 8, b_bishop = 9, b_rook = 10, b_queen = 11, b_king = 12};

	using Board = std::array<int,89>;
	Board board{};
	//bool save_game();
	void set_colour_theme( int const theme);
	void initialise_board();
	std::list<int> list_of_valid_moves(int const position_now);
	bool is_on_board(int const position) const;
	bool is_black(int const position) const;
	bool is_white(int const position) const;
	bool are_enemies(int const position1, int const position2) const;
	void error_output(int const error_num) const;
	bool is_king(int const position) const;
	bool is_king(int const position, Board const& temp_board) const;
	int find_king(int const color_king) const;
	int find_piece(Figures const& piece) const;
	std::list<int> list_of_king_attakers(int const color_king);
	
	std::list<int> list_rook_moves(int const position);
	std::list<int> list_bishop_moves(int const position);
	std::list<int> list_queen_moves(int const position);
	std::list<int> list_knight_moves(int const position);

  bool attacked_by_x (int const& position,Board const& temp_board,Figures const& figure, std::array<int,4> const& moveset) const;
	bool attacked_by_bishop (int const& position,Board const& board) const;
	bool attacked_by_rook (int const& position,Board const& temp_bord) const;
	bool attacked_by_queen (int const& position,Board const& temp_bord) const;
	bool attacked_by_knight (int const& position,Board const& temp_bord) const;
	bool attacked_by_pawn (int const& position,Board const& temp_bord) const;

	std::string board_pos_to_string(short board);

	//Leo is the best
	//Theme one standart
	int colorbonw = 112;
	int colorbonb = 96;
	int colorwonw = 127;
	int colorwonb = 111;
	int colorleg = 15;

	const int boardtheme = 2;
	HANDLE hConsole;
	void set_console_color(int const color);
	std::string inttochar(int const inttemp) const;
	void visualise();
	void visualisemoves(std::list<int> return_list);
	int quersum(int intemp);
	int playmove(int movefrom, int moveto,int valid);
private:
	std::array<int,4> const straight_moves{{-10,-1,1,10}};
	std::array<int,4> const diagonal_moves{{-11,-9,9,11}};
	std::array<int,8> const queen_moves{{-11,-9,9,11,-10,-1,1,10,}};
	std::array<int,8> const knight_moves{{ 19, 21 ,12, -8, -19, -21, -12, 8 }};
};



	

