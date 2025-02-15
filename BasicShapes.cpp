#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#define PII 3.14159265358979323846 

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth) :shape(r_pGame, ref)
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


void Rect::setHeight(double height) {
	hght = height;
}
void Rect::setWidth(double width) {
	wdth = width;
}
double Rect::getHeight() const {
	return hght;
}
double Rect::getWidth() const {
	return wdth;
}
void Rect::resizeUp(double factor) {
	setHeight(hght * factor);
	setWidth(wdth * factor);

	/*if (hght < config.windHeight&& wdth< config.windWidth)
	 {
		resizeUp(factor);
	 }
	*/

}
void Rect::resizeDown(double factor) {
	setHeight(hght * factor);
	setWidth(wdth * factor);

	/*if (hght > 0 && wdth > 0)
	{
		resizeDown(factor);
	}*/
}

void Rect::resize(double factor) {}



void Rect::Rotate()
{

	int temp;
	temp = wdth;
	wdth = hght;
	hght = temp;

}

void Rect::Save(ofstream& OutFile)
{
	OutFile << RCT << "\n" << hght << "\n" << wdth;
}

bool Rect::Match(shape* sh)
{
	Rect* rec = dynamic_cast<Rect*> (sh);
	if (rec) {
		return RefPoint.x == rec->getRefPoint().x && RefPoint.y == rec->getRefPoint().y && hght == rec->hght && wdth == rec->wdth;
	}
	return false;
}



////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r) :shape(r_pGame, ref)
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

void circle::setRadius(double radius) {
	rad = radius;
}
double circle::getRadius() const {
	return rad;
}
void circle::resizeUp(double factor) {
	setRadius(rad * factor);

	//if (2*rad < config.windHeight && 2*rad < config.windWidth)
	//{
	//	resizeUp(factor);
	//}
}
void circle::resizeDown(double factor) {
	setRadius(rad * factor);
	/*if ( rad >0)
	{
		resizeDown(factor);
	}*/
}

void circle::resize(double factor) {}


void circle::Rotate() //circle can't be rotated 
{}

void circle::Save(ofstream& OutFile)
{
	OutFile << CRC << "\n" << rad << "\n";
}

bool circle::Match(shape* sh)
{
	circle* cir = dynamic_cast<circle*> (sh);
	if (cir) {
		return RefPoint.x == cir->getRefPoint().x && RefPoint.y == cir->getRefPoint().y && rad == cir->rad;
	}
	return false;
}
////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here
Triangle::Triangle(game* r_pGame, point ref, int sl, double ra) :shape(r_pGame, ref)
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
	l.x = RefPoint.x + (LeftBottomPoint.x - RefPoint.x) * cos(s) - (LeftBottomPoint.y - RefPoint.y) * sin(s);
	l.y = RefPoint.y + (LeftBottomPoint.x - RefPoint.x) * sin(s) + (LeftBottomPoint.y - RefPoint.y) * cos(s);
	m.x = RefPoint.x + (UpperPoint.x - RefPoint.x) * cos(s) - (UpperPoint.y - RefPoint.y) * sin(s);
	m.y = RefPoint.y + (UpperPoint.x - RefPoint.x) * sin(s) + (UpperPoint.y - RefPoint.y) * cos(s);
	n.x = RefPoint.x + (RightBottomPoint.x - RefPoint.x) * cos(s) - (RightBottomPoint.y - RefPoint.y) * sin(s);
	n.y = RefPoint.y + (RightBottomPoint.x - RefPoint.x) * sin(s) + (RightBottomPoint.y - RefPoint.y) * cos(s);
	pW->DrawTriangle(l.x, l.y, m.x, m.y, n.x, n.y, FILLED);



	//pW->DrawTriangle(LeftBottomPoint.x, LeftBottomPoint.y, UpperPoint.x, UpperPoint.y, RightBottomPoint.x, RightBottomPoint.y, FILLED);
}
void Triangle::setbase(double BASE)
{
	sidelength = BASE;
}

double Triangle::getbase() const
{
	return sidelength;
}

void Triangle::resizeDown(double factor)
{
	setbase(sidelength * factor);
	/*if (sidelength > 0)
	resizeDown(factor);*/
}

void Triangle::resizeUp(double factor)
{
	setbase(sidelength * factor);
	/*if (sidelength < config.windHeight && sidelength < config.windWidth)
	{
		resizeUp(factor);
	}*/


}

void Triangle::Rotate()
{
	rotation_angle += 90;

}

void Triangle::resize(double factor)
{
	sidelength *= factor;
}

void Triangle::Save(ofstream& OutFile)
{
	OutFile << TRI << "\n" << sidelength << "\n" << rotation_angle;
}

bool Triangle::Match(shape* sh)
{
	Triangle* tri = dynamic_cast<Triangle*> (sh);
	if (tri) {
		return RefPoint.x == tri->getRefPoint().x && RefPoint.y == tri->getRefPoint().y && sidelength == tri->sidelength;
	}
	return false;
}