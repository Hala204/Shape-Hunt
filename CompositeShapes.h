#pragma once
#include "Basicshapes.h"
#include <fstream>

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
	double rotation_angle_sign;
public:
	Sign(game* r_pGame, point ref, color fillcolor);
	Sign(game* r_pGame, point ref, color fillcolor, double randomRotationAngle, double randomSize);
	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate(double rot);
	virtual void resize(double randomSize);
	virtual void resizeUp(double factor);
	virtual void resizeDown(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);

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
	IceCream(game* r_pGame, point ref, color fillcolor);
	IceCream(game* r_pGame, point ref, color fillcolor, double randomRotationAngle, double randomSize);
	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate(double rot);

	virtual void resize(double factor);

	virtual void resizeUp(double factor);
	virtual void resizeDown(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);

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
	double current_rotation_ang_;

public:
	Rocket(game* r_pGame, point ref, color fillcolor);
	Rocket(game* r_pGame, point ref, color fillcolor, double randomRotationAngle, double randomSize);
	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate(double randomRotationAngle);
	virtual void resize(double factor);
	virtual void resizeUp(double factor);
	virtual void resizeDown(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);

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
	double current_rotation_ang__;

public:
	Fish(game* r_pGame, point ref, color fillcolor);
	Fish(game* r_pGame, point ref, color fillcolor,double randomRotationAngle,double randomSize);
	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate(double rot);

	virtual void resize(double factor);
	virtual void resizeUp(double factor);
	virtual void resizeDown(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);

};


class Car : public shape
{
	Triangle* Window;
	circle* LeftWheel;
	circle* RightWheel;
	Rect* Body;
	Rect* Roof;
	Rect* top;
	circle* C1;
	circle* C2;
	double current_rotation_anggg;

public:
	Car(game* r_pGame, point ref, color fillcolor);
	Car(game* r_pGame, point ref, color fillcolor, double randomRotationAngle,double  randomSize);
	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate(double rot);

	virtual void resizeDown(double factor);
	virtual void resizeUp(double factor);
	virtual void resize(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);



};



class Watch :public shape
{
	circle* watchbody;
	Rect* upperRect;
	Triangle* lowerTri;
	double current_rotation_ang___;

public:
	Watch(game* r_pGame, point ref, color fillcolor);
	Watch(game* r_pGame, point ref, color fillcolor, double randomRotationAngle, double randomSize);

	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate(double rot);

	virtual void resize(double factor);
	virtual void resizeUp(double factor);
	virtual void resizeDown(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);

};

class Home :public shape
{
	Rect* HomeBody;
	Triangle* upperTri;
	Rect* leftRect;
	circle* circleup;
	circle* circleup1;
	double current_rotation_angg;


public:
	Home(game* r_pGame, point ref, color fillcolor);
	Home(game* r_pGame, point ref, color fillcolor,double randomRotationAngle, double randomSize);
	virtual void draw() const;
	virtual void Rotate();
	virtual void Rotate( double randomRotationAngle);

	virtual void resize(double factor);
	virtual void resizeUp(double factor);
	virtual void resizeDown(double factor);
	virtual void Save(ofstream& OutFile) override;
	virtual bool Match(shape* sh);
};