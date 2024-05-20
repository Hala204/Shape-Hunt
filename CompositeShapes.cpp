#include "CompositeShapes.h"
#include "gameConfig.h"
#define PII 3.14159265358979323846 

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref, color fillcolor):shape(r_pGame, ref),rotation_angle_sign(0)
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
	
	point NewtopRef = RefPoint;

	point NewbaseRef;

	rotation_angle_sign += 90;
	double s = rotation_angle_sign;
	if (s >= 90 && s < 180)
	{
		NewbaseRef = { RefPoint.x - config.sighShape.topWdth / 2 - config.sighShape.baseHeight / 2 + 25 , RefPoint.y};
	}

	else if (s >= 180 && s < 270)
	{
		NewbaseRef = { RefPoint.x  , RefPoint.y - config.sighShape.topWdth / 2 - config.sighShape.baseHeight / 2 + 25 };

	}
	else if (s >= 270 && s < 360)
	{
		NewbaseRef = { RefPoint.x + config.sighShape.topWdth / 2 + config.sighShape.baseHeight / 2 - 25 , RefPoint.y };

	}
	else
	{
		NewbaseRef = { RefPoint.x  , RefPoint.y + config.sighShape.topWdth / 2 + config.sighShape.baseHeight / 2 - 25 };

		rotation_angle_sign = 0;


	}
	base->setRefPoint(NewbaseRef);
	top->setRefPoint(NewtopRef);

}

void Sign::resizeUp(double factor)
{

	point oldRefPoint = top->getRefPoint();

	top->resizeUp(factor);
	base->resizeUp(factor);

	double newTopHeight = top->getHeight();
	double newBaseHeight = base->getHeight();

	point newRefBase;
	newRefBase.x = oldRefPoint.x;
	newRefBase.y = oldRefPoint.y + newTopHeight / 2 + newBaseHeight / 2;
	base->setRefPoint(newRefBase);


  point NewbaseRef;
  NewbaseRef.x = RefPoint.x;
  NewbaseRef.y = RefPoint.y + (+config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2) * *config.sighSize;

  base->setRefPoint(NewbaseRef);

  base->resize(*config.sighSize);
  top->resize(*config.sighSize);

}

void Sign::Save(ofstream& OutFile)
{
	OutFile << SIGN << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}

void Sign::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}


Car::Car(game* c_pGame, point ref, color fillcolor) : shape(c_pGame, ref),current_rotation_anggg(90)
{
	point BodyRef = ref;
	point windowRef = { ref.x - config.carShape.bodyWidth / 4, ref.y - config.carShape.bodyHeight / 2 - config.carShape.windowSide / 2 };
	point roofRef = { ref.x + config.carShape.bodyWidth / 8, ref.y - config.carShape.bodyHeight / 2 - config.carShape.roofHeight / 2 };
	point LeftWheelRef = { ref.x - config.carShape.bodyWidth / 4, ref.y + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius };
	point RightWheelRef = { ref.x + config.carShape.bodyWidth / 4, ref.y + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius };
	// Create the components of the car
	Body = new Rect(pGame, BodyRef, config.carShape.bodyHeight, config.carShape.bodyWidth);
	Roof = new Rect(pGame, roofRef, config.carShape.roofHeight, config.carShape.roofWidth);
	Window = new Triangle(pGame, windowRef, config.carShape.windowSide, config.carShape.rotation);
	LeftWheel = new circle(pGame, LeftWheelRef, config.carShape.wheelRadius);
	RightWheel = new circle(pGame, RightWheelRef, config.carShape.wheelRadius);
}

void Car::draw() const
{
	Body->draw();
	Roof->draw();
	Window->draw();
	LeftWheel->draw();
	RightWheel->draw();
}

void Car::Rotate()
{
	Body->Rotate();
	Roof->Rotate();
	Window->Rotate();
	LeftWheel->Rotate();
	RightWheel->Rotate();


	point BodyRef = RefPoint;
	point RoofRef;
	point WindowRef;
	point LeftWheelRef;
	point RightWheelRef;

	current_rotation_anggg += 90;
	double s = current_rotation_anggg;
	if (s >= 180 && s < 270)
	{
		RoofRef = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.roofHeight / 2 , RefPoint.y + config.carShape.bodyWidth / 8 };
		WindowRef = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.windowSide / 2 , RefPoint.y - config.carShape.bodyWidth / 4 };
		LeftWheelRef = { RefPoint.x - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius, RefPoint.y - config.carShape.bodyWidth / 4 };
		RightWheelRef = { RefPoint.x - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius, RefPoint.y + config.carShape.bodyWidth / 4 };
		
	}

	else if (s >= 270 && s < 360)
	{
		RoofRef = { RefPoint.x - config.carShape.bodyWidth / 8 , RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.roofHeight / 2 };
		WindowRef = { RefPoint.x + config.carShape.bodyWidth / 4 , RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.windowSide / 2 };
		LeftWheelRef = { RefPoint.x + config.carShape.bodyWidth / 4 , RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius };
		RightWheelRef = { RefPoint.x - config.carShape.bodyWidth / 4 , RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.wheelRadius };

	}
	else if (s >= 360)
	{
		RoofRef = { RefPoint.x - config.carShape.bodyHeight / 2 - config.carShape.roofHeight / 2 , RefPoint.y - config.carShape.bodyWidth / 8 };
		WindowRef = { RefPoint.x - config.carShape.bodyHeight / 2 - config.carShape.windowSide / 2 , RefPoint.y + config.carShape.bodyWidth / 4 };
		LeftWheelRef = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius, RefPoint.y + config.carShape.bodyWidth / 4 };
		RightWheelRef = { RefPoint.x + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius, RefPoint.y - config.carShape.bodyWidth / 4 };
		current_rotation_anggg = 0;

	}
	else
	{
		RoofRef = { RefPoint.x + config.carShape.bodyWidth / 8, RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.roofHeight / 2 };
		WindowRef = { RefPoint.x - config.carShape.bodyWidth / 4, RefPoint.y - config.carShape.bodyHeight / 2 - config.carShape.windowSide / 2 };
		LeftWheelRef = { RefPoint.x - config.carShape.bodyWidth / 4, RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius };
		RightWheelRef = { RefPoint.x + config.carShape.bodyWidth / 4, RefPoint.y + config.carShape.bodyHeight / 2 + config.carShape.wheelRadius };
		

	}
	Body->setRefPoint(BodyRef);
	Roof->setRefPoint(RoofRef);
	Window->setRefPoint(WindowRef);
	LeftWheel->setRefPoint(LeftWheelRef);
	RightWheel->setRefPoint(RightWheelRef);


}

