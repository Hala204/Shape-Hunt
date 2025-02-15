#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;
};

enum ShapeType
{
	//Composite shapes
	SIGN,	//a street sign
	CAR,
	ICECREAM,
	ROCKET,
	FISH,
	HOME,
	WATCH,
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
public:
    shape(game* r_pGame, point ref);
    virtual void draw() const=0;//for a shape to draw itself on the screen
	virtual void Rotate() = 0;//for a shape to rotate itself on the screen
	void setRefPoint(point p);
	int getrotated() const;
	virtual void resizeUp(double factor) = 0;
	virtual void resizeDown(double factor) = 0;
	virtual void Save(ofstream& OutFile) = 0;
	point getRefPoint() const;
	virtual bool Match(shape* sh) = 0;
								  
							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	//virtual void rotate() = 0;	//Rotate the shape
	virtual void resize(double factor) = 0;	//Resize the shape
	//virtual void move() = 0;		//Move the shape
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




