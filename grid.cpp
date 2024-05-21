#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <iostream>

grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
	{
		delete shapeList[i];
		shapeList[i] = nullptr;
	}
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->draw();
	//this->p_toolbar->drawStart(pWind);

}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail

	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;


	return true;
	

}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}

shape* grid::getActiveShape()
{
	return activeShape;
}

void grid::clearGrid()
{
	if (activeShape != nullptr)
	{
		delete activeShape;
		activeShape = nullptr;
		this->draw();
	}
}




void grid::SaveShapes(ofstream& OutFile)
{
	if (shapeCount > 0)
		OutFile << shapeCount << "\n";
	for (int i = 0; i < shapeCount; i++)
	{
		shapeList[i]->Save(OutFile);
	}
}


void grid::LoadShapes(ifstream& InFile)
{
	int shapecount;
	InFile >> shapecount;
	for (int i = 0; i < shapecount; i++)
	{
		int shapetype, x, y;
		unsigned char red, green, blue;
		InFile >> shapetype >> x >> y >> red >> green >> blue;
		point pnt;
		pnt.x = x;
		pnt.y = y;
		color clr(red, green, blue);
		shape* sh = nullptr;

		int _x = x;
		int _y = y;
		point ShapeRef = { _x,_y };
		grid* pGrid = this->pGame->getGrid();
		shape* psh0 = nullptr;

			switch (shapetype) 
			{
			case SIGN:
				psh0 = new Sign(pGame, pnt, clr);
				pGrid->addShape(psh0);
				break;

			case ROCKET:
				psh0 = new Rocket(pGame, pnt, clr);
				pGrid->addShape(psh0);
				break;

			case HOME:
				psh0 = new Home(pGame, pnt, clr);
				pGrid->addShape(psh0);
				break;

			case WATCH:
				psh0 = new Watch(pGame, pnt, clr);
				pGrid->addShape(psh0);
				break;

			case CAR:
				psh0 = new Car(pGame, pnt, clr);
				pGrid->addShape(psh0);
				break;

			case ICECREAM:
				psh0 = new IceCream(pGame, pnt, clr);
				pGrid->addShape(psh0);
				break;

			case FISH:
				psh0 = new Fish(pGame, pnt, clr);
				pGrid->addShape(psh0);

				break;


			}

			this->pGame->getGrid()->draw();
			this->pGame->getToolbar()->drawStart(this->pGame->getWind());
			this->pGame->getToolbar()->drawtoolbar(this->pGame->getWind());

		
	}



}


bool grid::handleMatch() {
	// Loop through shapes to find if the click is inside any shape
	for (int i = 0; i < shapeCount; i++) {
		// Check if the active shape and the clicked shape match
		if (activeShape->Match(shapeList[i])) {
			// Match found, print message and delete both shapes
			pGame->printMessage("Match Successed, KEEP UP THE GOOD WORK!");
			delete activeShape;
			delete shapeList[i];
			activeShape = nullptr;
			shapeList[i] = nullptr;
			draw();
			pGame->incrementScore(2);// Redraw the grid without the deleted shapes
			shapeCount--;
			break;
		}
		else {
			// Shapes don't match, print message
			pGame->printMessage("Match Failed, TRY AFAIN!");
			//pGame->decrementScore(0);
		}
	}
	int temp = shapeCount;
	if (temp == 0) {
		temp++; 
		pGame->setLevel(pGame->getLevel() + 1);
		pGame->clearStatusBar();

		pGame->printMessage("You moved up to level" + to_string(pGame->getLevel()));
		return true;

	}

}
//void grid::selectgamelevel()
//{
//
//	pGame->printMessage("please Enter your game level");
//	string slevel = pGame->getSrting();
//	while (!checkdigit(slevel)) {
//		pGame->printMessage("please Enter a valid number");
//		slevel = pGame->getSrting();
//	}
//
//	int level = stoi(slevel);
//	if (level == 0) {
//		pGame->printMessage("please Enter a valid number");
//		slevel = pGame->getSrting();
//	}
//	else
//		pGame->setLevel(level);
//
//}

//bool grid::checkdigit(string s)
//{
//	for (int i = 0; i < s.size(); i++) {
//		if (isdigit(s[i]))
//			return true;
//		else
//			return false;
//
//	}
//}