void Car::resize(double factor)
{
	point newWindowRef;
	newWindowRef.x = RefPoint.x + (-config.carShape.bodyWidth / 4)  ** config.carsize;
	newWindowRef.y = RefPoint.y + (-config.carShape.bodyHeight / 2 - config.carShape.windowSide / 2) * *config.carsize;
	Window->setRefPoint(newWindowRef);
	Window->resize(*config.carsize);
	


	point newRoofRef;
	newRoofRef.x = RefPoint.x + (config.carShape.bodyWidth / 8)  **config.carsize;
	newRoofRef.y = RefPoint.y + (-config.carShape.bodyHeight / 2 - config.carShape.roofHeight / 2)  **config.carsize;
	Roof->setRefPoint(newRoofRef);
	Roof->resize(*config.carsize);


	point newLeftWheelRef;
	newLeftWheelRef.x = RefPoint.x + (-config.carShape.bodyWidth / 4)  **config.carsize;
	newLeftWheelRef.y = RefPoint.y + (config.carShape.bodyHeight / 2 + config.carShape.wheelRadius)  **config.carsize;
	LeftWheel->setRefPoint(newLeftWheelRef);
	LeftWheel->resize(*config.carsize);

	point newrightWheelRef;
	newrightWheelRef.x = RefPoint.x + (config.carShape.bodyWidth / 4)  **config.carsize;
	newrightWheelRef.y = RefPoint.y + (config.carShape.bodyHeight / 2 + config.carShape.wheelRadius) **config.carsize;

	RightWheel->setRefPoint(newrightWheelRef);
	RightWheel->resize(*config.carsize);
}

void Car::Save(ofstream& OutFile)
{
	OutFile << CAR << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}


void Car::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}


////////////////////////////////////////////////////  class Ice Cream  ///////////////////////////////////////
IceCream::IceCream(game* r_pGame, point ref, color fillcolor) :shape(r_pGame, ref), current_rotation_ang(180)
{
	//calc the ref point of the Ice Cream cone and scoop relative to the Ice Cream shape
	point ScoopRef = ref;  //scoop ref is the same as the ice cream shape ref
	point ConeRef = { ref.x , ref.y + config.IceCreamShape._sidelength / 2 };
	Scoop = new circle(pGame, ScoopRef, config.IceCreamShape._radius);
	Cone = new Triangle(pGame, ConeRef, config.IceCreamShape._sidelength, current_rotation_ang);
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
	
	point NewScoopRef = RefPoint;
	point NewConeRef;

	current_rotation_ang += 90; 
	double s = current_rotation_ang;
	if (s >= 270 && s < 360) 
		NewConeRef = { RefPoint.x - config.IceCreamShape._sidelength / 2 ,RefPoint.y };
	else if (s >= 360)
	{
		NewConeRef = { RefPoint.x ,RefPoint.y - config.IceCreamShape._sidelength / 2 };
		current_rotation_ang = 0;
	}
	else if (s >= 90 && s < 180) 
		NewConeRef = { RefPoint.x + config.IceCreamShape._sidelength / 2,RefPoint.y };
	else 
		NewConeRef = { RefPoint.x ,RefPoint.y + config.IceCreamShape._sidelength / 2 };

	Scoop->setRefPoint(NewScoopRef);
	Cone->setRefPoint(NewConeRef);
}

void IceCream::resize(double factor)
{
}

void IceCream::Save(ofstream& OutFile)
{
	OutFile << ICECREAM << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}


void IceCream::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}


////////////////////////////////////////////////////  class Rocket  ///////////////////////////////////////
Rocket::Rocket(game* r_pGame, point ref, color fillcolor) :shape(r_pGame, ref),current_rotation_ang_(0)
{
	point BodyRef = ref;   //body ref is the same as the rocket shape ref
	point TopRef = { ref.x, ref.y - config.RocketShape.bodyhght / 2 - config.RocketShape.___sidelength / 2 };
	point BottomRight{ ref.x + config.RocketShape.bodywdth / 2 + config.RocketShape.__sl / 2 , ref.y + config.RocketShape.bodyhght / 2 - 20 };
	point BottomLeft{ ref.x - config.RocketShape.bodywdth / 2 - config.RocketShape.__sl / 2 , ref.y + config.RocketShape.bodyhght / 2 - 20 };

	Body = new Rect(pGame, BodyRef, config.RocketShape.bodyhght, config.RocketShape.bodywdth);
	Top = new Triangle(pGame, TopRef, config.RocketShape.___sidelength, current_rotation_ang_);
	_BottomLeft = new Triangle(pGame, BottomLeft, config.RocketShape.__sl, config.RocketShape.r_ang1);
	_BottomRight = new Triangle(pGame, BottomRight, config.RocketShape.__sl, config.RocketShape.r_ang2);

}

