#include "grid.h"
#include "game.h"
#include "gameConfig.h"


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
		OutFile << shapeCount;
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

		switch (shapetype)
		{
		case SIGN:
			sh = new Sign(pGame, pnt, clr);
			break;
		case CAR:
			sh = new Car(pGame, pnt, clr);
			break;
		case HOME:
			sh = new Home(pGame, pnt, clr);
			break;
		case ICECREAM:
			sh = new IceCream(pGame, pnt, clr);
			break;
		case ROCKET:
			sh = new Rocket(pGame, pnt, clr);
			break;
		case FISH:
			sh = new Fish(pGame, pnt, clr);
			break;
		case WATCH:
			sh = new Watch(pGame, pnt, clr);
		}
		sh->Load(InFile);
		addShape(sh);
	}
}