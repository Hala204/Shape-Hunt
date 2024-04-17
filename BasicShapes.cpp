#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y + hght / 2;     //update
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y - hght / 2;   //update

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}

void Rect::Rotate()
{

	int temp;
	temp = wdth;
	wdth = hght;
	hght = temp;

}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	pGame = r_pGame;
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}

void circle::Rotate() //circle can't be rotated 
{}



////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here
Triangle::Triangle(game* r_pGame, point ref, int sl) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	sidelength = sl;
}

void Triangle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	point LeftBottomPoint, UpperPoint, RightBottomPoint;
	LeftBottomPoint.x = RefPoint.x - sidelength / 2;
	LeftBottomPoint.y = RefPoint.y + sidelength / 2;
	UpperPoint.x = RefPoint.x;
	UpperPoint.y = RefPoint.y - sidelength / 2;
	RightBottomPoint.x = RefPoint.x + sidelength / 2;
	RightBottomPoint.y = RefPoint.y + sidelength / 2;
	pW->DrawTriangle(LeftBottomPoint.x, LeftBottomPoint.y, UpperPoint.x, UpperPoint.y, RightBottomPoint.x, RightBottomPoint.y, FILLED);
}


void Triangle::Rotate()
{}
