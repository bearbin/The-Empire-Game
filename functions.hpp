#include <string>
#include <iostream>
#include "player.hpp"

using namespace std;

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

static player realPlayer[9];
bool save(string);
bool load(string);
void game();
int getPlayerNumbers();
void visitCity(int,int);
void turn(int);

#endif // FUNCTIONS_H_INCLUDED
