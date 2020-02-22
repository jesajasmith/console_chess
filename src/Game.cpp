#include "Game.h"


Game::Game() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/* 	struct ColorTheme {
		int colorbonw;
		int colorbonb;
		int colorwonw;
		int colorwonb;
		int colorleg;
	};
	ColorTheme const standard = {112,96,127,11,15};
	ColorTheme const grey_beige = {112,96,127,111,15};
	ColorTheme const light_dark = {112,128,127,143,15};
	ColorTheme const colorful = {73,83,74,90,15}; */

	//Theme 1 Grey and Beige
	if (boardtheme == 1) {
		colorbonw = 112;
		colorbonb = 96;
		colorwonw = 127;
		colorwonb = 111;
		colorleg = 15;
	}
	//Theme 2 Light and Dark Grey
	if (boardtheme == 2) {
		colorbonw = 112;
		colorbonb = 128;
		colorwonw = 127;
		colorwonb = 143;
		colorleg = 15;
	}
	//Theme Colorful
	if (boardtheme == 3) {
		colorbonw = 73;
		colorbonb = 83;
		colorwonw = 74;
		colorwonb = 90;//
		colorleg = 15;
	}
	initialise_board();
}

void Game::initialise_board() {
	for (auto & field : board)
	{
		field = 0;
	}

	board[11] = w_rook;
	board[12] = w_knight;
	board[13] = w_bishop;
	board[14] = w_queen;
	board[15] = w_king;
	board[16] = w_bishop;
	board[17] = w_knight;
	board[18] = w_rook;

	for (int i = 21; i <= 28; i++)
	{
		board[i] = w_pawn;
	}

	board[81] = b_rook;
	board[82] = b_knight;
	board[83] = b_bishop;
	board[84] = b_queen;
	board[85] = b_king;
	board[86] = b_bishop;
	board[87] = b_knight; 
	board[88] = b_rook;

	for (int i = 71; i <= 78; i++)
	{
		board[i] = b_pawn;
	}
}

std::string Game::board_pos_to_figure(short board_pos) {
	switch (board_pos) {
	case w_pawn: return "P";
	case w_bishop: return "B";
	case w_knight: return "K";
	case w_rook: return "R";
	case w_queen: return "Q";
	case w_king: return "+";

	case b_pawn: return "P";
	case b_bishop: return "B";
	case b_knight: return "K";
	case b_rook: return "R";
	case b_queen: return "Q";
	case b_king: return "+";

	case empty: return " ";
	default: std::cout << "Error in board_pos_to_figure() function!" << std::endl;
	}

	return "Error in board_pos_to_figure() function!";

}

std::string Game::inttochar(int const inttemp) const {
	switch (inttemp)
	{
	case 1: return "P";
	case 2: return "K";
	case 3: return "B";
	case 4: return "R";
	case 5: return "Q";
	case 6: return "+";
	case 7: return "P";
	case 8: return "K";
	case 9: return "B";
	case 10: return "R";
	case 11: return "Q";
	case 12: return "+";

	default: return " ";
	}
}


void Game::set_console_color(int const color) {
	SetConsoleTextAttribute(hConsole, color);
}

void Game::visualise() {
	std::cout << "Chess Board!\n";
	set_console_color(colorleg);
	std::cout << "\n   A  B  C  D  E  F  G  H  "<< std::endl;
	for(int i = 1;i<9;i++) {
		set_console_color(colorleg);
		std::cout << i<<" ";
		for (size_t i1 = 10*i+1; i1 <= 10*i+8; i1++)
		{
			int colortemp;
			if ( (i1+i+1) % 2 )
			{
				if (board[i1] <= 6) { colortemp = colorwonw; }
				else { colortemp = colorbonw; }
			}
			else
			{
				if (board[i1] <= 6) { colortemp = colorwonb; }
				else { colortemp = colorbonb; }
			}

			set_console_color(colortemp);
			std::cout << " " << inttochar(board[i1]) << " ";
		}
		
		set_console_color(colorleg);
		std::cout << " " << i << std::endl;
	}
	
	std::cout << "   A  B  C  D  E  F  G  H  " << std::endl << std::endl;
}