void Rocket::draw() const
{
	Body->draw();
	Top->draw();
	_BottomLeft->draw();
	_BottomRight->draw();

}


void Rocket::Rotate()
{
	Body->Rotate();
	Top->Rotate();
	_BottomLeft->Rotate();
	_BottomRight->Rotate();

	point NewBodyRef = RefPoint;
	point NewTopRef;
	point NewBottomRightRef;
	point  NewBottomLeftRef;
	current_rotation_ang_ += 90;
	double s = current_rotation_ang_;
	if (s >= 90 && s < 180)
	{
		NewTopRef = { RefPoint.x + config.RocketShape.bodyhght / 2 + config.RocketShape.___sidelength / 2,RefPoint.y };
		NewBottomRightRef = { RefPoint.x - config.RocketShape.bodyhght / 2 + 20 ,  RefPoint.y + config.RocketShape.bodywdth / 2 + config.RocketShape.__sl / 2 };
		NewBottomLeftRef = { RefPoint.x - config.RocketShape.bodyhght / 2 + 20 ,  RefPoint.y - config.RocketShape.bodywdth / 2 - config.RocketShape.__sl / 2 };

	}
	else if (s >= 180 && s < 270)
	{
		NewTopRef = { RefPoint.x ,RefPoint.y + config.RocketShape.bodyhght / 2 + config.RocketShape.___sidelength / 2 };
		NewBottomRightRef = { RefPoint.x - config.RocketShape.bodywdth / 2 - config.RocketShape.__sl / 2 , RefPoint.y - config.RocketShape.bodyhght / 2 + 20 };
		NewBottomLeftRef = { RefPoint.x + config.RocketShape.bodywdth / 2 + config.RocketShape.__sl / 2 , RefPoint.y - config.RocketShape.bodyhght / 2 + 20 };

	}
	else if (s >= 270 && s < 360)
	{
		NewTopRef = { RefPoint.x - config.RocketShape.bodyhght / 2 - config.RocketShape.___sidelength / 2,RefPoint.y };
		NewBottomRightRef = { RefPoint.x + config.RocketShape.bodyhght / 2 - 20 ,  RefPoint.y - config.RocketShape.bodywdth / 2 - config.RocketShape.__sl / 2 };
		NewBottomLeftRef = { RefPoint.x + config.RocketShape.bodyhght / 2 - 20 ,  RefPoint.y + config.RocketShape.bodywdth / 2 + config.RocketShape.__sl / 2 };
	}
	else
	{
		NewTopRef = { RefPoint.x ,RefPoint.y - config.RocketShape.bodyhght / 2 - config.RocketShape.___sidelength / 2 };
		NewBottomRightRef = { RefPoint.x + config.RocketShape.bodywdth / 2 + config.RocketShape.__sl / 2 , RefPoint.y + config.RocketShape.bodyhght / 2 - 20 };
		NewBottomLeftRef = { RefPoint.x - config.RocketShape.bodywdth / 2 - config.RocketShape.__sl / 2 , RefPoint.y + config.RocketShape.bodyhght / 2 - 20 };
		current_rotation_ang_ = 0;
	}

	Body->setRefPoint(NewBodyRef);
	Top->setRefPoint(NewTopRef);
	_BottomRight->setRefPoint(NewBottomRightRef);
	_BottomLeft->setRefPoint(NewBottomLeftRef);
	
}

void Rocket::Save(ofstream& OutFile)
{
	OutFile << ROCKET << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}


void Rocket::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}


////////////////////////////////////////////////////  class Fish  ///////////////////////////////////////
Fish::Fish(game* r_pGame, point ref, color fillcolor) :shape(r_pGame, ref),current_rotation_ang__(90)
{
	point FishBodyRef = ref;  //FishBody ref is the same as the Fish shape ref
	point HeadRef = { ref.x + config.FishShape.Headsidelength , ref.y };
	point TailRef = { ref.x - config.FishShape.fradius - config.FishShape.Tailsidelength / 2 + 5 ,ref.y };
	point AboveFinsRef = { ref.x , ref.y + config.FishShape.fradius };
	point BelowFinsRef = { ref.x , ref.y - config.FishShape.fradius };

	FishBody = new circle(pGame, FishBodyRef, config.FishShape.fradius);
	Tail = new Triangle(pGame, TailRef, config.FishShape.Tailsidelength, 90);
	Head = new Triangle(pGame, HeadRef, config.FishShape.Headsidelength, 90);
	AboveFins = new Rect(pGame, AboveFinsRef, config.FishShape.Finshght, config.FishShape.Finswdth);
	BelowFins = new Rect(pGame, BelowFinsRef, config.FishShape.Finshght, config.FishShape.Finswdth);

}

void Fish::draw() const
{
	Head->draw();
	AboveFins->draw();
	BelowFins->draw();
	Tail->draw();
	FishBody->draw();
}


