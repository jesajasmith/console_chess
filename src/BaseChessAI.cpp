#include "BaseChessAI.h"

list<int> BaseChessAI::mymoves(int fieldtemp[89], int colortemp)
{
	for (size_t i = 10; i <= 88; i++)
	{
		board_position[i] = fieldtemp[i];
	}
 
	list<int> listmoves;
	list<int> listmypieces = mypieces(fieldtemp, colortemp);

	int sizetemp = listmypieces.size();

	for (size_t i = 1; i <= sizetemp; i++)
	{
		list<int> movesforthatpiece = list_of_valid_moves(*listmypieces.begin());

		int sizetemp2 = movesforthatpiece.size();
		for (size_t i = 1; i <= sizetemp2; i++)
		{
			listmoves.push_front((*listmypieces.begin() * 100 + *movesforthatpiece.begin()));
			movesforthatpiece.pop_front();
		}

		listmypieces.pop_front();
	}

	return listmoves;
}

list<int> BaseChessAI::mypieces(int fieldtemp[89], int colortemp)
{

	list<int> listmposenemypieces;

	if (colortemp)
	{
		for (size_t i = 11; i <= 88; i++)
		{
			if ((fieldtemp[i] <= 6) && (fieldtemp[i] > 0))
			{
				listmposenemypieces.push_back(i);
			}
		}
	}
	else
	{
		for (size_t i = 11; i <= 88; i++)
		{
			if (fieldtemp[i] >= 7 && (fieldtemp[i] < 13))
			{
				listmposenemypieces.push_back(i);
			}
		}
	}

	return listmposenemypieces;
}

list<int> BaseChessAI::enemypieces(int fieldtemp[89], int colortemp)
{
	int colorenemy = 1; if (colortemp) { colorenemy = 0; }

	list<int> listmposenemypieces;

	if (colorenemy)
	{
		for (size_t i = 11; i <= 88; i++)
		{
			if ((fieldtemp[i] <= 6) && (fieldtemp[i] > 0))
			{
				listmposenemypieces.push_back(i);
			}
		}
	}
	else
	{
		for (size_t i = 11; i <= 88; i++)
		{
			if (fieldtemp[i] >= 7 && (fieldtemp[i] < 13))
			{
				listmposenemypieces.push_back(i);
			}
		}
	}
	return listmposenemypieces;
}

list<int> BaseChessAI::enemymoves(int fieldtemp[89], int colortemp)
{
	for (size_t i = 10; i <= 88; i++)
	{
		board_position[i] = fieldtemp[i];
	}

	list<int> listmoves;
	list<int> listmypieces = enemypieces(fieldtemp, colortemp);

	int sizetemp = listmypieces.size();

	for (size_t i = 1; i <= sizetemp; i++)
	{
		list<int> movesforthatpiece = list_of_valid_moves(*listmypieces.begin());

		int sizetemp2 = movesforthatpiece.size();
		for (size_t i = 1; i <= sizetemp2; i++)
		{
			listmoves.push_front((*listmypieces.begin() * 100 + *movesforthatpiece.begin()));
			movesforthatpiece.pop_front();
		}

		listmypieces.pop_front();
	}

	return listmoves;
}

list<int> BaseChessAI::enemyattackedfields(int fieldtemp[89], int colortemp)
{
	int colorenemy = 1; if (colortemp) { colorenemy = 0; }

	for (size_t i = 10; i <= 88; i++)
	{
		board_position[i] = fieldtemp[i];
	}

	list<int> listmoves;
	list<int> listmypieces = enemypieces(fieldtemp, colortemp);

	int sizetemp = listmypieces.size();

	for (size_t i = 1; i <= sizetemp; i++)
	{
		list<int> movesforthatpiece = list_of_valid_moves(*listmypieces.begin());

		int sizetemp2 = movesforthatpiece.size();
		for (size_t i = 1; i <= sizetemp2; i++)
		{
			listmoves.push_front(*movesforthatpiece.begin());
			movesforthatpiece.pop_front();
		}

		listmypieces.pop_front();
	}

	return listmoves;
}