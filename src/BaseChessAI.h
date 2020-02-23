#pragma once

//libraries
#include <iostream>
#include <string>
#include <windows.h>  
#include <list>
#include <algorithm>
#include <iterator>

//classes
#include "Game.h"

//shortcuts
using namespace std;

//  Comments
//	!!! format move 21 32 = 2132 move 21 to 32 !!!

class BaseChessAI : public Game
{
public:
	//constructor
	BaseChessAI();
	virtual ~BaseChessAI();

	//internal variables
	int color = 1; //1 white 0 black
	int field[89] = { 0 }; //initialises field with 0 entries

	//variable set functions
	void setcolor(int colortemp);
	void sethardfield(int fieldtemp[89]); //hardcopy into field
	void sethardboard(int fieldtemp[89]); //hardcopy into boardposition(from game)

	//helpful functions
	list<int> convertlisttomovesfrom(list<int> listtemp); //convert a move to only movesfrom
	list<int> convertlisttomovesto(list<int> listtemp);  //convert a move to only movesto
	list<int> sortandcleanlist(list<int> listtemp); //removes duplicates and sorts list

	//listfunctions
	list<int> mypieces(int fieldtemp[89], int colortemp); //list of my pieces
	list<int> mymoves(int fieldtemp[89], int colortemp); //list of my moves
	list<int> enemypieces(int fieldtemp[89], int colortemp); //list of enemy pieces - your own color in colortemp
	list<int> enemymoves(int fieldtemp[89], int colortemp); //list of enemy moves - your own color in colortemp
	list<int> enemyattackedfields(int fieldtemp[89], int colortemp); // list of enemy attack fields in this composition

};