void Fish::Rotate()
{
	Head->Rotate();
	AboveFins->Rotate();
	BelowFins->Rotate();
	Tail->Rotate();
	FishBody->Rotate();

	point FishBodyRef = RefPoint;
	point AboveFinsRef;
	point BelowFinsRef;
	point HeadRef;
	point TailRef;

	//point HeadRef = { ref.x + config.FishShape.Headsidelength , ref.y };
	//point TailRef = { ref.x - config.FishShape.fradius - config.FishShape.Tailsidelength / 2 + 5 ,ref.y };


	current_rotation_ang__ += 90;
	double s = current_rotation_ang__;
	if (s >= 180 && s < 270)
	{
	    AboveFinsRef = { RefPoint.x + config.FishShape.fradius,RefPoint.y };
		BelowFinsRef = { RefPoint.x - config.FishShape.fradius,RefPoint.y };
		HeadRef = { RefPoint.x , RefPoint.y + config.FishShape.Headsidelength };
		TailRef = { RefPoint.x , RefPoint.y - config.FishShape.fradius - config.FishShape.Tailsidelength / 2 + 5 };
	}
	else if (s >= 270 && s < 360)
	{
		AboveFinsRef = { RefPoint.x ,RefPoint.y + config.FishShape.fradius };
		BelowFinsRef = { RefPoint.x ,RefPoint.y - config.FishShape.fradius };
		HeadRef = { RefPoint.x - config.FishShape.Headsidelength , RefPoint.y };
		TailRef = { RefPoint.x + config.FishShape.fradius + config.FishShape.Tailsidelength / 2 - 5, RefPoint.y };

	}
	else if (s >= 360)
	{
		AboveFinsRef = { RefPoint.x + config.FishShape.fradius,RefPoint.y };
		BelowFinsRef = { RefPoint.x - config.FishShape.fradius,RefPoint.y };
		HeadRef = { RefPoint.x , RefPoint.y - config.FishShape.Headsidelength };
		TailRef = { RefPoint.x , RefPoint.y + config.FishShape.fradius + config.FishShape.Tailsidelength / 2 - 5 };
		current_rotation_ang__ = 0;
		
	}
	else
	{
	    AboveFinsRef = { RefPoint.x ,RefPoint.y + config.FishShape.fradius };
		BelowFinsRef = { RefPoint.x ,RefPoint.y - config.FishShape.fradius };
		HeadRef = { RefPoint.x + config.FishShape.Headsidelength , RefPoint.y };
		TailRef = { RefPoint.x - config.FishShape.fradius - config.FishShape.Tailsidelength / 2 + 5, RefPoint.y };

	}

	Head->setRefPoint(HeadRef);
	AboveFins->setRefPoint(AboveFinsRef);
	BelowFins->setRefPoint(BelowFinsRef);
	Tail->setRefPoint(TailRef);
	FishBody->setRefPoint(FishBodyRef);

}

void Fish::resize(double factor)
{
}

void Fish::Save(ofstream& OutFile)
{
	OutFile << FISH << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}


void Fish::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}



Watch::Watch(game* r_pGame, point ref, color fillcolor):shape(r_pGame, ref),current_rotation_ang___(180)
{
	point watchRef = ref;
	point upperRectRef = { ref.x, ref.y - config.watchShape.radious - config.watchShape.Rectwidth + 5 };
	point lowerTriRef = { ref.x, ref.y + config.watchShape.radious + config.watchShape.sidelength - 35 };

	watchbody = new circle(pGame, watchRef, config.watchShape.radious);
	upperRect = new Rect(pGame, upperRectRef, config.watchShape.Rectwidth, config.watchShape.RectHeight);
	lowerTri = new Triangle(pGame, lowerTriRef, config.watchShape.sidelength, 180);
}




void Watch::resize(double factor)
{
}


void Watch::Save(ofstream& OutFile)
{
	OutFile << WATCH << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}


void Watch::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}



Home::Home(game* r_pGame, point ref, color fillcolor):shape(r_pGame, ref),current_rotation_angg(0)
{
	point bodyRef = { ref.x,ref.y };
	point TriRef = { ref.x , ref.y - config.homeshape.hight / 2 - config.homeshape.sidelength / 2 };
	point leftRectRef = { ref.x - config.homeshape.width / 2 + 11, ref.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight / 2 };
	point circRef = { ref.x - config.homeshape.width / 2 - config.homeshape.radius + 15, ref.y - config.homeshape.hight/2 - config.homeshape.smallrectheight - 17 };
	point circRef1 = { ref.x - config.homeshape.width / 2 - config.homeshape.radius - 5 ,  ref.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 35 };


	HomeBody = new Rect(pGame, bodyRef, config.homeshape.hight, config.homeshape.width );
	upperTri = new Triangle(pGame, TriRef, config.homeshape.sidelength, 0);
	leftRect = new Rect(pGame, leftRectRef, config.homeshape.smallrectheight, config.homeshape.smallrectwidth);
	circleup = new circle(pGame, circRef, config.homeshape.radius);
	circleup1 = new circle(pGame, circRef1, config.homeshape.radius);

}

void Home::draw() const
{
	HomeBody-> draw();
	upperTri-> draw();
	leftRect-> draw();
	circleup-> draw();
	circleup1->draw();
}

