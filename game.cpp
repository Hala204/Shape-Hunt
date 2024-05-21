#include "game.h"
#include "gameConfig.h"



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	createToolBar();

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
	int gridHeight = config.windHeight - config.toolBarHeight  - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

void game::randomGenerator()
{
	
	std::srand(static_cast<unsigned int>(std::time(0)));
	window* pw = pWind;

	int gameLevel = 3;// config.level;

	int h = config.windHeight;
	int w = config.windWidth;

	const int maxNumberOfRandomShapes = 7;
	point p[maxNumberOfRandomShapes];
	for (int i = 0; i < 2*gameLevel-1; i++)
	{
		//create random ref point 
		//int random_number = std::rand() % (end - start + 1) + start;
		int random_x = std::rand() % (w - config.homeshape.width - config.homeshape.width + 1) + config.homeshape.width;
		int random_y = std::rand() % (h - config.homeshape.hight - config.homeshape.hight + 1) + config.homeshape.hight;

		// create random rotation angle
		int angles[] = { 90, 180, 270, 360 };

		// Generate a random index in the range 0 to 3
		int randomIndex = std::rand() % 4;

		// Select the random rotation angle
		double randomRotationAngle = angles[randomIndex];

		//create random size 
		int   randomSize= std::rand() % (30 - 10 + 1) + 10; 

		// which random shape
		int random_shape = std::rand() % (4 - 0 + 1) + 0;

		point ShapeRef = { random_x,random_y };

		grid* pGrid = this->getGrid();
		shape* psh0 = nullptr;

		//create a sign shape

		switch (random_shape){
			case 0:
				psh0 = new Sign(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);
				break;

			case 1:
				psh0 = new Rocket(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);
				break;

			case 2:
				 psh0 = new Home(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);
				break;

			case 3:
				 psh0 = new Watch(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);
				break;

			case 4:
				 psh0 = new Car(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);
				break;

			case 5:
				psh0 = new IceCream(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);
				break;

			case 6:
				psh0 = new Fish(this, ShapeRef, RED, randomRotationAngle, randomSize/20);
				pGrid->addShape(psh0);

				break;
		
		
		}

		shapesGrid->draw();
		gameToolbar->drawStart(pWind);
		gameToolbar->drawtoolbar(pWind);
		
	}




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
	case ITM_START_GAME:
		op = new operStartGame(this);
		printMessage("game started... GOOD LUCK !");
		break;
	case ITM_SIGN:
		op = new operAddSign(this);
		printMessage("sign is pressed, you can move it by arrows ");
		break;

	//	break;
	//case ITM_RECT:
	//	op = new operAddRect(this);
	//	printMessage("rectangle is pressed ");

	//	break;
	//case ITM_CIRC:
	//	op = new operAddCirc(this);
	//	printMessage("circle is pressed ");

	//	break;
	//case ITM_TRI:
	//	op = new operAddTri(this);
	//	printMessage("triangle is pressed ");

	//	break;
	case ITM_CAR:
		op = new operAddCar(this);
		printMessage("car is pressed ");
		break;

	case ITM_Home:
		op = new operAddHome(this);
		printMessage("Home is pressed ");
		break;


	case ITM_WATCH:
		op = new operAddWatch(this);
		printMessage("watch is pressed ");
		break;

	case ITM_FISH:
		op = new operAddFish(this);
		printMessage("Fish is pressed ");
		break;

	case ITM_CONE:
		op = new operAddIceCream(this);
		printMessage("cone is pressed ");
		break;

	case ITM_ROCKET:
		op = new operAddRocket(this);
		printMessage("Rocket is pressed ");
		break;

	case ITM_REFRESH:
		printMessage("ITM_REFRESH is pressed ");
		break;
	case ITM_HINT:
		printMessage("ITM_HINT is pressed ");
		break;

	case ITM_SELECT:
		printMessage("ITM_SELECT is pressed ");
		break;

	case ITM_SAVE:
		op = new operSave(this);
		printMessage("ITM_SAVE is pressed ");
		break;
	case ITM_LOAD:
		op = new operLoad(this);
		printMessage("ITM_LOAD is pressed ");
		break;

	case ITM_EXIT:
		op = new operExit(this);
		printMessage("ITM_EXIT is pressed ");
		break;
	case ITM_ROTATE:
		op = new operRotate(this);
		printMessage("ITM_ROTATE is pressed ");

		break;
	case ITM_DEL:
		op = new operDEL(this);
		printMessage("ITM_DELETE is pressed ");

		break;
	case ITM_MINI:
		op = new operMinimize(this);
		printMessage("ITM_DECREASE is pressed ");

		break;
	case ITM_INC:
		op = new operINC(this);
		printMessage("ITM_INCREASE is pressed ");
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

toolbar* game::getToolbar() const
{
	return gameToolbar;
}

void game::setScore(int newScore)
{
	this->score = newScore;
	pWind->SetBrush(BLACK);
	pWind->SetPen(BLACK);
	pWind->SetFont(20, PLAIN, ROMAN);
	pWind->DrawString(config.windWidth / 2, config.toolBarHeight, "Score : " + to_string(config.Score));
}

void game::setLevel(int newLevel)
{
	this->level = newLevel;
	pWind->SetBrush(BLACK);
	pWind->SetPen(BLACK);
	pWind->SetFont(20, PLAIN, ROMAN);
	pWind->DrawString(config.windWidth - 100, config.toolBarHeight, "Level : " + to_string(config.level));

}
void game::setLives(int newLives)
{
	this->level = newLives;
	pWind->SetBrush(BLACK);
	pWind->SetPen(BLACK);
	pWind->SetFont(20, PLAIN, ROMAN);
	pWind->DrawString(5, config.toolBarHeight, "Lives : " + to_string(config.lives));

}



void game::incrementScore(int num)
{
	score += num;
}

void game::decrementScore(int num)
{
	score -= num;
}


////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	char keyPressed;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem=ITM_CNT;
	do
	{

		pWind->GetKeyPress(keyPressed);
		if (shapesGrid->getActiveShape() != nullptr) {
			if (keyPressed) {
				if (keyPressed == 32) // ASCII for space bar
				{
					shapesGrid->handleMatch();
				}
				//printMessage("Ready...");
				//1- Get user click
			}
		}



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
			gameToolbar->drawStart(pWind);
			gameToolbar->drawtoolbar(pWind);

	

		}	

	} while (clickedItem!=ITM_EXIT);
}

////////////////////////////////////////////////////////////////////////////



