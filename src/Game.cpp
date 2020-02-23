#include "Game.h"

Game::Game() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	set_colour_theme(boardtheme);

	initialise_board();
}

void Game::set_colour_theme( int const theme) {
	if (theme == 0) {//Theme 0 default
		colorbonw = 112;
		colorbonb = 96;
		colorwonw = 127;
		colorwonb = 111;
		colorleg = 15;
 	} else if (theme == 1) {//Theme 1 Grey and Beige
		colorbonw = 112;
		colorbonb = 96;
		colorwonw = 127;
		colorwonb = 111;
		colorleg = 15;
	} else if (theme == 2) {//Theme 2 Light and Dark Grey
		colorbonw = 112;
		colorbonb = 128;
		colorwonw = 127;
		colorwonb = 143;
		colorleg = 15;
	} else if (theme == 3) {//Theme Colorful
		colorbonw = 73;
		colorbonb = 83;
		colorwonw = 74;
		colorwonb = 90;
		colorleg = 15;
	}
}

void Game::initialise_board() {
	for (auto & field : board) { field = 0; }

	board[11] = w_rook;
	board[12] = w_knight;
	board[13] = w_bishop;
	board[14] = w_queen;
	board[15] = w_king;
	board[16] = w_bishop;
	board[17] = w_knight;
	board[18] = w_rook;

	for (int i = 21; i <= 28; i++) { board[i] = w_pawn; }

	board[81] = b_rook;
	board[82] = b_knight;
	board[83] = b_bishop;
	board[84] = b_queen;
	board[85] = b_king;
	board[86] = b_bishop;
	board[87] = b_knight; 
	board[88] = b_rook;

	for (int i = 71; i <= 78; i++) { board[i] = b_pawn; }
}

std::string Game::inttochar(int const inttemp) const {
	switch (inttemp) {
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

		case no_piece: return " ";

		default: return "@";
	}
}

void Game::set_console_color(int const color) {
	SetConsoleTextAttribute(hConsole, color);
}

void Game::visualise() {
  std::list<int> listvalidmoves{};
	visualisemoves(listvalidmoves);
}

