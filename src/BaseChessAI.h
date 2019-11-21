#pragma once

//libraries
#include <iostream>
#include <string>
#include <windows.h>  
#include <list> 
#include <algorithm>
#include <iterator>

//classes
#include "src/Game.h"

//shortcuts
using namespace std;

class BaseChessAI : public Game
{
	int color = 0; //0 white 1 black
	int fiel[89] = { 0 }; //initialises field with 0 entries

	list<int> mypieces(int fieldtemp[89], int colortemp); //list of my pieces
	list<int> mymoves(int fieldtemp[89], int colortemp); //list of my moves
	list<int> enemypieces(int fieldtemp[89], int colortemp); //list of enemy pieces - your own color in colortemp
	list<int> enemymoves(int fieldtemp[89], int colortemp); //list of enemy moves - your own color in colortemp
	list<int> enemyattackedfields(int fieldtemp[89], int colortemp); // list of enemy attack fields in this composition

};

