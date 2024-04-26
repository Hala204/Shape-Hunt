#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#define PII 3.14159265358979323846 

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
  pGame = r_pGame;
  ihght = r_hght;
  iwdth = r_wdth;
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

void Rect::resize(double factor)
{
  wdth = iwdth*factor;
  hght = ihght*factor;
}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
  pGame = r_pGame;
  rad = r;
  irad = r;
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



void circle::resize(double factor)
{
  rad = irad * factor;
}
////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here
Triangle::Triangle(game* r_pGame, point ref, int sl,double ra) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	sidelength = sl;
	rotation_angle = ra;
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


	double s = (rotation_angle * PII) / 180;
	point l, m, n;
	l.x = RefPoint.x + (LeftBottomPoint.x - RefPoint.x ) * cos(s) - (LeftBottomPoint.y - RefPoint.y) * sin(s);
	l.y = RefPoint.y + (LeftBottomPoint.x - RefPoint.x) * sin(s) + (LeftBottomPoint.y - RefPoint.y) * cos(s);
	m.x = RefPoint.x + (UpperPoint.x - RefPoint.x) * cos(s) - (UpperPoint.y - RefPoint.y) * sin(s);
	m.y = RefPoint.y + (UpperPoint.x - RefPoint.x) * sin(s) + (UpperPoint.y - RefPoint.y) * cos(s);
	n.x = RefPoint.x + (RightBottomPoint.x - RefPoint.x) * cos(s) - (RightBottomPoint.y - RefPoint.y) * sin(s);
	n.y = RefPoint.y + (RightBottomPoint.x - RefPoint.x) * sin(s) + (RightBottomPoint.y - RefPoint.y) * cos(s);
	pW->DrawTriangle(l.x, l.y, m.x, m.y, n.x, n.y, FILLED);



	//pW->DrawTriangle(LeftBottomPoint.x, LeftBottomPoint.y, UpperPoint.x, UpperPoint.y, RightBottomPoint.x, RightBottomPoint.y, FILLED);
}


void Triangle::Rotate()
{
	rotation_angle += 90;

}

void Triangle::resize(double factor)
{
	sidelength *= factor;
}