void Game::visualisemoves(std::list<int> listvalidmoves) {
	std::cout << "Chess Board!\n";
	set_console_color(colorleg);
	std::cout << "\n   A  B  C  D  E  F  G  H  " << std::endl;
	for(auto row = 1; row<9; row++) {
		set_console_color(colorleg);
		std::cout << row << " ";
		for (auto column = 10*row+1; column <= 10*row+8; column++) {
			int colortemp;
			if ( (column+row+1) % 2 ) {
				if (board[column] <= 6) { 
					colortemp = colorwonw; 
				} else { 
					colortemp = colorbonw; 
				}
			} else {
				if (board[column] <= 6) { 
					colortemp = colorwonb; 
				} else { 
					colortemp = colorbonb; 
				}
			}


			set_console_color(colortemp);
			if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), column) != listvalidmoves.end())) {
				int colormarker = 64;
				if (board[column] <= 6) {
					colormarker = 79;
					if (quersum(column) % 2) {
						colormarker = 79;
					} else {
						colormarker = 207;
					}
				} else {
					colormarker = 64;
					if (quersum(column) % 2) {
						colormarker = 64;
					} else {
						colormarker = 192;
					}
				}
				set_console_color(colormarker);
			}
			
			std::cout << " " << inttochar(board[column]) << " ";
		}
		set_console_color(colorleg);
		std::cout << " " << row << std::endl;
	}
	std::cout << "   A  B  C  D  E  F  G  H  " << std::endl << std::endl;
}



int Game::quersum(int intemp) {
	int outtemp = 0;
	while (intemp > 0) {
		outtemp += intemp % 10;
		intemp /= 10;
	}
	return outtemp;
}

int Game::playmove(int movefrom, int moveto, int valid) {
	//Overwrite array

	//Confirm kill
	int killconftemp = 0;
	int killtemp = 0;
	std::string killchartemp = " ";
	std::string killtypetemp = "";

		if (board[moveto] != 0) {
			killtemp = board[moveto];
			killchartemp = inttochar(killtemp);
			killconftemp = 1;
		}

		if (killtemp <= 6) {
			killtypetemp = "white";
		}
		else {
			killtypetemp = "black";
		}


    board[moveto] = board[movefrom];
	board[movefrom] = 0;
	

	set_console_color(15);

	std::cout << std::endl << movefrom <<" moved to " << moveto;
	if (killconftemp) {
		std::cout << killtypetemp << killchartemp << "was killed";
	}
	std::cout << std::endl;

	return 0;
}

void Game::error_output(int const error_num) const {
	std::string error_msg;

	switch(error_num)
	{
	case 1: error_msg = "Position of piece not in Board";
		break;
	case 2: error_msg = "King missing on Board";
		break;
	case 3: error_msg = "Wrong piece selected";
		break;
	}

	std::cout << "An error has acured ->  " << error_msg << std::endl;
	int temp_input;
	std::cin >> temp_input;

	return;
}

bool Game::is_king(int position) const {
	if (!is_position_in_board(position))
	{
		error_output(1);
		return false;
	}

	if (board[position] == w_king)
	{
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(position + knight_addition[i])) continue;
			if (board[position + knight_addition[i]] == b_knight) return true;
		}

		//check for pawn

		if (is_position_in_board(position + 9) && board[position + 9] == b_pawn) return true;
		if (is_position_in_board(position + 11) && board[position + 11] == b_pawn) return true;

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_white(board[next_position])) break;
				if (is_black(board[next_position]))
				{
					if (board[next_position] == b_bishop || board[next_position] == b_queen) return true;
					break;
				}


			}

		}

		//check for rook & queen

		int rook_addition[4] = { -1, 10 , 1 , -10 };
		next_position = position;

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + rook_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_white(board[next_position])) break;

				if (is_black(board[next_position]))
				{
					if (board[next_position] == b_rook || board[next_position] == b_queen) return true;
					break;
				}

			}

		}
		return false;
	}

	else if (board[position] == b_king)
	{
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(position + knight_addition[i])) continue;
			if (board[position + knight_addition[i]] == w_knight) return true;
		}

		//check for pawn

		if (is_position_in_board(position - 9) && board[position - 9] == w_pawn) return true;
		if (is_position_in_board(position - 11) && board[position - 11] == w_pawn) return true;

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_black(board[next_position])) break;
				if (is_white(board[next_position]))
				{
					if (board[next_position] == w_bishop || board[next_position] == w_queen) return true;
					break;
				}

			}

		}

		//check for rook & queen

		int rook_addition[4] = { -1, 10 , 1 , -10 };
		next_position = position;

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + rook_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
			
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_black(board[next_position])) break;

				if (is_white(board[next_position]))
				{
					if (board[next_position] == w_rook || board[next_position] == w_queen) return true;
					break;
				}

			}

		}

		return false;

	}

	else error_output(3);
	return false;
}

