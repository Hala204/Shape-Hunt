#pragma once
#include "gameConfig.h"
////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class game;
class toolbar
{

private:
	int height, width;	
	int Level, Score, Lives;
	string toolbarItemImages[ITM_CNT]; //array to hold paths to images of diffrent items in the toolbar
	game* pGame;

public:
	toolbar(game* r_pGame);
	toolbarItem getItemClicked(int x);	//handles clicks on toolbar icons, returns the "enum" of the clicekd item
	void drawStart(window* wind);
	void drawtoolbar(game* r_pGame);
	int getLevel() const;
	int getScore() const;
	int getRemainingLives() const;

};




