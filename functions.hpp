#include <string>
#include <iostream>
#include "player.hpp"

using namespace std;

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

static int currentTurn = 0, amountOfTurns;
static short saveSlot, currentPlayer, playerNumbers;
static player realPlayer[9];

// Saves a copy of the current game at file param1
bool save(short);
void game();
int getPlayerNumbers();
void visitCity(int,int);
void turn(int);

#endif // FUNCTIONS_H_INCLUDED
