#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};


///////////////////////////// Class ice cream //////////////////////////////////
//This shape is composed of one circle and one triangle
//The reference point of this shape is the center of the scoop (circle)


class IceCream :public shape
{
	Triangle* Cone;
	circle* Scoop;
	double current_rotation_ang;
public:
	IceCream(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};


///////////////////////////// Class Rocket //////////////////////////////////
//This shape is composed of three triangles and one rectangle
//The reference point of this shape is the reference point of the body (rectangle)


class Rocket :public shape
{
	Triangle* Top;
	Triangle* _BottomLeft;
	Triangle* _BottomRight;
	Rect* Body;

public:
	Rocket(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};



///////////////////////////// Class Fish //////////////////////////////////
//This shape is composed of two triangles, two rectangles and one circle
//The reference point of this shape is the center of the body of the fish (circle)


class Fish :public shape
{
	Triangle* Tail;
	Triangle* Head;
	Rect* AboveFins;
	Rect* BelowFins;
	circle* FishBody;

public:
	Fish(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};
