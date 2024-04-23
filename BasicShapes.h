//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	int hght, wdth;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	int rad;
public:	
	circle(game* r_pGame, point ref, int r);	
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//Reference point of the triangle is its center
class Triangle :public shape
{
	int sidelength;
	double rotation_angle;
public:
	Triangle(game* r_pGame, point ref, int sl, double ra) ;
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);

};
