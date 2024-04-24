#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}


void Sign::Rotate()
{
	base->Rotate();
	top->Rotate();
	//The Adjustments of the shape after rotation (NOT YET)
	//TO BE IMPLEMENTED 
}

void Sign::resize(double factor)
{
	base->resize(factor);
	top->resize(factor);
}


////////////////////////////////////////////////////  class Ice Cream  ///////////////////////////////////////
IceCream::IceCream(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	//calc the ref point of the Ice Cream cone and scoop relative to the Ice Cream shape
	point ScoopRef = ref;  //scoop ref is the same as the ice cream shape
	point ConeRef = { ref.x , ref.y + config.IceCreamShape._sidelength / 2 };
	Scoop = new circle(pGame, ScoopRef, config.IceCreamShape._radius);
	Cone = new Triangle(pGame, ConeRef, config.IceCreamShape._sidelength, config.IceCreamShape._rotation_angle);
}

void IceCream::draw() const
{
    Scoop->draw();
	Cone->draw();
}


void IceCream::Rotate()
{
	Scoop->Rotate();
	Cone->Rotate();
	//The Adjustments of the shape after rotation (NOT YET)
	//TO BE IMPLEMENTED 
}

void IceCream::resize(double factor)
{
}