void Home::Rotate()
{
	HomeBody->Rotate();
	upperTri->Rotate();
	leftRect->Rotate();
	circleup->Rotate();
	circleup1->Rotate();

	point HomeBodyRef = RefPoint;
	point upperTriRef;
	point leftRectRef;
	point circleupRef;
	point circleup1Ref;

	/*point TriRef = { ref.x , ref.y - config.homeshape.hight / 2 - config.homeshape.sidelength / 2 };
	point leftRectRef = { ref.x - config.homeshape.width / 2 + 11, ref.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight / 2 };
	point circRef = { ref.x - config.homeshape.width / 2 - config.homeshape.radius + 15, ref.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 17 };
	point circRef1 = { ref.x - config.homeshape.width / 2 - config.homeshape.radius - 5 ,  ref.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 35 };*/


	current_rotation_angg += 90;
	double s = current_rotation_angg;
	if (s >= 90 && s < 180)
	{
		upperTriRef = { RefPoint.x + config.homeshape.hight / 2 + config.homeshape.sidelength / 2 , RefPoint.y };
		leftRectRef = { RefPoint.x + config.homeshape.hight / 2 + config.homeshape.smallrectheight / 2  , RefPoint.y - config.homeshape.width / 2 + 11 };
		circleupRef = { RefPoint.x + config.homeshape.hight / 2 + config.homeshape.smallrectheight + 17 , RefPoint.y - config.homeshape.width / 2 - config.homeshape.radius + 15 };
		circleup1Ref = { RefPoint.x + config.homeshape.hight / 2 + config.homeshape.smallrectheight + 35 , RefPoint.y - config.homeshape.width / 2 - config.homeshape.radius - 5 };


	}
	else if (s >= 180 && s < 270)
	{
		upperTriRef = { RefPoint.x , RefPoint.y + config.homeshape.hight / 2 + config.homeshape.sidelength / 2 };
		leftRectRef = { RefPoint.x + config.homeshape.width / 2 - 11,RefPoint.y + config.homeshape.hight / 2 + config.homeshape.smallrectheight / 2 };
		circleupRef = { RefPoint.x + config.homeshape.width / 2 + config.homeshape.radius - 15 , RefPoint.y + config.homeshape.hight / 2 + config.homeshape.smallrectheight + 17 };
		circleup1Ref = { RefPoint.x + config.homeshape.width / 2 + config.homeshape.radius + 5 , RefPoint.y + config.homeshape.hight / 2 + config.homeshape.smallrectheight + 35 };


	}
	else if (s >= 270 && s < 360)
	{
		upperTriRef = { RefPoint.x - config.homeshape.hight / 2 - config.homeshape.sidelength / 2 , RefPoint.y };
		leftRectRef = { RefPoint.x - config.homeshape.hight / 2 - config.homeshape.smallrectheight / 2  , RefPoint.y + config.homeshape.width / 2 - 11 };
		circleupRef = { RefPoint.x - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 17 , RefPoint.y + config.homeshape.width / 2 + config.homeshape.radius - 15 };
		circleup1Ref = { RefPoint.x - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 35 , RefPoint.y + config.homeshape.width / 2 + config.homeshape.radius + 5 };

	}
	else
	{
		upperTriRef = { RefPoint.x , RefPoint.y - config.homeshape.hight / 2 - config.homeshape.sidelength / 2 };
        leftRectRef = { RefPoint.x - config.homeshape.width / 2 + 11, RefPoint.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight / 2 };
		circleupRef = { RefPoint.x - config.homeshape.width / 2 - config.homeshape.radius + 15, RefPoint.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 17 };
        circleup1Ref = { RefPoint.x - config.homeshape.width / 2 - config.homeshape.radius - 5 ,  RefPoint.y - config.homeshape.hight / 2 - config.homeshape.smallrectheight - 35 };
		current_rotation_angg = 0;
	}

	HomeBody->setRefPoint(HomeBodyRef);
	upperTri->setRefPoint(upperTriRef);
	leftRect->setRefPoint(leftRectRef);
	circleup->setRefPoint(circleupRef);
	circleup1->setRefPoint(circleup1Ref);
}


void Home::Save(ofstream& OutFile)
{
	OutFile << HOME << "\n" << RefPoint.x << "\n" << RefPoint.y << "\n" << fillColor.ucRed << "\n" << fillColor.ucGreen << "\n" << fillColor.ucBlue << "\n";
}


void Home::Load(ifstream& Infile)
{
	int resized, rotated;
	Infile >> resized >> rotated;
	if (resized > 0)
	{
		for (int i = 0; i < resized; i++)
			this->resizeUp(1.5);
	}
	else if (resized < 0)
	{
		for (int i = 0; i > resized; i--)
			this->resizeDown(0.5);
	}
	if (rotated > 0)
	{
		for (int i = 0; i < rotated; i++)
			this->Rotate();
	}
}


void Home::resize(double factor)
{
}
void Sign::resizeDown(double factor)
{
	point oldRefPoint = top->getRefPoint();

	top->resizeDown(factor);
	base->resizeDown(factor);

	double newTopHeight = top->getHeight();
	double newBaseHeight = base->getHeight();

	point newRefBase;
	newRefBase.x = oldRefPoint.x;
	newRefBase.y = oldRefPoint.y + newTopHeight / 2 + newBaseHeight / 2;
	base->setRefPoint(newRefBase);

}
void Sign::resize(double factor) {}







  //void Sign::resizeUp(double factor){}
  //void Sign::resizeDown(double factor) {}





