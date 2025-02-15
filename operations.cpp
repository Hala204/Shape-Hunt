#include "operations.h"
#include "game.h"
#include "BasicShapes.h"
#include "CompositeShapes.h"
#include <iostream>
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


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);
        

        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");






        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh=NULL;
        if (psh)
        delete psh;


        psh = new Sign(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();

        //
        bool i= this->pGame->getGrid()->handleMatch();
        if (i == true)
            break;
        //this->pGame->getWind()->WaitMouseClick(x, y);

    } while (kType != ESCAPE);

    pw->SetBuffering(false);

    

}


/////////////////////////////////// class operAddIceCream  //////////////////

operAddIceCream::operAddIceCream(game* r_pGame) :operation(r_pGame)
{
}

void operAddIceCream::Act()
{
    window* pw = pGame->getWind();

    //TODO:
    // Don't allow adding new shape if there is alreday an active shape

    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the sign shape ref point
    point signShapeRef = { xGrid,yGrid };


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);


        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");





        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh = NULL;
        if (psh)
            delete psh;


        psh = new IceCream(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();
        bool i = this->pGame->getGrid()->handleMatch();
        if (i == true)
            break;

        //


    } while (kType != ESCAPE);

    pw->SetBuffering(false);

}

/////////////////////////////////// class operAddRocket  //////////////////

operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}

void operAddRocket::Act()
{
    window* pw = pGame->getWind();

    //TODO:
    // Don't allow adding new shape if there is alreday an active shape

    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the sign shape ref point
    point signShapeRef = { xGrid,yGrid };


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);


        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");





        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh = NULL;
        if (psh)
            delete psh;


        psh = new Rocket(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();
        bool i = this->pGame->getGrid()->handleMatch();
        if (i == true)
            break;

        //


    } while (kType != ESCAPE);

    pw->SetBuffering(false);

}


/////////////////////////////////// class operAddFish  //////////////////

operAddFish::operAddFish(game* r_pGame) :operation(r_pGame)
{
}

void operAddFish::Act()
{
    window* pw = pGame->getWind();

    //TODO:
    // Don't allow adding new shape if there is alreday an active shape

    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the sign shape ref point
    point signShapeRef = { xGrid,yGrid };


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);


        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");





        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh = NULL;
        if (psh)
            delete psh;


        psh = new Fish(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();
        bool i = this->pGame->getGrid()->handleMatch();
        if (i == true)
            break;

        //


    } while (kType != ESCAPE);

    pw->SetBuffering(false);

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

    //TODO:
    // Don't allow adding new shape if there is alreday an active shape

    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the sign shape ref point
    point signShapeRef = { xGrid,yGrid };


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);


        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");





        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh = NULL;
        if (psh)
            delete psh;


        psh = new Watch(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();
        bool i = this->pGame->getGrid()->handleMatch();
        if (i == true)
            break;
        //


    } while (kType != ESCAPE);

    pw->SetBuffering(false);
}


operAddHome::operAddHome(game* r_pGame) : operation(r_pGame)
{

}

void operAddHome::Act()
{
    window* pw = pGame->getWind();

    //TODO:
    // Don't allow adding new shape if there is alreday an active shape

    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the sign shape ref point
    point signShapeRef = { xGrid,yGrid };


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);


        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");





        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh = NULL;
        if (psh)
            delete psh;


        psh = new Home(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();
        bool i = this->pGame->getGrid()->handleMatch();
        if (i == true)
            break;
        //


    } while (kType != ESCAPE);

    pw->SetBuffering(false);

}

operAddCar::operAddCar(game* r_pGame) :operation(r_pGame)
{
    window* pw = pGame->getWind();

    //TODO:
    // Don't allow adding new shape if there is alreday an active shape

    //align reference point to the nearest grid point
    int xGrid = config.RefX - config.RefX % config.gridSpacing;
    int yGrid = config.RefY - config.RefX % config.gridSpacing;

    //take the aligned point as the sign shape ref point
    point signShapeRef = { xGrid,yGrid };


    /////////////////////// move shapes 
    pw->FlushKeyQueue();

    pw->SetFont(20, BOLD, BY_NAME, "Arial");

    pw->SetBuffering(true);

    int RectULX = xGrid;
    int RectULY = yGrid;

    bool bDragging = false;


    char cKeyData;
    keytype kType;

    // Loop until there escape is pressed
    do
    {


        kType = pw->GetKeyPress(cKeyData);


        //Create and draw the grid
        //this->pGame->createGrid();
        this->pGame->getGrid()->draw();	//draw the grid and all shapes it contains.

        this->pGame->createToolBar();

        //Create and clear the status bar
        this->pGame->clearStatusBar();
        this->pGame->printMessage("you can move the shape now to match the generated shapes, press exit when you finish ");





        if (kType == ARROW)
        {
            switch (cKeyData)
            {
            case 2:	//Down Arrow
                RectULY += 1;
                break;
            case 4:	//left Arrow
                RectULX -= 1;
                break;
            case 6:	//Down Arrow
                RectULX += 1;
                break;
            case 8:	//Down Arrow
                RectULY -= 1;
                break;
            }

        }



        shape* psh = NULL;
        if (psh)
            delete psh;


        psh = new Car(pGame, signShapeRef, RED);
        grid* pGrid = pGame->getGrid();

        pGrid->setActiveShape(psh);

        signShapeRef.x = RectULX;

        signShapeRef.y = RectULY;

        pw->SetPen(BLUE);
        pw->SetBrush(BLUE);
        //this->pGame->getGrid()->draw();
        pw->UpdateBuffer();
        psh->draw();
        this->pGame->getGrid()->draw();
        bool i = this->pGame->getGrid()->handleMatch();
        if (i==true)
            break;
        


    } while (kType != ESCAPE );

    pw->SetBuffering(false);
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
    int CurrentScore = pGame->getScore();
    int CurrentLevel = pGame->getLevel();
    int RemainingLives = pGame->getLives();
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
    infile.open("test.txt");
    int CurrentLevel, RemainingLives, CurrentScore;
    if (infile >> CurrentScore >> CurrentLevel >> RemainingLives) 
    {
        pGame->setScore(CurrentScore);
        pGame->setLevel(CurrentLevel);
        pGame->setLives(RemainingLives);
        pGame->getGrid()->LoadShapes(infile);
        infile.close();
    }
    else
        pGame->printMessage("No such file exists in the directory");
}

/////////////////////////////////// class operExit  //////////////////

operExit::operExit(game* r_pGame) : operation(r_pGame)
{
}

void operExit::Act()
{
        cout << "Do you want to save the game before exiting? (y/n): ";
        char response;
        cin >> response;

        if (response == 'y' || response == 'Y') {
            int CurrentScore = pGame->getScore();
            int CurrentLevel = pGame->getLevel();
            int RemainingLives = pGame->getLives();
            ofstream outfile;
            outfile.open("test.txt");
            outfile << CurrentScore << "\t" << CurrentLevel << "\t" << RemainingLives << "\n";
            pGame->getGrid()->SaveShapes(outfile);
            outfile.close();
            this->pGame->getGrid()->SaveShapes(outfile);
        }
        pGame->cleanUp();
        exit(0); 
}