bool Game::is_king(int const position, Board const& temp_board) const {
	if (!is_position_in_board(position))
	{
		error_output(1);
		return false;
	}

	if (temp_board[position] == w_king)
	{
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(position + knight_addition[i])) continue;
			if (temp_board[position + knight_addition[i]] == b_knight) return true;
		}

		//check for pawn

		if (is_position_in_board(position + 9) && temp_board[position + 9] == b_pawn) return true;
		if (is_position_in_board(position + 11) && temp_board[position + 11] == b_pawn) return true;

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (temp_board[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_white(temp_board[next_position])) break;

				if (is_black(temp_board[next_position]))
				{
					if (temp_board[next_position] == b_bishop || temp_board[next_position] == b_queen) return true;
					break;
				}
					


			}

		}

		//check for rook & queen

		int rook_addition[4] = { -1, 10 , 1 , -10 };
		next_position = position;

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + rook_addition[i];

			while (is_position_in_board(next_position))
			{
				if (temp_board[next_position] == empty)
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_white(temp_board[next_position])) break;
				if (is_black(temp_board[next_position]))
				{
					if (temp_board[next_position] == b_rook || temp_board[next_position] == b_queen) return true;
					break;
				}

			}

		}
		return false;
	}


	else if (temp_board[position] == b_king)
	{
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(position + knight_addition[i])) continue;
			if (temp_board[position + knight_addition[i]] == w_knight) return true;
		}

		//check for pawn

		if (is_position_in_board(position - 9) && temp_board[position - 9] == w_pawn) return true;
		if (is_position_in_board(position - 11) && temp_board[position - 11] == w_pawn) return true;

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (temp_board[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_black(temp_board[next_position])) break;
				if (is_white(temp_board[next_position]))
				{
					if (temp_board[next_position] == w_bishop || temp_board[next_position] == w_queen) return true;
					break;
				}
				

			}

		}

		//check for rook & queen

		int rook_addition[4] = { -1, 10 , 1 , -10 };
		next_position = position;

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + rook_addition[i];

			while (is_position_in_board(next_position))
			{
				if (temp_board[next_position] == empty)

				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_black(temp_board[next_position])) break;
				if (is_white(temp_board[next_position]))
				{
					if (temp_board[next_position] == w_rook || temp_board[next_position] == w_queen) return true;
					break;
				}
			}

		}

		return false;

	}



	else error_output(3);
	return false;
}

int Game::find_king(int const color_king) const {
    
	for (auto const& position : board) {
		if (position == color_king) return i;
	}
	error_output(3);
	return 11;
}

