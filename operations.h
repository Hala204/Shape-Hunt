#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operStartGame :public operation
{
public:
	operStartGame(game* r_pGame);
	virtual void Act();
};


class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};

class operAddIceCream :public operation
{
public:
	operAddIceCream(game* r_pGame);
	virtual void Act();
};

class operAddRocket :public operation
{
public:
	operAddRocket(game* r_pGame);
	virtual void Act();
};

class operAddFish :public operation
{
public:
	operAddFish(game* r_pGame);
	virtual void Act();
};

class operAddWatch :public operation
{
public:
	operAddWatch(game* r_pGame);
	virtual void Act();
};

class operAddHome :public operation
{
public:
	operAddHome(game* r_pGame);
	virtual void Act();
};

class operAddCar :public operation
{
public:
	operAddCar(game* r_pGame);
	virtual void Act();
};

class operAddRect :public operation
{
public:
	operAddRect(game* r_pGame);
	virtual void Act();
};

class operAddCirc :public operation
{
public:
	operAddCirc(game* r_pGame);
	virtual void Act();
};


class operAddTri :public operation
{
public:
	operAddTri(game* r_pGame);
	virtual void Act();
};


class operRotate :public operation
{
public:
	operRotate(game* r_pGame);
	virtual void Act();
};


class operMinimize : public operation {
public:
	operMinimize(game* r_pGame);
	virtual void Act();
};
class operDEL : public operation {
public:
	operDEL(game* r_pGame);
	virtual void Act();
};
class operINC : public operation {
public:
	operINC(game* e_pGame);
	virtual void Act();

};

class operSave :public operation
{
public:
	operSave(game* r_pGame);
	virtual void Act();
};


class operLoad :public operation
{
public:
	operLoad(game* r_pGame);
	virtual void Act();
};

class operExit :public operation
{
public:
	operExit(game* r_pGame);
	virtual void Act();
};