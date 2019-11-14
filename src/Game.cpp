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
	//Colors
	int colorbonw = 112;
	int colorbonb = 96;
	int colorwonw = 127;
	int colorwonb = 111;
	int colorleg = 15;

	std::cout << "Hello World!\n";

	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorleg);

	//ROW 1
	cout << endl;
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



	cout << endl;
	//cin.get(); // wait
	
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