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

class IceCream :public shape
{
	Triangle* Cone;
	circle* Scoop;
public:
	IceCream(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void Rotate();
	virtual void resize(double factor);


};