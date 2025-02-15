#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"
#include "gameConfig.h"



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	int level;
	int score;
	int lives;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	void randomGenerator();
	void cleanUp();


	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	toolbar* getToolbar() const;
	void drawHome(window* &w, color c, int rx, int ry, int size);

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);

	int getLevel() const { return this->level; }
	int getScore() const { return score; }
	int getLives() const { return this->lives; }


	void setLevel(int newLevel);

	void setScore(int newScore);

	void setLives(int newLives);
	void incrementScore(int num);
	void decrementScore(int num);



	void run();	//start the game

};