void Game::visualisemoves(std::list<int> listvalidmoves) {
	std::cout << "Chess Board!\n";
	set_console_color(colorleg);
	std::cout << "\n   A  B  C  D  E  F  G  H  " << std::endl;
	for(auto row = 1; row < 9; row++) {
		set_console_color(colorleg);
		std::cout << row << " ";
		for (auto position = 10*row+1; position <= 10*row+8; position++) {

			int square_color = 64;
			if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), position) != listvalidmoves.end())) {
				if ( is_white(board[position]) ) {
					if ( quersum(position) % 2 ) {
						square_color = 79;
					} else {
						square_color = 207;
					}
				} else {
					if ( quersum(position) % 2 ) {
						square_color = 64;
					} else {
						square_color = 192;
					}
				}
			} else {
				if ( is_white(board[position]) ) {
					if ( quersum(position) % 2 ) {
						square_color = colorwonw;
					} else {
						square_color = colorwonb;
					}
				} else {
					if ( quersum(position) % 2 ) {
						square_color = colorbonw;
					} else {
						square_color = colorbonb;
					}
				}
			}
			set_console_color(square_color);
			std::cout << " " << inttochar(board[position]) << " ";
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

	switch(error_num) {
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

bool Game::attacked_by_x (int const& position,Board const& temp_board,Figures const& figure, std::array<int,4> const& moveset) const {
	for (auto && direction : moveset) {
		for (int next_position = position + direction ; is_on_board(next_position); next_position += direction) {
			if (temp_board[next_position] != no_piece) {
				if ( are_enemies(position,next_position) ) {
					if (((temp_board[next_position]-figure) % 6 ) == 0 ) {
						return true;
					}
				}
				break;
			}
		}
	}
	return false;
}

bool Game::attacked_by_bishop (int const& position,Board const& temp_board) const {
	return attacked_by_x(position,temp_board,w_bishop,diagonal_moves);
}

bool Game::attacked_by_rook (int const& position,Board const& temp_board) const {
	return attacked_by_x(position,temp_board,w_rook,straight_moves);
}

bool Game::attacked_by_queen (int const& position,Board const& temp_board) const {
	return ( attacked_by_x(position,temp_board,w_queen,diagonal_moves) || attacked_by_x(position,temp_board,w_queen,straight_moves) );
}

bool Game::attacked_by_knight (int const& position,Board const& temp_board) const {
	for (auto && knight_move : knight_moves) {
		if (is_on_board(position + knight_move) && 
				are_enemies(position,position+knight_move) && 
				(temp_board[position + knight_move]-w_knight)%6 == 0 ) {
			return true;
		}
	}
	return false;
}

bool Game::attacked_by_pawn (int const& position,Board const& temp_board) const {
	if(is_white(position)) {
		if (is_on_board(position + 9) && temp_board[position + 9] == b_pawn) {
			return true;
		} else if (is_on_board(position + 11) && temp_board[position + 11] == b_pawn) {
			return true;
		}
	} else {
		if (is_on_board(position - 9) && temp_board[position - 9] == w_pawn) {
			return true;
		} else if (is_on_board(position - 11) && temp_board[position - 11] == w_pawn) {
			return true;
		}
	}
	return false;
}

bool Game::is_king(int position) const {
	return is_king(position,board);
}

bool Game::is_king(int const position, Board const& temp_board) const {
	if (!is_on_board(position)) {
		error_output(1);
		return false;
	}

	if ((temp_board[position] == w_king) || (temp_board[position] == b_king)) {

    if(attacked_by_bishop (position,temp_board)) {
			return true;
		} else if(attacked_by_rook (position,temp_board)) {
			return true;
		} else if(attacked_by_queen (position,temp_board)) {
			return true;
		} else if(attacked_by_knight (position,temp_board)) {
			return true;
		} else if(attacked_by_pawn (position,temp_board)) {
			return true;
		}

		return false;
	} else {
		error_output(3);
	}
	return false;
}

int Game::find_king(int const color_king) const {
    
	int position = find_piece(static_cast<Figures>(color_king));
	if (!position) error_output(3);
	return position;
}

int Game::find_piece(Figures const& piece) const {
  	for (int position = 11; position<89; position++) {
		if (board[position] == piece) return position;
	}
	error_output(1);
	return 0;
}

std::list<int> Game::list_of_king_attakers(int color_king) {
	std::list<int> return_list;
	int king_position;

	if (color_king == w_king) {
		king_position = find_king(color_king);

		for (auto && knight_move : knight_moves) {
			if (!is_on_board(king_position + knight_move)) continue;
			if (board[king_position + knight_move] == b_knight) return_list.push_back(king_position + knight_move);
		}

		//check for pawn

		if (is_on_board(king_position + 9) && board[king_position + 9] == b_pawn) return_list.push_back(king_position + 9);
		if (is_on_board(king_position + 11) && board[king_position + 11] == b_pawn) return_list.push_back(king_position + 11);

		//check for bishop & part queen

		int next_position;
		for (auto && diagonal : diagonal_moves) {
			next_position = king_position + diagonal;
			while (is_on_board(next_position)) {
				if (board[next_position] == no_piece) {
					next_position = next_position + diagonal;
					continue;
				}
				if (is_white(board[next_position])) break;
				if (is_black(board[next_position])) {
					if (board[next_position] == b_bishop || board[next_position] == b_queen) return_list.push_back(next_position);
					break;
				}
			}
		}

		//check for rook & queen

		next_position = king_position;

		for (auto && straight : straight_moves) {

			next_position = king_position + straight;

			while (is_on_board(next_position)) {
				if (board[next_position] == no_piece) {
					next_position = next_position + straight;
					continue;
				}

				if (is_white(board[next_position])) break;

				if (is_black(board[next_position])) {
					if (board[next_position] == b_rook || board[next_position] == b_queen) return_list.push_back(next_position);
					break;
				}

			}

		}

	}

	else if (color_king == b_king) {
		king_position = find_king(color_king);

		for (auto && knight_move : knight_moves) {
			if (!is_on_board(king_position + knight_move)) continue;
			if (board[king_position + knight_move] == w_knight) return_list.push_back(king_position + knight_move);
		}

		//check for pawn

		if (is_on_board(king_position - 9) && board[king_position - 9] == w_pawn) return_list.push_back(king_position - 9);
		if (is_on_board(king_position - 11) && board[king_position - 11] == w_pawn) return_list.push_back(king_position - 11);

		//check for bishop & part queen

		int next_position;
		for (auto && diagonal : diagonal_moves) {
			next_position = king_position + diagonal;
			while (is_on_board(next_position)) {
				if (board[next_position] == no_piece) {
					next_position = next_position + diagonal;
					continue;
				}
				if (is_black(board[next_position])) break;
				if (is_white(board[next_position])) {
					if (board[next_position] == w_bishop || board[next_position] == w_queen) return_list.push_back(next_position);
					break;
				}
			}
		}

		//check for rook & queen

		next_position = king_position;

		for (auto && straight : straight_moves) {

			next_position = king_position + straight;

			while (is_on_board(next_position)) {
				if (board[next_position] == no_piece) {
					next_position = next_position + straight;
					continue;
				}

				if (is_black(board[next_position])) break;

				if (is_white(board[next_position])) {
					if (board[next_position] == w_rook || board[next_position] == w_queen) return_list.push_back(next_position);
					break;
				}
			}
		}
	}

	return return_list;
}

bool Game::is_on_board(int const position) const {
	//check if first and second integer are in [1,..,8] 
	if (((position <= 88) && (position >= 11)) && (((position % 10) >= 1) && ((position % 10) <= 8))) return true;
	return false;
}

bool Game::is_black(int const position) const {
	if (position >= 7 && position <= 12) return true;
	return false;
}

bool Game::is_white(int const position) const {
	if (position >= 1 && position <= 6) return true;
	return false;
}

bool Game::are_enemies(int const position1, int const position2) const {
	if ( (is_black(board[position1]) && is_white(board[position2])) || 
			 (is_white(board[position1]) && is_black(board[position2])) ) {
		return true;
	}
	return false;
}

std::list<int> Game::list_rook_moves(int const position)  {
	std::list<int> move_list;
	
	for(auto&& straight : straight_moves) {
		for (int next_pos = position + straight;is_on_board(next_pos) == true; next_pos += straight) {
			if (board[next_pos] == no_piece) {
				move_list.push_back(next_pos);
			} else {
				if (are_enemies(position,next_pos)) move_list.push_back(next_pos);
				break;
			}
		}
	}
	return move_list;
}

std::list<int> Game::list_bishop_moves(int const position)  {
	std::list<int> move_list;
	for(auto && diagonal : diagonal_moves) {
		for (int next_pos = position + diagonal; is_on_board(next_pos); next_pos += diagonal) {
			if (board[next_pos] == no_piece) {
				move_list.push_back(next_pos);
			} else {
				if (are_enemies(position,next_pos)) move_list.push_back(next_pos);	
				break;
			}
		}
	}
	return move_list;
}

std::list<int> Game::list_queen_moves(int const position)  {
	auto rook_moves = list_rook_moves(position);
	auto bishop_moves =list_bishop_moves(position);
	rook_moves.splice(rook_moves.end(),bishop_moves);
	return rook_moves;
}

std::list<int> Game::list_knight_moves(int const position)  {
	std::list<int> move_list;
	for (auto&& k_move : knight_moves) {
		int next_pos = position + k_move;
		if ( is_on_board(next_pos) && (board[next_pos] == no_piece || are_enemies(position,next_pos)) ) {
			move_list.push_back(next_pos);
		} 
	}
	return move_list;
}

std::list<int> Game::list_of_valid_moves(int const position_now)  {
	std::list<int> return_list, empty_list;
	int const this_piece = board[position_now];
	//Return empty list if position isn't in board
	if (!(is_on_board(position_now))) {
		error_output(1);
		return return_list;
	}
	// Return empty list if board is empty
	if (this_piece == no_piece) return return_list;


	/*__________________________________________________________________________________________________________________________________
														is piece pinned
	__________________________________________________________________________________________________________________________________
	*/

	int position_king = 0;  
	int cursor = 0;
	int addition = 0;

												//##### Case white pieces ####

	bool no_pieces_between_king_and_position_now = true;

	if (is_white(this_piece) && this_piece != w_king) {
		position_king = find_king(w_king);
		//####### Case piece pinned by rook or queen ######
		//Same colum
		if (((position_now - position_king) % 10) == 0) {
			if (position_king < position_now) addition = 10;
			if (position_king > position_now) addition = -10;
		}
		//Same row
		if ((position_king - (position_king % 10)) == (position_now - (position_now % 10))) {
			if (position_king < position_now) addition = 1;
			if (position_king > position_now) addition = -1;
		}

		if (addition != 0){
			cursor = position_king + addition;

			//check if there are no pieces between king and position_now

			while (cursor != position_now) {
				bool temp = false;
				if (board[cursor] == no_piece) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}
			if (no_pieces_between_king_and_position_now == true) {

				cursor = position_now + addition;

				while (is_on_board(cursor)) {
					if (board[cursor] == no_piece) {
						cursor = cursor + addition;
						continue;
					}
					if (is_white(board[cursor])) break;
					if (board[cursor] == b_queen || board[cursor] == b_rook) {
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (this_piece == w_queen || this_piece == w_rook)
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
						else if (this_piece == w_pawn)
						{
							if (addition == 10)
							{
								if (board[position_now + addition] == no_piece)
								{
									return_list.push_back(position_now + addition);
									if (((position_now - (position_now % 10)) == 1) || board[position_now + addition + addition] == no_piece)
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

		if (x_square == y_square) {

			// left diagonal 
			if ((position_king % 11) == (position_now % 11)) {
				if (position_king < position_now) addition = 11;
				if (position_king > position_now) addition = -11;
			}
			// rigth diagonal
			if ((position_king % 9) == (position_now % 9)) {
				if (position_king < position_now) addition = 9;
				if (position_king > position_now) addition = -9;
			}

			cursor = position_king + addition;


			//Check if lane between king and position_now is empty 
			no_pieces_between_king_and_position_now = true;
			while (cursor != position_now) {
				bool temp = false;
				if (board[cursor] == no_piece) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}

			if (no_pieces_between_king_and_position_now == true) {
				cursor = position_now + addition;
				while (is_on_board(cursor)) {
					if (board[cursor] == no_piece)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_white(board[cursor])) break;
					if (board[cursor] == b_queen || board[cursor] == b_bishop)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (this_piece == w_queen || this_piece == w_bishop)
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

	if (is_black(this_piece) && this_piece != b_king) {
		position_king = find_king(b_king);


		//####### Case piece pinned by rook or queen ######

		//Same colum
		if (((position_now - position_king) % 10) == 0) {
			if (position_king < position_now) addition = 10;
			if (position_king > position_now) addition = -10;
		}
		//Same row
		if ((position_king - (position_king % 10)) == (position_now - (position_now % 10))) {
			if (position_king < position_now) addition = 1;
			if (position_king > position_now) addition = -1;
		}

		if (addition != 0) {
			cursor = position_king + addition;

			//check if there are no pieces between king and position_now

			while (cursor != position_now) {
				bool temp = false;
				if (board[cursor] == no_piece) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}
			if (no_pieces_between_king_and_position_now == true) {

				cursor = position_now + addition;

				while (is_on_board(cursor)) {
					if (board[cursor] == no_piece)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_black(board[cursor])) break;
					if (board[cursor] == w_queen || board[cursor] == w_rook)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (this_piece == b_queen || this_piece == b_rook)
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
						else if (this_piece == b_pawn)
						{
							if (addition == -10)
							{
								if (board[position_now + addition] == no_piece)
								{
									return_list.push_back(position_now + addition);
									if (((position_now - (position_now % 10)) == 7) || board[position_now + addition + addition] == no_piece)
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

		if (x_square == y_square) {

			// left diagonal 
			if ((position_king % 11) == (position_now % 11)) {
				if (position_king < position_now) addition = 11;
				if (position_king > position_now) addition = -11;
			}
			// rigth diagonal
			if ((position_king % 9) == (position_now % 9)) {
				if (position_king < position_now) addition = 9;
				if (position_king > position_now) addition = -9;
			}

			cursor = position_king + addition;


			//Check if lane between king and position_now is empty 
			no_pieces_between_king_and_position_now = true;
			while (cursor != position_now) {
				bool temp = false;
				if (board[cursor] == no_piece) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}

			if (no_pieces_between_king_and_position_now == true) {
				cursor = position_now + addition;
				while (is_on_board(cursor)) {
					if (board[cursor] == no_piece)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_black(board[cursor])) break;
					if (board[cursor] == w_queen || board[cursor] == w_bishop)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (this_piece == b_queen || this_piece == b_bishop)
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
	
	if (this_piece == w_bishop || this_piece == b_bishop ) {

		return_list.splice(return_list.end(), list_bishop_moves(position_now));

	} else if (this_piece == w_rook || this_piece == b_rook ) {

		return_list.splice(return_list.end(), list_rook_moves(position_now));

	} else if ( this_piece == w_queen || this_piece == b_queen) {

		return_list.splice(return_list.end(), list_queen_moves(position_now));	

	} else if (this_piece == w_knight || this_piece == b_knight) {

		return_list.splice(return_list.end(), list_knight_moves(position_now));

	} else if (this_piece == w_pawn) {
		if ((is_on_board(position_now + 10)) && (board[position_now + 10] == no_piece)) return_list.push_back(position_now + 10);
		if ((is_on_board(position_now + 9)) && is_black((board[position_now + 9]))) return_list.push_back(position_now + 9);
		if ((is_on_board(position_now + 11)) && is_black((board[position_now + 11]))) return_list.push_back(position_now + 11);
	} else if (this_piece == b_pawn) {
		if ((is_on_board(position_now - 10)) && (board[position_now - 10] == no_piece)) return_list.push_back(position_now - 10);
		if ((is_on_board(position_now - 9)) && is_white((board[position_now - 9]))) return_list.push_back(position_now - 9);
		if ((is_on_board(position_now - 11)) && is_white((board[position_now - 11]))) return_list.push_back(position_now - 11);
	}



	/*__________________________________________________________________________________________________________________________________
												case king
	__________________________________________________________________________________________________________________________________
	*/

	Board temp_board = board;
	temp_board[position_now] = no_piece;

	bool enemy_king_is_not_one_field_away = true;

										//###### case white king #####

	if (this_piece == w_king) {
		int king_addition[8] = { 9,10,11,1,-11,-10,-9,-1 };

		for (int i = 0; i <= 7; i++)

		{
			enemy_king_is_not_one_field_away = true;
			if ((board[position_now + king_addition[i]] == no_piece || is_black(board[position_now + king_addition[i]])) && (is_on_board(position_now + king_addition[i]))) {
				for (int j = 0; j <= 7; j++) {
					if (is_on_board(position_now + king_addition[i] + king_addition[j]))
						enemy_king_is_not_one_field_away = enemy_king_is_not_one_field_away && ((board[position_now + king_addition[i] + king_addition[j]]) != b_king);
				}

				if (enemy_king_is_not_one_field_away == true) {
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

	if (this_piece == b_king) {
		int king_addition[8] = { 9,10,11,1,-11,-10,-9,-1 };

		for (int i = 0; i <= 7; i++)

		{
			enemy_king_is_not_one_field_away = true;
			if ((board[position_now + king_addition[i]] == no_piece || is_white(board[position_now + king_addition[i]])) 
				&& (is_on_board(position_now + king_addition[i]))) {
				for (int j = 0; j <= 7; j++) {
					if (is_on_board(position_now + king_addition[i] + king_addition[j]))
						enemy_king_is_not_one_field_away = enemy_king_is_not_one_field_away 
						&& ((board[position_now + king_addition[i] + king_addition[j]]) != w_king);
				}

				if (enemy_king_is_not_one_field_away == true) {
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
	if (is_white(this_piece) && !(this_piece == w_king) && is_king(find_king(w_king))) {
		std::list<int> king_attaker_list = list_of_king_attakers(w_king);
		if (king_attaker_list.size() == 1) {
			int temp = king_attaker_list.front();
			//If attacking piec in list push.back
			if (find(return_list.begin(), return_list.end(), temp) != return_list.end()) empty_list.push_back(temp);
			return empty_list;

		}
		else return empty_list;
	}

	//Case black piece
	if (is_black(this_piece) && !(this_piece == b_king) && is_king(find_king(b_king))) {
		std::list<int> king_attaker_list = list_of_king_attakers(b_king);
		if (king_attaker_list.size() == 1) {
			int temp = king_attaker_list.front();
			//If attacking piec in list push.back
			if (find(return_list.begin(), return_list.end(), temp) != return_list.end()) empty_list.push_back(temp);
			return empty_list;

		}
		else return empty_list;
	}
	return return_list;
}