void Car::resizeUp(double factor) 
{
	point oldRefPoint = Body->getRefPoint();
	
		Body->resizeUp(factor);
		Roof->resizeUp(factor);
		Window->resizeUp(factor);
		LeftWheel->resizeUp(factor);
		RightWheel->resizeUp(factor);
		
		
		double newBodyWidth = Body->getWidth();
		double newBodyHeight = Body->getHeight();
		double newRoofHeight = Roof->getHeight();
		double newRooWidth = Roof->getHeight();
		double newWindow = Window->getbase();
		double newLeftWheel = LeftWheel->getRadius();
		double newRightWheel = RightWheel->getRadius();

		

		point newWindowRef = { oldRefPoint.x - newBodyWidth / 4, oldRefPoint.y - newBodyHeight / 2 - newWindow / 2 };
		point newRoofRef = { oldRefPoint.x + newBodyWidth / 8, oldRefPoint.y - newBodyHeight / 2 - newRoofHeight / 2 };
		point newLeftWheelRef = { oldRefPoint.x - newBodyWidth / 4, oldRefPoint.y + newBodyHeight / 2 + newLeftWheel };
		point newRightWheelRef = { oldRefPoint.x + newBodyWidth / 4, oldRefPoint.y + newBodyHeight / 2 + newRightWheel };

	 
		Window->setRefPoint(newWindowRef);
		Roof->setRefPoint(newRoofRef);
		LeftWheel->setRefPoint(newLeftWheelRef);
		RightWheel->setRefPoint(newRightWheelRef);
	}

void Car::resizeDown(double factor) {
	point oldRefPoint = Body->getRefPoint();

	Body->resizeDown(factor);
	Roof->resizeDown(factor);
	Window->resizeDown(factor);
	LeftWheel->resizeDown(factor);
	RightWheel->resizeDown(factor);

	
	double newBodyWidth = Body->getWidth();
	double newBodyHeight = Body->getHeight();
	double newRoofHeight = Roof->getHeight();
	double newRooWidth = Roof->getHeight();
	double newWindow = Window->getbase();
	double newLeftWheel = LeftWheel->getRadius();
	double newRightWheel = RightWheel->getRadius();





	point newWindowRef = { oldRefPoint.x - newBodyWidth / 4, oldRefPoint.y - newBodyHeight / 2 - newWindow / 2 };
	point newRoofRef = { oldRefPoint.x + newBodyWidth / 8, oldRefPoint.y - newBodyHeight / 2 - newRoofHeight / 2 };
	point newLeftWheelRef = { oldRefPoint.x - newBodyWidth / 4, oldRefPoint.y + newBodyHeight / 2 + newLeftWheel };
	point newRightWheelRef = { oldRefPoint.x + newBodyWidth / 4, oldRefPoint.y + newBodyHeight / 2 + newRightWheel };


	Window->setRefPoint(newWindowRef);
	Roof->setRefPoint(newRoofRef);
	LeftWheel->setRefPoint(newLeftWheelRef);
	RightWheel->setRefPoint(newRightWheelRef);
}



	


////////////////////////////////////////////////////  class Ice Cream  ///////////////////////////////////////


void IceCream::resizeUp(double factor) {

	point oldScoopRefPoint = Scoop->getRefPoint();

	
	Scoop->resizeUp(factor);
	Cone->resizeUp(factor);

	
	double newScoopRadius = Scoop->getRadius();
	double newConeSideLength = Cone->getbase();


	point newScoopRefPoint = oldScoopRefPoint;
	newScoopRefPoint.y = oldScoopRefPoint.y - newConeSideLength / 2;


	Scoop->setRefPoint(newScoopRefPoint);
}

void IceCream::resizeDown(double factor) {
	
	point oldScoopRefPoint = Scoop->getRefPoint();


	Scoop->resizeDown(factor);
	Cone->resizeDown(factor);


	double newScoopRadius = Scoop->getRadius();
	double newConeSideLength = Cone->getbase();

	
	point newScoopRefPoint = oldScoopRefPoint;
	newScoopRefPoint.y = oldScoopRefPoint.y - newConeSideLength / 2;

	
	Scoop->setRefPoint(newScoopRefPoint);
}






//void IceCream::resizeUp(double factor) {}
//void IceCream::resizeDown(double factor) {}



////////////////////////////////////////////////////  class Rocket  ///////////////////////////////////////







void Rocket::resizeUp(double factor) {
	point oldRefPoint = Body->getRefPoint();

	
	Body->resizeUp(factor);
	Top->resizeUp(factor);
	_BottomLeft->resizeUp(factor);
	_BottomRight->resizeUp(factor);

	
	double newBodyHeight = Body->getHeight();
	double newBodyWidth = Body->getWidth();
	double newTop = Top->getbase();
	double newBottomLeft = _BottomLeft->getbase();
	double newBottomRight = _BottomRight->getbase();



	
	point newTopRefPoint = { oldRefPoint.x, oldRefPoint.y - newBodyHeight / 2 - newTop / 2 };
	point newBottomRightRefPoint = { oldRefPoint.x + newBodyWidth / 2 + newBottomRight / 2 , oldRefPoint.y + newBodyHeight / 2 - 20  };
	point newBottomLeftRefPoint = { oldRefPoint.x - newBodyWidth / 2 - newBottomLeft / 2 , oldRefPoint.y + newBodyHeight / 2 - 20 };

	
	Top->setRefPoint(newTopRefPoint);
	_BottomLeft->setRefPoint(newBottomLeftRefPoint);
	_BottomRight->setRefPoint(newBottomRightRefPoint);
}