std::list<int> Game::list_of_king_attakers(int color_king) {
	std::list<int> return_list;
	int king_position;

	if (color_king == w_king)
	{
		king_position = find_king(color_king);
	
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(king_position + knight_addition[i])) continue;
			if (board[king_position + knight_addition[i]] == b_knight) return_list.push_back(king_position + knight_addition[i]);
		}

		//check for pawn

		if (is_position_in_board(king_position + 9) && board[king_position + 9] == b_pawn) return_list.push_back(king_position + 9);
		if (is_position_in_board(king_position + 11) && board[king_position + 11] == b_pawn) return_list.push_back(king_position + 11);

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = king_position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_white(board[next_position])) break;
				if (is_black(board[next_position]))
				{
					if (board[next_position] == b_bishop || board[next_position] == b_queen) return_list.push_back(next_position);
					break;
				}


			}

		}

		//check for rook & queen

		int rook_addition[4] = { -1, 10 , 1 , -10 };
		next_position = king_position;

		for (int i = 0; i <= 3; i++)
		{

			next_position = king_position + rook_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_white(board[next_position])) break;

				if (is_black(board[next_position]))
				{
					if (board[next_position] == b_rook || board[next_position] == b_queen) return_list.push_back(next_position);
					break;
				}

			}

		}

	}

	else if (color_king == b_king)
	{
		king_position = find_king(color_king);

		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(king_position + knight_addition[i])) continue;
			if (board[king_position + knight_addition[i]] == w_knight) return_list.push_back(king_position + knight_addition[i]);
		}

		//check for pawn

		if (is_position_in_board(king_position - 9) && board[king_position - 9] == w_pawn) return_list.push_back(king_position - 9);
		if (is_position_in_board(king_position - 11) && board[king_position - 11] == w_pawn) return_list.push_back(king_position - 11);

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = king_position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_black(board[next_position])) break;
				if (is_white(board[next_position]))
				{
					if (board[next_position] == w_bishop || board[next_position] == w_queen) return_list.push_back(next_position);
					break;
				}


			}

		}

		//check for rook & queen

		int rook_addition[4] = { -1, 10 , 1 , -10 };
		next_position = king_position;

		for (int i = 0; i <= 3; i++)
		{

			next_position = king_position + rook_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board[next_position] == empty)
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_black(board[next_position])) break;

				if (is_white(board[next_position]))
				{
					if (board[next_position] == w_rook || board[next_position] == w_queen) return_list.push_back(next_position);
					break;
				}

			}

		}

	}

	return return_list;
}

bool Game::is_position_in_board(int position) const {
	//check if first and second integer are in [1,..,8] 
	if (((position <= 88) && (position >= 11)) && (((position % 10) >= 1) && ((position % 10) <= 8))) return true;
	return false;
}

bool Game::is_black(int position) const {
	if (position >= 7 && position <= 12) return true;
	return false;
}

bool Game::is_white(int position) const {
	if (position >= 1 && position <= 6) return true;
	return false;
}

