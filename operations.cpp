#include "operations.h"
#include "game.h"
#include "BasicShapes.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
    pGame = r_pGame;
}


/////////////////////////////////// class operStartGame  //////////////////


operStartGame::operStartGame(game* r_pGame):operation(r_pGame)
{
}

void operStartGame::Act()
{
    pGame->randomGenerator();
    //std::srand(static_cast<unsigned int>(std::time(0)));
    //window* pw = pGame->getWind();
    //int gameLevel = config.level;
    //int h = config.windHeight;
    //int w = config.windWidth;
    //const int maxNumberOfRandomShapes = 5;
    //point p[maxNumberOfRandomShapes];
    //for (int i = 0; i < maxNumberOfRandomShapes ;i++)
    //{
    //    //int random_number = std::rand() % (end - start + 1) + start;
    //    int random_x = std::rand() % (w- config.homeshape.width - config.homeshape.width + 1) + config.homeshape.width;
    //    int random_y = std::rand() % (h- config.homeshape.hight - config.homeshape.hight + 1) + config.homeshape.hight;
    //    p[i].x = random_x;
    //    p[i].y = random_y;


    //    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    //    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //    //take the aligned point as the sign shape ref point
    //    point signShapeRef = { random_x,random_y };

    //    //create a sign shape
    //    shape* psh = new Sign(pGame, signShapeRef);



    //    psh->draw();

    //}


    //switch (gameLevel)
    //{
    ////case 1:

    //}

}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
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
    shape* psh = new Sign(pGame, signShapeRef, RED);

    //Add the shape to the grid
    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}


/////////////////////////////////// class operAddIceCream  //////////////////

operAddIceCream::operAddIceCream(game* r_pGame) :operation(r_pGame)
{
}

void operAddIceCream::Act()
{
    window* pw = pGame->getWind();


    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the ice cream shape ref point
    point IceCreamShapeRef = { xGrid,yGrid };

    //create an Ice Cream shape
    shape* psh = new IceCream(pGame, IceCreamShapeRef, RED);

    //Add the shape to the grid
    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}

/////////////////////////////////// class operAddRocket  //////////////////

operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}

void operAddRocket::Act()
{
    window* pw = pGame->getWind();


    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the Rocket shape ref point
    point RocketShapeRef = { xGrid,yGrid };

    //create a Rocket shape
    shape* psh = new Rocket(pGame, RocketShapeRef, RED);

    //Add the shape to the grid
    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}


/////////////////////////////////// class operAddFish  //////////////////

operAddFish::operAddFish(game* r_pGame) :operation(r_pGame)
{
}

void operAddFish::Act()
{
    window* pw = pGame->getWind();


    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the Fish shape ref point
    point FishShapeRef = { xGrid,yGrid };

    //create a Fish shape
    shape* psh = new Fish(pGame, FishShapeRef, RED);

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


    shape* psh = new Triangle(pGame, TriShapeRef, _sidelength, rotation_angle);

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
    psh->resizeDown(0.5);
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
    if (psh!=nullptr)
        psh->resizeUp(1.5);
    pGrid->setActiveShape(psh);
    //pGame->getToolbar()->drawtoolbar(pGame);
}


operAddWatch::operAddWatch(game* r_pGame) : operation(r_pGame)
{
}

void operAddWatch::Act()
{
    window* pw = pGame->getWind();

    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefY % config.gridSpacing;

    point watchRefPoint = { xGrid, yGrid };




    shape* psh = new Watch(pGame, watchRefPoint, RED);

    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);
}


operAddHome::operAddHome(game* r_pGame) : operation(r_pGame)
{

}

void operAddHome::Act()
{
    window* pw = pGame->getWind();

    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefY % config.gridSpacing;

    point homeRefPoint = { xGrid, yGrid };





    shape* psh = new Home(pGame, homeRefPoint, RED);

    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);

}

operAddCar::operAddCar(game* r_pGame) :operation(r_pGame)
{
    window* pw = pGame->getWind();

    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefY % config.gridSpacing;

    point homeRefPoint = { xGrid, yGrid };





    shape* psh = new Car(pGame, homeRefPoint, RED);

    grid* pGrid = pGame->getGrid();
    pGrid->setActiveShape(psh);
}

void operAddCar::Act()
{
}

//////////////////////////// OperSave and OperLoad //////////////////////////
operSave::operSave(game* r_pGame) : operation(r_pGame)
{
}
void operSave::Act()
{
    int CurrentScore = pGame->getToolbar()->getScore();
    int CurrentLevel = pGame->getToolbar()->getLevel();
    int RemainingLives = pGame->getToolbar()->getRemainingLives();
    ofstream outfile;
    outfile.open("test.txt");
    outfile << CurrentScore << "\t" << CurrentLevel << "\t" << RemainingLives << "\n";
    pGame->getGrid()->SaveShapes(outfile);
    outfile.close();
}


operLoad::operLoad(game* r_pGame) : operation(r_pGame)
{
}
void operLoad::Act()
{
    ifstream infile;
    infile.open("text.txt");
    if (infile) {
        int CurrentLevel, RemainingLives, CurrentScore;
        infile >> CurrentScore >> CurrentLevel >> RemainingLives;
        pGame->getToolbar()->setScore(CurrentScore);
        pGame->getToolbar()->setLevel(CurrentLevel);
        pGame->getToolbar()->setRemainingLives(RemainingLives);
        pGame->getGrid()->LoadShapes(infile);
        infile.close();
    }
    else
        pGame->printMessage("No such file exists in the directory");
}