void Rocket::resizeDown(double factor) {
	point oldRefPoint = Body->getRefPoint(); 


	Body->resizeDown(factor);
	Top->resizeDown(factor);
	_BottomLeft->resizeDown(factor);
	_BottomRight->resizeDown(factor);

	
	double newBodyHeight = Body->getHeight();
	double newBodyWidth = Body->getWidth();
	double newTop = Top->getbase();
	double newBottomLeft = _BottomLeft->getbase();
	double newBottomRight = _BottomRight->getbase();



	point newTopRefPoint = { oldRefPoint.x, oldRefPoint.y - newBodyHeight / 2 - newTop / 2 };
	point newBottomRightRefPoint = { oldRefPoint.x + newBodyWidth / 2 + newBottomRight / 2 , oldRefPoint.y + newBodyHeight / 2 - 20 };
	point newBottomLeftRefPoint = { oldRefPoint.x - newBodyWidth / 2 - newBottomLeft / 2 , oldRefPoint.y + newBodyHeight / 2 - 20 };



	
	Top->setRefPoint(newTopRefPoint);
	_BottomLeft->setRefPoint(newBottomLeftRefPoint);
	_BottomRight->setRefPoint(newBottomRightRefPoint);
}




























//void Rocket::resizeUp(double factor) {}
//void Rocket::resizeDown(double factor) {}







void Rocket::resize(double factor)
{
}


////////////////////////////////////////////////////  class Fish  ///////////////////////////////////////


void Fish::resizeUp(double factor) {
	point oldRefPoint = FishBody->getRefPoint();

	
	FishBody->resizeUp(factor);
	Tail->resizeUp(factor);
	Head->resizeUp(factor);
	AboveFins->resizeUp(factor);
	BelowFins->resizeUp(factor);


	double newFishBodyRadius = FishBody->getRadius();
	double newHeadSideLength = Head->getbase();

	double newTailSideLength = Tail->getbase();
	double newFinsWidthAbove = AboveFins->getWidth();
	double newFinsHeightAbove = AboveFins->getWidth();
	double newFinsWidthBelow = BelowFins->getWidth();
	double newFinsHeightBelow = BelowFins->getWidth();

	
	point newTailRefPoint = { oldRefPoint.x - newFishBodyRadius - newTailSideLength / 2 + 5 , oldRefPoint.y };
	point newHeadRefPoint = { oldRefPoint.x + newFishBodyRadius + newHeadSideLength , oldRefPoint.y };
	point newAboveFinsRefPoint = { oldRefPoint.x, oldRefPoint.y + newFishBodyRadius  };
	point newBelowFinsRefPoint = { oldRefPoint.x, oldRefPoint.y - newFishBodyRadius  };


	Tail->setRefPoint(newTailRefPoint);
	Head->setRefPoint(newHeadRefPoint);
	AboveFins->setRefPoint(newAboveFinsRefPoint);
	BelowFins->setRefPoint(newBelowFinsRefPoint);
}

void Fish::resizeDown(double factor) {
	point oldRefPoint = FishBody->getRefPoint();

	
	FishBody->resizeDown(factor);
	Tail->resizeDown(factor);
	Head->resizeDown(factor);
	AboveFins->resizeDown(factor);
	BelowFins->resizeDown(factor);

	
	double newFishBodyRadius = FishBody->getRadius();
	double newHeadSideLength = Head->getbase();
	double newTailSideLength = Tail->getbase();
	double newFinsWidth = AboveFins->getWidth();

	
	point newTailRefPoint = { oldRefPoint.x - newFishBodyRadius - newTailSideLength / 2 + 5 , oldRefPoint.y };
	point newHeadRefPoint = { oldRefPoint.x + newFishBodyRadius + newHeadSideLength , oldRefPoint.y };
	point newAboveFinsRefPoint = { oldRefPoint.x, oldRefPoint.y + newFishBodyRadius };
	point newBelowFinsRefPoint = { oldRefPoint.x, oldRefPoint.y - newFishBodyRadius };

	
	Tail->setRefPoint(newTailRefPoint);
	Head->setRefPoint(newHeadRefPoint);
	AboveFins->setRefPoint(newAboveFinsRefPoint);
	BelowFins->setRefPoint(newBelowFinsRefPoint);
}










//void Fish::resizeUp(double factor) {}
//void Fish::resizeDown(double factor) {}





void Watch::draw() const
{
	watchbody->draw();
	upperRect->draw();
	lowerTri->draw();
}




void Watch::resizeUp(double factor) {
	point oldRefPoint = watchbody->getRefPoint();

	
	watchbody->resizeUp(factor);
	upperRect->resizeUp(factor);
	lowerTri->resizeUp(factor);

	
	double newWatchRadius = watchbody->getRadius();
	double newUpperRectHeight = upperRect->getHeight();
	double newUpperRectWidth = upperRect->getWidth();
	double newLowerTriSideLength = lowerTri->getbase();

	
	point newWatchRefPoint = oldRefPoint;
	point newUpperRectRefPoint = { oldRefPoint.x, oldRefPoint.y - newWatchRadius - newUpperRectWidth + 5 };
	point newLowerTriRefPoint = { oldRefPoint.x, oldRefPoint.y + newWatchRadius + newLowerTriSideLength - 35 };

	
	watchbody->setRefPoint(newWatchRefPoint);
	upperRect->setRefPoint(newUpperRectRefPoint);
	lowerTri->setRefPoint(newLowerTriRefPoint);
}

void Watch::resizeDown(double factor) {
	point oldRefPoint = watchbody->getRefPoint();

	watchbody->resizeDown(factor);
	upperRect->resizeDown(factor);
	lowerTri->resizeDown(factor);


	double newWatchRadius = watchbody->getRadius();
	double newUpperRectHeight = upperRect->getHeight();
	double newUpperRectWidth = upperRect->getWidth();
	double newLowerTriSideLength = lowerTri->getbase();


	point newWatchRefPoint = oldRefPoint;
	point newUpperRectRefPoint = { oldRefPoint.x, oldRefPoint.y - newWatchRadius - newUpperRectWidth + 5 };
	point newLowerTriRefPoint = { oldRefPoint.x, oldRefPoint.y + newWatchRadius + newLowerTriSideLength - 35 };

	
	watchbody->setRefPoint(newWatchRefPoint);
	upperRect->setRefPoint(newUpperRectRefPoint);
	lowerTri->setRefPoint(newLowerTriRefPoint);
}