std::list<int> Game::list_of_valid_moves(int position_now) {
	std::list<int> return_list, empty_list;
	//Return empty list if position isn't in board
	if (!(is_position_in_board(position_now)))
	{
		error_output(1);
		return return_list;
	}
	// Return empty list if board is empty
	if (board[position_now] == empty) return return_list;


	/*__________________________________________________________________________________________________________________________________
														is piece pinned
	__________________________________________________________________________________________________________________________________
	*/

	int position_king = 0;  
	int cursor = 0;
	int addition = 0;

												//##### Case white pieces ####

	bool no_pieces_between_king_and_position_now = true;

	if (is_white(board[position_now]) && !(board[position_now] == w_king))
	{
		position_king = find_king(w_king);

	
		//####### Case piece pinned by rook or queen ######

		//Same colum
		if (((position_now - position_king) % 10) == 0)
		{
			if (position_king < position_now) addition = 10;
			if (position_king > position_now) addition = -10;
		}
		//Same row
		if ((position_king - (position_king % 10)) == (position_now - (position_now % 10)))
		{
			if (position_king < position_now) addition = 1;
			if (position_king > position_now) addition = -1;
		}

		if (addition != 0)
		{
			cursor = position_king + addition;

			//check if there are no pieces between king and position_now

			while (cursor != position_now)
			{
				bool temp = false;
				if (board[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}
			if (no_pieces_between_king_and_position_now == true)
			{

				cursor = position_now + addition;

				while (is_position_in_board(cursor))
				{
					if (board[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_white(board[cursor])) break;
					if (board[cursor] == b_queen || board[cursor] == b_rook)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board[position_now] == w_queen || board[position_now] == w_rook)
						{
							return_list.push_back(cursor);
							int i = position_king + addition;
							while (i != cursor)
							{
								if (i == position_now)
								{
									i = i + addition;
									continue;
								}
								return_list.push_back(i);
								i = i + addition;
							}
							return return_list;
						}
						else if (board[position_now] == w_pawn)
						{
							if (addition == 10)
							{
								if (board[position_now + addition] == empty)
								{
									return_list.push_back(position_now + addition);
									if (((position_now - (position_now % 10)) == 1) || board[position_now + addition + addition] == empty)
										return_list.push_back(position_now + addition + addition);
									break;
								}
							}
						}
						//piece is pinned and can not make a move
						else return return_list;
					}
					else break;
				}

			}
		}


		//####### Case piece pinned by bishop or queen #######

		//check if position now and position king coordinates create a square

		int x_square = (position_king % 10 - position_now % 10) * 10;
		x_square = x_square * x_square;
		int y_square = ((position_king - (position_king % 10)) - (position_now - (position_now % 10)));
		y_square = y_square * y_square;

		if (x_square == y_square)
		{

			// left diagonal 
			if ((position_king % 11) == (position_now % 11))
			{
				if (position_king < position_now) addition = 11;
				if (position_king > position_now) addition = -11;
			}
			// rigth diagonal
			if ((position_king % 9) == (position_now % 9))
			{
				if (position_king < position_now) addition = 9;
				if (position_king > position_now) addition = -9;
			}

			cursor = position_king + addition;


			//Check if lane between king and position_now is empty 
			no_pieces_between_king_and_position_now = true;
			while (cursor != position_now)
			{
				bool temp = false;
				if (board[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}

			if (no_pieces_between_king_and_position_now == true)
			{
				cursor = position_now + addition;
				while (is_position_in_board(cursor))
				{
					if (board[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_white(board[cursor])) break;
					if (board[cursor] == b_queen || board[cursor] == b_bishop)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board[position_now] == w_queen || board[position_now] == w_bishop)
						{
							return_list.push_back(cursor);
							int i = position_king + addition;
							while (i != cursor)
							{
								if (i == position_now)
								{
									i = i + addition;
									continue;
								}
								return_list.push_back(i);
								i = i + addition;
							}
							return return_list;
						}
						//piece is pinned and can not make a move
						else return return_list;
					}
					else break;
				}

			}
		}
	}

															//##### Case black pieces ####

	no_pieces_between_king_and_position_now = true;

	if (is_black(board[position_now]) && !(board[position_now] == b_king))
	{
		position_king = find_king(b_king);


		//####### Case piece pinned by rook or queen ######

		//Same colum
		if (((position_now - position_king) % 10) == 0)
		{
			if (position_king < position_now) addition = 10;
			if (position_king > position_now) addition = -10;
		}
		//Same row
		if ((position_king - (position_king % 10)) == (position_now - (position_now % 10)))
		{
			if (position_king < position_now) addition = 1;
			if (position_king > position_now) addition = -1;
		}

		if (addition != 0)
		{
			cursor = position_king + addition;

			//check if there are no pieces between king and position_now

			while (cursor != position_now)
			{
				bool temp = false;
				if (board[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}
			if (no_pieces_between_king_and_position_now == true)
			{

				cursor = position_now + addition;

				while (is_position_in_board(cursor))
				{
					if (board[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_black(board[cursor])) break;
					if (board[cursor] == w_queen || board[cursor] == w_rook)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board[position_now] == b_queen || board[position_now] == b_rook)
						{
							return_list.push_back(cursor);
							int i = position_king + addition;
							while (i != cursor)
							{
								if (i == position_now)
								{
									i = i + addition;
									continue;
								}
								return_list.push_back(i);
								i = i + addition;
							}
							return return_list;
						}
						else if (board[position_now] == b_pawn)
						{
							if (addition == -10)
							{
								if (board[position_now + addition] == empty)
								{
									return_list.push_back(position_now + addition);
									if (((position_now - (position_now % 10)) == 7) || board[position_now + addition + addition] == empty)
										return_list.push_back(position_now + addition + addition);
									break;
								}
							}
						}
						//piece is pinned and can not make a move
						else return return_list;
					}
					else break;
				}

			}
		}


		//####### Case piece pinned by bishop or queen #######

		//check if position now and position king coordinates create a square

		int x_square = (position_king % 10 - position_now % 10) * 10;
		x_square = x_square * x_square;
		int y_square = ((position_king - (position_king % 10)) - (position_now - (position_now % 10)));
		y_square = y_square * y_square;

		if (x_square == y_square)
		{

			// left diagonal 
			if ((position_king % 11) == (position_now % 11))
			{
				if (position_king < position_now) addition = 11;
				if (position_king > position_now) addition = -11;
			}
			// rigth diagonal
			if ((position_king % 9) == (position_now % 9))
			{
				if (position_king < position_now) addition = 9;
				if (position_king > position_now) addition = -9;
			}

			cursor = position_king + addition;


			//Check if lane between king and position_now is empty 
			no_pieces_between_king_and_position_now = true;
			while (cursor != position_now)
			{
				bool temp = false;
				if (board[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}

			if (no_pieces_between_king_and_position_now == true)
			{
				cursor = position_now + addition;
				while (is_position_in_board(cursor))
				{
					if (board[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_black(board[cursor])) break;
					if (board[cursor] == w_queen || board[cursor] == w_bishop)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board[position_now] == b_queen || board[position_now] == b_bishop)
						{
							return_list.push_back(cursor);
							int i = position_king + addition;
							while (i != cursor)
							{
								if (i == position_now)
								{
									i = i + addition;
									continue;
								}
								return_list.push_back(i);
								i = i + addition;
							}
							return return_list;
						}
						//piece is pinned and can not make a move
						else return return_list;
					}
					else break;
				}

			}
		}
	}
	
			
		

	/*__________________________________________________________________________________________________________________________________
															case bis bishop & part Queen
	  __________________________________________________________________________________________________________________________________
	*/
	if (board[position_now] == w_bishop || board[position_now] == b_bishop
		|| board[position_now] == b_queen || board[position_now] == w_queen)
	{
		int next_position;

		//upper right diagonal
		next_position = position_now + 11;
		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}

			next_position = next_position + 11;
		}

		//upper left diagonal
		next_position = position_now + 9;

		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position + 9;
		}


		//lower right diagonal
		next_position = position_now - 9;

		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position - 9;
		}



		//lower left diagonal
		next_position = position_now - 11;

		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_bishop || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_bishop || board[position_now] == b_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position - 11;
		}

	}


	/*__________________________________________________________________________________________________________________________________
													case rook & part Queen
	__________________________________________________________________________________________________________________________________
	*/

	if (board[position_now] == w_rook || board[position_now] == b_rook
		|| board[position_now] == w_queen || board[position_now] == b_queen)
	{
		int next_position;

		// upper line 
		next_position = position_now + 10;
		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_white(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position + 10;
		}

		// lower line 
		next_position = position_now - 10;
		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_white(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position - 10;
		}

		// left line 
		next_position = position_now - 1;
		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_white(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position - 1;
		}


		// Right line 
		next_position = position_now + 1;
		while (is_position_in_board(next_position) == true)
		{
			if (board[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_white(board[next_position])) break;
				if ((board[position_now] == w_rook || board[position_now] == w_queen) && is_black(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_black(board[next_position])) break;
				if ((board[position_now] == b_rook || board[position_now] == b_queen) && is_white(board[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}

			}
			next_position = next_position + 1;
		}
	}

	/*__________________________________________________________________________________________________________________________________
															case Knight
	__________________________________________________________________________________________________________________________________
	*/
	if (board[position_now] == w_knight || board[position_now] == b_knight)
	{


		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{


			if (is_position_in_board(position_now + knight_addition[i]) == true)
			{

				if (board[position_now + knight_addition[i]] == empty)
				{
					return_list.push_back(position_now + knight_addition[i]);
					continue;
				}

				else if ((board[position_now] == w_knight && is_white(board[position_now + knight_addition[i]]))
					|| (board[position_now] == b_knight && is_black(board[position_now + knight_addition[i]])))
				{

					continue;
				}
				else if ((board[position_now] == w_knight && is_black(board[position_now + knight_addition[i]]))
					|| (board[position_now] == b_knight && is_white(board[position_now + knight_addition[i]])))
				{

					return_list.push_back(position_now + knight_addition[i]);
					continue;
				}

			}

		}
	}

	/*__________________________________________________________________________________________________________________________________
													case white pawn
	__________________________________________________________________________________________________________________________________
	*/

	if (board[position_now] == w_pawn)
	{
		if ((is_position_in_board(position_now + 10)) && (board[position_now + 10] == empty)) return_list.push_back(position_now + 10);
		if ((is_position_in_board(position_now + 9)) && is_black((board[position_now + 9]))) return_list.push_back(position_now + 9);
		if ((is_position_in_board(position_now + 11)) && is_black((board[position_now + 11]))) return_list.push_back(position_now + 11);
	}



	/*__________________________________________________________________________________________________________________________________
												case black pawn
	__________________________________________________________________________________________________________________________________
	*/

	if (board[position_now] == b_pawn)
	{
		if ((is_position_in_board(position_now - 10)) && (board[position_now - 10] == empty)) return_list.push_back(position_now - 10);
		if ((is_position_in_board(position_now - 9)) && is_white((board[position_now - 9]))) return_list.push_back(position_now - 9);
		if ((is_position_in_board(position_now - 11)) && is_white((board[position_now - 11]))) return_list.push_back(position_now - 11);
	}



	/*__________________________________________________________________________________________________________________________________
												case king
	__________________________________________________________________________________________________________________________________
	*/

	Board temp_board;
	for (int i = 0; i <= 88; i++)
	{
		temp_board[i] = board[i];
	}
	temp_board[position_now] = empty;

	bool enemy_king_is_not_one_field_away = true;

										//###### case white king #####

	if (board[position_now] == w_king)
	{
		int king_addition[8] = { 9,10,11,1,-11,-10,-9,-1 };

		for (int i = 0; i <= 7; i++)

		{
			enemy_king_is_not_one_field_away = true;
			if ((board[position_now + king_addition[i]] == empty || is_black(board[position_now + king_addition[i]])) && (is_position_in_board(position_now + king_addition[i])))
			{
				for (int j = 0; j <= 7; j++)
				{
					if (is_position_in_board(position_now + king_addition[i] + king_addition[j]))
						enemy_king_is_not_one_field_away = enemy_king_is_not_one_field_away && ((board[position_now + king_addition[i] + king_addition[j]]) != b_king);
				}

				if (enemy_king_is_not_one_field_away == true)
				{
					int temp_piece = temp_board[position_now + king_addition[i]];
					temp_board[position_now + king_addition[i]] = w_king;
					if (is_king(position_now + king_addition[i], temp_board) != true) return_list.push_back(position_now + king_addition[i]);
					temp_board[position_now + king_addition[i]] = temp_piece;
				}

			}
		}
	}

													//###### case black king ##### 
	enemy_king_is_not_one_field_away = true;

	if (board[position_now] == b_king)
	{
		int king_addition[8] = { 9,10,11,1,-11,-10,-9,-1 };

		for (int i = 0; i <= 7; i++)

		{
			enemy_king_is_not_one_field_away = true;
			if ((board[position_now + king_addition[i]] == empty || is_white(board[position_now + king_addition[i]])) 
				&& (is_position_in_board(position_now + king_addition[i])))
			{
				for (int j = 0; j <= 7; j++)
				{
					if (is_position_in_board(position_now + king_addition[i] + king_addition[j]))
						enemy_king_is_not_one_field_away = enemy_king_is_not_one_field_away 
						&& ((board[position_now + king_addition[i] + king_addition[j]]) != w_king);
				}

				if (enemy_king_is_not_one_field_away == true)
				{
					int temp_piece = temp_board[position_now + king_addition[i]];
					temp_board[position_now + king_addition[i]] = b_king;
					if (is_king(position_now + king_addition[i], temp_board) != true) return_list.push_back(position_now + king_addition[i]);
					temp_board[position_now + king_addition[i]] = temp_piece;
				}

			}
		}
	}


	/*__________________________________________________________________________________________________________________________________
											case king in check and move possibilitys for non king figures
	__________________________________________________________________________________________________________________________________
	*/


	
	//Case white piece
	if (is_white(board[position_now]) && !(board[position_now] == w_king) && is_king(find_king(w_king)))
	{
		std::list<int> king_attaker_list = list_of_king_attakers(w_king);
		if (king_attaker_list.size() == 1)
		{
			int temp = king_attaker_list.front();
			//If attacking piec in list push.back
			if (find(return_list.begin(), return_list.end(), temp) != return_list.end()) empty_list.push_back(temp);
			return empty_list;

		}
		else return empty_list;
	}

	//Case black piece
	if (is_black(board[position_now]) && !(board[position_now] == b_king) && is_king(find_king(b_king)))
	{
		std::list<int> king_attaker_list = list_of_king_attakers(b_king);
		if (king_attaker_list.size() == 1)
		{
			int temp = king_attaker_list.front();
			//If attacking piec in list push.back
			if (find(return_list.begin(), return_list.end(), temp) != return_list.end()) empty_list.push_back(temp);
			return empty_list;

		}
		else return empty_list;
	}
	return return_list;
}

	




