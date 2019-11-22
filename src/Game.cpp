#include "Game.h"
using namespace std;


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
	board_position[82] = b_knight;
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

char Game::inttochar(int inttemp)
{

	char temp;
	switch (inttemp)
	{
	case 1:
		temp = 'P';
		break;
	case 2:
		temp = 'K';
		break;
	case 3:
		temp = 'B';
		break;
	case 4:
		temp = 'R';
		break;
	case 5:
		temp = 'Q';
		break;
	case 6:
		temp = '+';
		break;
	case 7:
		temp = 'P';
		break;
	case 8:
		temp = 'K';
		break;
	case 9:
		temp = 'B';
		break;
	case 10:
		temp = 'R';
		break;
	case 11:
		temp = 'Q';
		break;
	case 12:
		temp = '+';
		break;

	default:
		temp = ' ';
	}

	return temp;
}

void Game::visualise()
{
	using namespace std;
	//Colors 
	int settemp = boardtheme;

	//Theme one standart
	int colorbonw = 112;
	int colorbonb = 96;
	int colorwonw = 127;
	int colorwonb = 111;
	int colorleg = 15;

	//Theme 1 Grey and Beige
	if (settemp == 1) {
		colorbonw = 112;
		colorbonb = 96;
		colorwonw = 127;
		colorwonb = 111;
		colorleg = 15;
	}
	//Theme 2 Light and Dark Grey
	if (settemp == 2) {
		colorbonw = 112;
		colorbonb = 128;
		colorwonw = 127;
		colorwonb = 143;
		colorleg = 15;
	}
	//Theme Colorful
	if (settemp == 3) {
		colorbonw = 73;
		colorbonb = 83;
		colorwonw = 74;
		colorwonb = 90;//
		colorleg = 15;
	}

	std::cout << "Chess Board!\n";

	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorleg);

	cout << endl;

	cout << "   A  B  C  D  E  F  G  H  "<< endl;
	//ROW 1
	
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "1 ";
	for (size_t i1 = 11; i1 <= 18; i1++)
	{
		int colortemp;
		if ((i1 % 2))
		{
			if (board_position[i1] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i1] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i1]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 1" << endl;

	//ROW 2
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "2 ";
	for (size_t i2 = 21; i2 <= 28; i2++)
	{
		int colortemp;
		if (((i2 + 1) % 2))
		{
			if (board_position[i2] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i2] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i2]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 2" << endl;

	//ROW 3
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "3 ";
	for (size_t i3 = 31; i3 <= 38; i3++)
	{
		int colortemp;
		if (((i3) % 2))
		{
			if (board_position[i3] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i3] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i3]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 3" << endl;

	//ROW 4
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "4 ";
	for (size_t i4 = 41; i4 <= 48; i4++)
	{
		int colortemp;
		if (((i4 + 1) % 2))
		{
			if (board_position[i4] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i4] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i4]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 4" << endl;

	//ROW 5
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "5 ";
	for (size_t i5 = 51; i5 <= 58; i5++)
	{
		int colortemp;
		if (((i5) % 2))
		{
			if (board_position[i5] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i5] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i5]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 5" << endl;

	//ROW 6
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "6 ";
	for (size_t i6 = 61; i6 <= 68; i6++)
	{
		int colortemp;
		if (((i6 + 1) % 2))
		{
			if (board_position[i6] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i6] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i6]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 6" << endl;

	//ROW 7
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "7 ";
	for (size_t i7 = 71; i7 <= 78; i7++)
	{
		int colortemp;
		if (((i7) % 2))
		{
			if (board_position[i7] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i7] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i7]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 7" << endl;

	//ROW 8
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "8 ";
	for (size_t i8 = 81; i8 <= 88; i8++)
	{
		int colortemp;
		if (((i8 + 1) % 2))
		{
			if (board_position[i8] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i8] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		cout << " " << inttochar(board_position[i8]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 8" << endl;
	cout << "   A  B  C  D  E  F  G  H  " << endl;



	cout << endl;
	//cin.get(); // wait
	
}

void Game::visualisemoves(list<int> listvalidmoves)
{

	//Colors 
	int settemp = boardtheme;

	//Theme one standart
	int colorbonw = 112;
	int colorbonb = 96;
	int colorwonw = 127;
	int colorwonb = 111;
	int colorleg = 15;

	//Theme 1 Grey and Beige
	if (settemp == 1) {
		colorbonw = 112;
		colorbonb = 96;
		colorwonw = 127;
		colorwonb = 111;
		colorleg = 15;
	}
	//Theme 2 Light and Dark Grey
	if (settemp == 2) {
		colorbonw = 112;
		colorbonb = 128;
		colorwonw = 127;
		colorwonb = 143;
		colorleg = 15;
	}
	//Theme Colorful
	if (settemp == 3) {
		colorbonw = 73;
		colorbonb = 83;
		colorwonw = 74;
		colorwonb = 90;//
		colorleg = 15;
	}

	std::cout << "Chess Board!\n";

	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorleg);

	cout << endl;

	cout << "   A  B  C  D  E  F  G  H  " << endl;
	//ROW 1
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "1 ";
	for (size_t i1 = 11; i1 <= 18; i1++)
	{
		int colortemp;
		if ((i1 % 2))
		{
			if (board_position[i1] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i1] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i1) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i1] <= 6)
			{
				colormarker = 79;
				if (quersum(i1) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i1) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
		
		cout << " " << inttochar(board_position[i1]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 1" << endl;

	//ROW 2
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "2 ";
	for (size_t i2 = 21; i2 <= 28; i2++)
	{
		int colortemp;
		if (((i2 + 1) % 2))
		{
			if (board_position[i2] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i2] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);

		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i2) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i2] <= 6)
			{
				colormarker = 79;
				if (quersum(i2) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i2) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
		cout << " " << inttochar(board_position[i2]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 2" << endl;

	//ROW 3
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "3 ";
	for (size_t i3 = 31; i3 <= 38; i3++)
	{
		int colortemp;
		if (((i3) % 2))
		{
			if (board_position[i3] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i3] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i3) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i3] <= 6)
			{
				colormarker = 79;
				if (quersum(i3) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i3) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
		cout << " " << inttochar(board_position[i3]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 3" << endl;

	//ROW 4
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "4 ";
	for (size_t i4 = 41; i4 <= 48; i4++)
	{
		int colortemp;
		if (((i4 + 1) % 2))
		{
			if (board_position[i4] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i4] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i4) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i4] <= 6)
			{
				colormarker = 79;
				if (quersum(i4) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i4) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
		cout << " " << inttochar(board_position[i4]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 4" << endl;

	//ROW 5
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "5 ";
	for (size_t i5 = 51; i5 <= 58; i5++)
	{
		int colortemp;
		if (((i5) % 2))
		{
			if (board_position[i5] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i5] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i5) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i5] <= 6)
			{
				colormarker = 79;
				if (quersum(i5) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i5) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
		cout << " " << inttochar(board_position[i5]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 5" << endl;

	//ROW 6
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "6 ";
	for (size_t i6 = 61; i6 <= 68; i6++)
	{
		int colortemp;
		if (((i6 + 1) % 2))
		{
			if (board_position[i6] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i6] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i6) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i6] <= 6)
			{
				colormarker = 79;
				if (quersum(i6) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i6) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
		cout << " " << inttochar(board_position[i6]) << " ";
	}
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 6" << endl;

	//ROW 7
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "7 ";
	for (size_t i7 = 71; i7 <= 78; i7++)
	{
		int colortemp;
		if (((i7) % 2))
		{
			if (board_position[i7] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i7] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i7) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i7] <= 6)
			{
				colormarker = 79;
				if (quersum(i7) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i7) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}

			SetConsoleTextAttribute(hConsole, colormarker);
		}
			cout << " " << inttochar(board_position[i7]) << " ";
		}
	
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << " 7" << endl;

	//ROW 8
	SetConsoleTextAttribute(hConsole, colorleg);
	cout << "8 ";
	for (size_t i8 = 81; i8 <= 88; i8++)
	{
		int colortemp;
		if (((i8 + 1) % 2))
		{
			if (board_position[i8] <= 6) { colortemp = colorwonw; }
			else { colortemp = colorbonw; }
		}
		else
		{
			if (board_position[i8] <= 6) { colortemp = colorwonb; }
			else { colortemp = colorbonb; }
		}


		SetConsoleTextAttribute(hConsole, colortemp);
		if ((std::find(listvalidmoves.begin(), listvalidmoves.end(), i8) != listvalidmoves.end()))
		{
			int colormarker = 64;
			if (board_position[i8] <= 6)
			{
				colormarker = 79;
				if (quersum(i8) % 2) {
					colormarker = 79;
				}
				else
				{
					colormarker = 207;
				}
			}
			else
			{
				colormarker = 64;
				if (quersum(i8) % 2) {
					colormarker = 64;
				}
				else
				{
					colormarker = 192;
				}
			}
			SetConsoleTextAttribute(hConsole, colormarker);
		}
			cout << " " << inttochar(board_position[i8]) << " ";
		}
		SetConsoleTextAttribute(hConsole, colorleg);

		cout << " 8" << endl;
		cout << "   A  B  C  D  E  F  G  H  " << endl;



		cout << endl;
		//cin.get(); // wait
	}



int Game::quersum(int intemp)
{
	int outtemp = 0;
	while (intemp > 0) {
		outtemp += intemp % 10;
		intemp /= 10;
	}
	return outtemp;
}

int Game::playmove(int movefrom, int moveto, int valid)
{


	//Overwrite array

	//Confirm kill
	int killconftemp = 0;
	int killtemp = 0;
	char killchartemp = ' ';
	string killtypetemp = "";

		if (board_position[moveto] != 0) 
		{
			killtemp = board_position[moveto];
			killchartemp = inttochar(killtemp);
			killconftemp = 1;
		}

		if (killtemp <= 6)
		{
			killtypetemp = "white";
		}
		else
		{
			killtypetemp = "black";
		}


	board_position[movefrom] = 0;
	board_position[moveto] = board_position[movefrom];


	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << movefrom <<" moved to " << moveto;
	if (killconftemp)
	{
		cout << killtypetemp << killchartemp << "was killed";
	}
	cout << endl;

	return 0;
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
	case 2: error_msg = "King missing on Board";
		break;
	case 3: error_msg = "Wrong piece selected";
		break;
	}

	cout << "An error has acured ->  " << error_msg << endl;
	int temp_input;
	cin >> temp_input;

	return;
}

bool Game::is_king_check(int position)
{
	if (!is_position_in_board(position))
	{
		error_output(1);
		return false;
	}

	if (board_position[position] == w_king)
	{
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(position + knight_addition[i])) continue;
			if (board_position[position + knight_addition[i]] == b_knight) return true;
		}

		//check for pawn

		if (is_position_in_board(position + 9) || board_position[position + 9] == b_pawn) return true;
		if (is_position_in_board(position + 11) || board_position[position + 9] == b_pawn) return true;

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board_position[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_white(board_position[next_position])) break;
				if (is_black(board_position[next_position]))
				{
					if (board_position[next_position] == b_bishop || board_position[next_position] == b_queen) return true;
					else break;
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
				if (board_position[next_position] == empty)
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_white(board_position[next_position])) break;

				if (is_black(board_position[next_position]))
				{
					if (board_position[next_position] == b_rook || board_position[next_position] == b_queen) return true;
					else break;
				}

			}

		}
		return false;
	}


	else if (board_position[position] == b_king)
	{
		//check for Knight
		int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

		for (int i = 0; i < 8; i++)
		{
			if (!is_position_in_board(position + knight_addition[i])) continue;
			if (board_position[position + knight_addition[i]] == w_knight) return true;
		}

		//check for pawn

		if (is_position_in_board(position - 9) && board_position[position - 9] == w_pawn) return true;
		if (is_position_in_board(position - 11) && board_position[position - 9] == w_pawn) return true;

		//check for bishop & part queen

		int next_position;
		int bishop_addition[4] = { 9,11,-9,-11 };

		// go through all diagonals

		for (int i = 0; i <= 3; i++)
		{

			next_position = position + bishop_addition[i];

			while (is_position_in_board(next_position))
			{
				if (board_position[next_position] == empty)
				{
					next_position = next_position + bishop_addition[i];
					continue;
				}

				if (is_black(board_position[next_position])) break;
				if (is_white(board_position[next_position]))
				{
					if (board_position[next_position] == w_bishop || board_position[next_position] == w_queen) return true;
					else break;
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
				if (board_position[next_position] == empty)
			
				{
					next_position = next_position + rook_addition[i];
					continue;
				}

				if (is_black(board_position[next_position])) break;

				if (is_white(board_position[next_position]))
				{
					if (board_position[next_position] == w_rook || board_position[next_position] == w_queen) return true;
					else break;
				}

			}

		}

		return false;

	}

	

	else error_output(3);
	return false;
}

bool Game::is_king_check(int position, int * temp_board)
{
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
		if (is_position_in_board(position + 11) && temp_board[position + 9] == b_pawn) return true;

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
					else break;
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
					else break;
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
		if (is_position_in_board(position - 11) && temp_board[position - 9] == w_pawn) return true;

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
					else break;
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
					else break;
				}
			}

		}

		return false;

	}



	else error_output(3);
	return false;
}