void Watch::Rotate()
{
	watchbody->Rotate();
	upperRect->Rotate();
	lowerTri->Rotate();
	
	point watchRef = RefPoint;
	point upperRectRef;
	point lowerTriRef;


	current_rotation_ang___ += 90;
	double s = current_rotation_ang___;

	if (s >= 270 && s < 360)
	{
		upperRectRef = { RefPoint.x + config.watchShape.radious + config.watchShape.Rectwidth - 5 ,RefPoint.y };
		lowerTriRef = { RefPoint.x - config.watchShape.radious - config.watchShape.sidelength + 35 ,RefPoint.y };
	}
	else if (s >= 360)
	{
		upperRectRef = { RefPoint.x ,RefPoint.y + config.watchShape.radious + config.watchShape.Rectwidth - 5 };
		lowerTriRef = { RefPoint.x ,RefPoint.y - config.watchShape.radious - config.watchShape.sidelength + 35 };
		current_rotation_ang___ = 0;

	}
	else if (s >= 90 && s < 180)
	{
		upperRectRef = { RefPoint.x - config.watchShape.radious - config.watchShape.Rectwidth + 5 ,RefPoint.y };
		lowerTriRef = { RefPoint.x + config.watchShape.radious + config.watchShape.sidelength - 35 ,RefPoint.y };
	}
	else
	{
		upperRectRef = { RefPoint.x ,RefPoint.y - config.watchShape.radious - config.watchShape.Rectwidth + 5 };
		lowerTriRef = { RefPoint.x ,RefPoint.y + config.watchShape.radious + config.watchShape.sidelength - 35 };
	}

	watchbody->setRefPoint(watchRef);
	upperRect->setRefPoint(upperRectRef);
	lowerTri->setRefPoint(lowerTriRef);


}






void Home::resizeUp(double factor) {
	point oldRefPoint = HomeBody->getRefPoint();

	
	HomeBody->resizeUp(factor);
	upperTri->resizeUp(factor);
	leftRect->resizeUp(factor);
	circleup->resizeUp(factor);
	circleup1->resizeUp(factor);


	double newHomeBodyHeight = HomeBody->getHeight();
	double newHomeBodyWidth = HomeBody->getWidth();
	double newLeftRectHeight = leftRect->getHeight();
	double newLeftRectwidth = leftRect->getWidth();
	double newupperTri = upperTri->getbase();
	double newcircleup = circleup->getRadius();
	double newcircleup1 = circleup->getRadius();




	
	point newTriRefPoint = { oldRefPoint.x, oldRefPoint.y - newHomeBodyHeight / 2 - newupperTri / 2 };
	point newLeftRectRefPoint = { oldRefPoint.x - newHomeBodyWidth / 2 + 11 , oldRefPoint.y - newHomeBodyHeight / 2 - newLeftRectHeight / 2 };
	point newCircRefPoint = { oldRefPoint.x - newHomeBodyWidth / 2 - config.homeshape.radius + 15 , oldRefPoint.y - newHomeBodyHeight / 2 - newupperTri - 17};
	point newCircRef1Point = { oldRefPoint.x - newHomeBodyWidth / 2 - config.homeshape.radius - 5 , oldRefPoint.y - newHomeBodyHeight / 2 - newupperTri - 35  };

	
	upperTri->setRefPoint(newTriRefPoint);
	leftRect->setRefPoint(newLeftRectRefPoint);
	circleup->setRefPoint(newCircRefPoint);
	circleup1->setRefPoint(newCircRef1Point);
}

void Home::resizeDown(double factor) {
	point oldRefPoint = HomeBody->getRefPoint();

	
	HomeBody->resizeDown(factor);
	upperTri->resizeDown(factor);
	leftRect->resizeDown(factor);
	circleup->resizeDown(factor);
	circleup1->resizeDown(factor);

	double newHomeBodyHeight = HomeBody->getHeight();
	double newHomeBodyWidth = HomeBody->getWidth();
	double newLeftRectHeight = leftRect->getHeight();
	double newLeftRectwidth = leftRect->getWidth();
	double newupperTri = upperTri->getbase();
	double newcircleup = circleup->getRadius();
	double newcircleup1 = circleup->getRadius();




	point newTriRefPoint = { oldRefPoint.x, oldRefPoint.y - newHomeBodyHeight / 2 - newupperTri / 2 };
	point newLeftRectRefPoint = { oldRefPoint.x - newHomeBodyWidth / 2 + 11 , oldRefPoint.y - newHomeBodyHeight / 2 - newLeftRectHeight / 2 };
	point newCircRefPoint = { oldRefPoint.x - newHomeBodyWidth / 2 - config.homeshape.radius + 15 , oldRefPoint.y - newHomeBodyHeight / 2 - newupperTri - 17 };
	point newCircRef1Point = { oldRefPoint.x - newHomeBodyWidth / 2 - config.homeshape.radius - 5 , oldRefPoint.y - newHomeBodyHeight / 2 - newupperTri - 35 };


	upperTri->setRefPoint(newTriRefPoint);
	leftRect->setRefPoint(newLeftRectRefPoint);
	circleup->setRefPoint(newCircRefPoint);
	circleup1->setRefPoint(newCircRef1Point);




}