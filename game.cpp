#include "game.h"
#include "gameConfig.h"



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}



void game::drawHome(window* &w, color c, int rx, int ry, int size) {
	w->SetPen(BLACK, 2);

	w->SetBrush(c);
	w->DrawRectangle(rx, ry, rx + 1.5 * size, ry + size);

	w->SetBrush(HUGE);
	w->DrawTriangle(rx, ry, 1.5 * size + rx, ry, rx + 1.5 * size / 2, ry - size);

	w->SetBrush(STEELBLUE);
	w->DrawRectangle(rx + (size * .95), ry + (size * 0.15), rx + (1.5 * size * .9), ry + (size * .5));

	w->SetBrush(BROWN);
	w->DrawRectangle(rx + (size * .2), ry + (size * 0.42), rx + (size * .5), ry + (size));

	w->DrawLine(rx + (size * .42), ry + (size * .75), rx + (size * .43), ry + (size * .76));
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		printMessage("sign is pressed ");

		break;
	case ITM_RECT:
		op = new operAddRect(this);
		printMessage("rectangle is pressed ");

		break;
	case ITM_CIRC:
		op = new operAddCirc(this);
		printMessage("circle is pressed ");

		break;
	case ITM_TRI:
		op = new operAddTri(this);
		printMessage("triangle is pressed ");

		break;

	case ITM_WATCH:
		printMessage("watch is pressed ");
		break;
	case ITM_HOME:
		printMessage("home is pressed ");
		drawHome(pWind , config.fillColor, config.RefX, config.RefY, 50);
		break;
	case ITM_CONE:
		printMessage("cone is pressed ");

		break;
	case ITM_ROCKET:
		printMessage("Rocket is pressed ");
		break;
	case ITM_INCREASE:
		printMessage("ITM_INCREASE is pressed ");
		break;
	case ITM_DECREASE:
		printMessage("ITM_DECREASE is pressed ");
		break;
	case ITM_ROTATE:
		printMessage("ITM_ROTATE is pressed ");
		break;
	case ITM_REFRESH:
		printMessage("ITM_REFRESH is pressed ");
		break;
	case ITM_HINT:
		printMessage("ITM_HINT is pressed ");
		break;
	case ITM_DELETE:
		printMessage("ITM_DELETE is pressed ");
		break;
	case ITM_SELECT:
		printMessage("ITM_SELECT is pressed ");
		break;
	case ITM_SAVE:
		printMessage("ITM_DELETE is pressed ");
		break;
	case ITM_EXIT:
		printMessage("ITM_DELETE is pressed ");
		break;
	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(BLACK, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}



////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem=ITM_CNT;
	do
	{
		//printMessage("Ready...");
		//1- Get user click
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem=gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action
			shapesGrid->draw();

		}	

	} while (clickedItem!=ITM_EXIT);
}

