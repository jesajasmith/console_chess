#include "Game.h"



Game::Game()
{
	initialise_board();
}


Game::~Game()
{
}

void Game::initialise_board()
{
	for (int i = 0; i <= 88; i++)
	{
		board_position[i] = 0;
	}

	board_position[11] = w_rook;
	board_position[12] = w_knight;
	board_position[13] = w_bishop;
	board_position[14] = w_queen;
	board_position[15] = w_king;
	board_position[16] = w_bishop;
	board_position[17] = w_knight;
	board_position[18] = w_rook;

	for (int i = 21; i <= 28; i++)
	{
		board_position[i] = w_pawn;
	}

	board_position[81] = b_rook;
	board_position[82] = b_king;
	board_position[83] = b_bishop;
	board_position[84] = b_queen;
	board_position[85] = b_king;
	board_position[86] = b_bishop;
	board_position[87] = b_knight; 
	board_position[88] = b_rook;

	for (int i = 71; i <= 78; i++)
	{
		board_position[i] = b_pawn;
	}

	return;
}

string Game::board_pos_to_figure(short board)
{
	switch (board) {
	case w_pawn: return "P";
	case w_bishop: return "B";
	case w_knight: return "N";
	case w_rook: return "R";
	case w_queen: return "Q";
	case w_king: return "K";

	case b_pawn: return "p";
	case b_bishop: return "b";
	case b_knight: return "n";
	case b_rook: return "r";
	case b_queen: return "q";
	case b_king: return "k";

	case empty: return " ";
	default: cout << "Error in board_pos_to_figure() function!" << endl;
	}

	return "Error in board_pos_to_figure() function!";

}


void Game::output_board()
{
	cout << endl << endl;

	int letters = 9;
	cout << "     ---------------------------------" << endl;
	for (int i = 88; i >= 11; i--)
	{
	
		//if you reach end of line 
		if (i % 10 == 0)
		{
			i = i - 2;
			cout << "|" << endl;
			cout << "     ---------------------------------" << endl;
		}

		if (i % 10 == 8)
		{ 
			cout << "  " << --letters << "  ";
		}

		cout << "| " << board_pos_to_figure(board_position[i]) << " ";
		
	}
	cout << "|" << endl
		 << "     ---------------------------------" << endl
		<< "     ";
	for (int i = 97; i <= 104; i++)
	{
		cout << "  " << (char)i << " ";
	}
}
void Game::error_output(int error_num)
{
	string error_msg;

	switch(error_num)
	{
	case 1: error_msg = "Position of piece not in Board";
		break;
	}

	cout << "An error has acured ->  " << error_msg << endl;
	int temp_input;
	cin >> temp_input;

	return;
}

bool Game::is_position_in_board(int position)
{
	//check if first and second integer are in [1,..,8] 
	if ((position <= 88) && (position >= 11) && (((position % 10) >= 1) && ((position % 10) <= 8))) return true;
	return false;
}

bool Game::is_black(int position)
{
	if (position >= 7 && position <= 12) return true;
	if (position >= 1 && position <= 6) return false;
	else error_output(1); 
	return false;
}

bool Game::is_white(int position)
{
	if (position >= 7 && position <= 12) return false;
	if (position >= 1 && position <= 6) return true;
	else error_output(1);
	return false;
}

list <int> Game::list_of_valid_moves(int position_now)
{
	list<int> return_list;
	//Return empty list if position isn't in board
	if (!(is_position_in_board(position_now)))
	{
		error_output(1);
		return return_list;
	}

	/*__________________________________________________________________________________________________________________________________
															case bis bishop & part Queen
	  __________________________________________________________________________________________________________________________________
	*/
	if (   board_position[position_now] == w_bishop || board_position[position_now] == b_bishop
		|| board_position[position_now] == b_queen  || board_position[position_now] == w_queen)
	{
		int next_position;

		//upper right diagonal
		next_position = position_now + 11;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen ) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen ) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen ) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen)  && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}

			next_position = next_position + 11;
		}

		//upper left diagonal
		next_position = position_now + 9;

		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now + 9;
		}


		//lower right diagonal
		next_position = position_now - 9;

		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now - 9;
		}



		//lower left diagonal
		next_position = position_now - 11;

		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now - 11;
		}

	}


	/*__________________________________________________________________________________________________________________________________
													case rook & part Queen
	__________________________________________________________________________________________________________________________________
	*/

	if (board_position[position_now] == w_rook || board_position[position_now] == b_rook
		|| board_position[position_now] == w_queen || board_position[position_now] == b_queen)
	{
		int next_position;

		// upper line 
		next_position = position_now + 10;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now + 10;
		}

		// lower line 
		next_position = position_now - 10;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now - 10;
		}

		// left line 
		next_position = position_now - 1;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now - 1;
		}


		// Right line 
		next_position = position_now + 1;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(position_now);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[position_now])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[position_now]))
				{
					return_list.push_back(position_now);
					break;
				}

			}
			next_position = position_now + 1;
		}

		/*__________________________________________________________________________________________________________________________________
																case Knight
		__________________________________________________________________________________________________________________________________
		*/
		if (board_position[position_now] == w_knight || board_position[position_now] == b_knight)
		{


			int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

			for (int i = 0; i < 8; i++)
			{


				if (is_position_in_board(next_position + knight_addition[i]) == true)
				{

					if (board_position[next_position + knight_addition[i]] == empty)
					{
						return_list.push_back(next_position + knight_addition[i]);
						continue;
					}

					else if ((board_position[position_now] == w_knight && is_white(board_position[next_position + knight_addition[i]]))
						|| (board_position[position_now] == b_knight && is_black(board_position[next_position + knight_addition[i]])))
					{

						continue;
					}
					else if ((board_position[position_now] == w_knight && is_black(board_position[next_position + knight_addition[i]]))
						|| (board_position[position_now] == b_knight && is_white(board_position[next_position + knight_addition[i]])))
					{

						return_list.push_back(next_position + knight_addition[i]);
						continue;
					}

				}

			}
		}

		/*__________________________________________________________________________________________________________________________________
														case white pawn
		__________________________________________________________________________________________________________________________________
		*/

		if(board_position[position_now] == w_pawn)
		{
			if ((is_position_in_board(board_position[position_now + 10] || (board_position[position_now + 10] == empty)) return_list.push_back(position_now + 10);
			
		}


















	}

	return return_list;


}


