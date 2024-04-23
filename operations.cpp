#include "operations.h"
#include "game.h"
#include "BasicShapes.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

/////////////////////////////////// class operAddRect  //////////////////


operAddRect::operAddRect(game* r_pGame) :operation(r_pGame)
{
}

void operAddRect::Act()
{
    window* pw = pGame->getWind();

    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefY % config.gridSpacing;

    point rectShapeRef = { xGrid, yGrid };

    int rectHeight = 120; 
    int rectWidth = 200; 

    shape* psh = new Rect(pGame, rectShapeRef, rectHeight, rectWidth);

    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}


/////////////////////////////////// class operAddCirc  //////////////////


operAddCirc::operAddCirc(game* r_pGame) :operation(r_pGame)
{
}

void operAddCirc::Act()
{
    window* pw = pGame->getWind();

    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefY % config.gridSpacing;

    point CircShapeRef = { xGrid, yGrid };

    int radius = 80;

    shape* psh = new circle(pGame, CircShapeRef, radius);

    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}


/////////////////////////////////// class operAddTri  //////////////////


operAddTri::operAddTri(game* r_pGame) :operation(r_pGame)
{
}

void operAddTri::Act()
{
    window* pw = pGame->getWind();

    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefY % config.gridSpacing;

    point TriShapeRef = { xGrid, yGrid };

    int _sidelength = 160;
    int rotation_angle = 0;


    shape* psh = new Triangle(pGame, TriShapeRef, _sidelength,rotation_angle);

    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}


operRotate::operRotate(game* r_pGame) :operation(r_pGame)
{
}

void operRotate::Act()
{
    grid* pGrid = pGame->getGrid();
    shape* p = pGrid->getActiveShape();
    if (p)
        p->Rotate();
}


operMinimize::operMinimize(game* r_pGame) : operation(r_pGame)
{

}

void operMinimize::Act()
{
    grid* pGrid = pGame->getGrid();
    shape* psh = pGrid->getActiveShape();
    psh->resize(0.5);
    pGrid->setActiveShape(psh);
}

operDEL::operDEL(game* r_pGame) : operation(r_pGame)
{
}

void operDEL::Act()
{
    pGame->getGrid()->clearGrid();
}

operINC::operINC(game* e_pGame) : operation(e_pGame)
{
}

void operINC::Act()
{
    grid* pGrid = pGame->getGrid();
    shape* psh = pGrid->getActiveShape();
    psh->resize(1.5);
    pGrid->setActiveShape(psh);
}