int Game::find_king(int color_king)
{
	if (color_king == w_king)
	{
		for (int i = 11; i <= 88; i++)
		{
			if (board_position[i] == w_king) return i;
		}
	}

	else if (color_king == b_king)
	{
		for (int i = 11; i <= 88; i++)
		{
			if (board_position[i] == b_king) return i;
		}
	}

	else error_output(3);
	return 11;
}

bool Game::is_position_in_board(int position)
{
	//check if first and second integer are in [1,..,8] 
	if (((position <= 88) && (position >= 11)) && (((position % 10) >= 1) && ((position % 10) <= 8))) return true;
	return false;
}

bool Game::is_black(int position)
{
	if (position >= 7 && position <= 12) return true;
	if (position >= 1 && position <= 6) return false;
	//else error_output(1); 
	return false;
}

bool Game::is_white(int position)
{
	if (position >= 7 && position <= 12) return false;
	if (position >= 1 && position <= 6) return true;
	//else error_output(1);
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
	// Return empty list if board is empty
	if (board_position[position_now] == empty) return return_list;

	/*
	//Check if King is in check
	if (is_white(board_position[position_now]) && !(board_position[position_now] == w_king))
	{
		if (is_king_check(find_king(w_king))) return return_list;
	}
	if (is_black(board_position[position_now]) && !(board_position[position_now] == b_king))
	{
		if (is_king_check(find_king(b_king))) return return_list;
	}
	*/

	/*__________________________________________________________________________________________________________________________________
														is piece pinned
	__________________________________________________________________________________________________________________________________
	*/

	int position_king = 0;  
	int cursor = 0;
	int addition = 0;

												//##### Case white pieces ####

	bool no_pieces_between_king_and_position_now = true;

	if (is_white(board_position[position_now]) && !(board_position[position_now] == w_king))
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
				if (board_position[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}
			if (no_pieces_between_king_and_position_now == true)
			{

				cursor = position_now + addition;

				while (is_position_in_board(cursor))
				{
					if (board_position[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_white(board_position[cursor])) break;
					if (board_position[cursor] == b_queen || board_position[cursor] == b_rook)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board_position[position_now] == w_queen || board_position[position_now] == w_rook)
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
						else if (board_position[position_now] == w_pawn)
						{
							if (addition == 10)
							{
								if (board_position[position_now + addition] == empty)
								{
									return_list.push_back(position_now + addition);
									if (((position_now - (position_now % 10)) == 1) || board_position[position_now + addition + addition] == empty)
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
				if (board_position[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}

			if (no_pieces_between_king_and_position_now == true)
			{
				cursor = position_now + addition;
				while (is_position_in_board(cursor))
				{
					if (board_position[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_white(board_position[cursor])) break;
					if (board_position[cursor] == b_queen || board_position[cursor] == b_bishop)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board_position[position_now] == w_queen || board_position[position_now] == w_bishop)
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

	if (is_black(board_position[position_now]) && !(board_position[position_now] == b_king))
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
				if (board_position[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}
			if (no_pieces_between_king_and_position_now == true)
			{

				cursor = position_now + addition;

				while (is_position_in_board(cursor))
				{
					if (board_position[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_black(board_position[cursor])) break;
					if (board_position[cursor] == w_queen || board_position[cursor] == w_rook)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board_position[position_now] == b_queen || board_position[position_now] == b_rook)
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
						else if (board_position[position_now] == b_pawn)
						{
							if (addition == -10)
							{
								if (board_position[position_now + addition] == empty)
								{
									return_list.push_back(position_now + addition);
									if (((position_now - (position_now % 10)) == 7) || board_position[position_now + addition + addition] == empty)
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
				if (board_position[cursor] == empty) temp = true;
				no_pieces_between_king_and_position_now = no_pieces_between_king_and_position_now && temp;
				cursor = cursor + addition;
			}

			if (no_pieces_between_king_and_position_now == true)
			{
				cursor = position_now + addition;
				while (is_position_in_board(cursor))
				{
					if (board_position[cursor] == empty)
					{
						cursor = cursor + addition;
						continue;
					}
					if (is_black(board_position[cursor])) break;
					if (board_position[cursor] == w_queen || board_position[cursor] == w_bishop)
					{
						//Is my pined piece a rook or queen so it can defet the oposing rook or queen
						if (board_position[position_now] == b_queen || board_position[position_now] == b_bishop)
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
	if (board_position[position_now] == w_bishop || board_position[position_now] == b_bishop
		|| board_position[position_now] == b_queen || board_position[position_now] == w_queen)
	{
		int next_position;

		//upper right diagonal
		next_position = position_now + 11;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position]))
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
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position]))
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
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position]))
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
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_bishop || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_bishop || board_position[position_now] == b_queen) && is_black(board_position[next_position]))
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

	if (board_position[position_now] == w_rook || board_position[position_now] == b_rook
		|| board_position[position_now] == w_queen || board_position[position_now] == b_queen)
	{
		int next_position;

		// upper line 
		next_position = position_now + 10;
		while (is_position_in_board(next_position) == true)
		{
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_white(board_position[next_position]))
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
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_white(board_position[next_position]))
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
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_white(board_position[next_position]))
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
			if (board_position[next_position] == empty) return_list.push_back(next_position);
			else
			{
				//What to do if a piece is in your way
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_white(board_position[next_position])) break;
				if ((board_position[position_now] == w_rook || board_position[position_now] == w_queen) && is_black(board_position[next_position]))
				{
					return_list.push_back(next_position);
					break;
				}
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_black(board_position[next_position])) break;
				if ((board_position[position_now] == b_rook || board_position[position_now] == b_queen) && is_white(board_position[next_position]))
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
		if (board_position[position_now] == w_knight || board_position[position_now] == b_knight)
		{


			int knight_addition[8] = { 19, 21 ,12, -8, -19, -21, -12, 8 };

			for (int i = 0; i < 8; i++)
			{


				if (is_position_in_board(position_now + knight_addition[i]) == true)
				{

					if (board_position[position_now + knight_addition[i]] == empty)
					{
						return_list.push_back(position_now + knight_addition[i]);
						continue;
					}

					else if ((board_position[position_now] == w_knight && is_white(board_position[position_now + knight_addition[i]]))
						|| (board_position[position_now] == b_knight && is_black(board_position[position_now + knight_addition[i]])))
					{

						continue;
					}
					else if ((board_position[position_now] == w_knight && is_black(board_position[position_now + knight_addition[i]]))
						|| (board_position[position_now] == b_knight && is_white(board_position[position_now + knight_addition[i]])))
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

		if (board_position[position_now] == w_pawn)
		{
			if ((is_position_in_board(position_now + 10)) && (board_position[position_now + 10] == empty)) return_list.push_back(position_now + 10);
			if ((is_position_in_board(position_now + 9)) && is_black((board_position[position_now + 9]))) return_list.push_back(position_now + 9);
			if ((is_position_in_board(position_now + 11)) && is_black((board_position[position_now + 11]))) return_list.push_back(position_now + 11);
		}



		/*__________________________________________________________________________________________________________________________________
													case black pawn
		__________________________________________________________________________________________________________________________________
		*/

		if (board_position[position_now] == b_pawn)
		{
			if ((is_position_in_board(position_now - 10)) && (board_position[position_now - 10] == empty)) return_list.push_back(position_now - 10);
			if ((is_position_in_board(position_now - 9)) && is_white((board_position[position_now - 9]))) return_list.push_back(position_now - 9);
			if ((is_position_in_board(position_now - 11)) && is_white((board_position[position_now - 11]))) return_list.push_back(position_now - 11);
		}



		/*__________________________________________________________________________________________________________________________________
													case king
		__________________________________________________________________________________________________________________________________
		*/

		int temp_board[89];
			for (int i = 0; i <= 88; i++)
			{
				temp_board[i] = board_position[i];
			}
			temp_board[position_now] = empty;

			bool enemy_king_is_not_one_field_away = true;

											//###### case white king #####

		if (board_position[position_now] == w_king)
		{
			int king_addition[8] = { 9,10,11,1,-11,-10,-9,-1 };

			for (int i = 0; i <= 7; i++)

			{
				enemy_king_is_not_one_field_away = true;
				if ((board_position[position_now + king_addition[i]] == empty || is_black(board_position[position_now + king_addition[i]])) && (is_position_in_board(position_now + king_addition[i])))
				{
					for (int j = 0; j <= 7; j++)
					{
						if (is_position_in_board(position_now + king_addition[i] + king_addition[j]))
							enemy_king_is_not_one_field_away = enemy_king_is_not_one_field_away && ((board_position[position_now + king_addition[i] + king_addition[j]]) != b_king);
					}

					if (enemy_king_is_not_one_field_away == true)
					{
						int temp_piece = temp_board[position_now + king_addition[i]];
						temp_board[position_now + king_addition[i]] = w_king;
						if (is_king_check(position_now + king_addition[i], &temp_board[0]) != true) return_list.push_back(position_now + king_addition[i]);
						temp_board[position_now + king_addition[i]] = temp_piece;
					}

				}
			}
		}

														//###### case black king ##### 
		enemy_king_is_not_one_field_away = true;

		if (board_position[position_now] == b_king)
		{
			int king_addition[8] = { 9,10,11,1,-11,-10,-9,-1 };

			for (int i = 0; i <= 7; i++)

			{
				enemy_king_is_not_one_field_away = true;
				if ((board_position[position_now + king_addition[i]] == empty || is_white(board_position[position_now + king_addition[i]])) 
					&& (is_position_in_board(position_now + king_addition[i])))
				{
					for (int j = 0; j <= 7; j++)
					{
						if (is_position_in_board(position_now + king_addition[i] + king_addition[j]))
							enemy_king_is_not_one_field_away = enemy_king_is_not_one_field_away 
							&& ((board_position[position_now + king_addition[i] + king_addition[j]]) != w_king);
					}

					if (enemy_king_is_not_one_field_away == true)
					{
						int temp_piece = temp_board[position_now + king_addition[i]];
						temp_board[position_now + king_addition[i]] = b_king;
						if (is_king_check(position_now + king_addition[i], &temp_board[0]) != true) return_list.push_back(position_now + king_addition[i]);
						temp_board[position_now + king_addition[i]] = temp_piece;
					}

				}
			}
		}



	








		cout << return_list.size();
		return return_list;

	}

	




