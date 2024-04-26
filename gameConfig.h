#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

     double SizeOptions[3] = {0.5,1.0,2.0};
     double* sighSize = SizeOptions + 1;
     double* fishSize = SizeOptions + 1;
double* carSize = SizeOptions + 1;
double* rocketSize = SizeOptions + 1;

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;

	////----- Ice Cream shape Configuration ------////
	struct {
		int _radius = 57;
		int _sidelength = 125; double _rotation_angle = 180;
	}IceCreamShape;

	////------ Rocket shape Configuration -------////
	struct {
		int bodywdth = 40; int bodyhght = 200;
		int ___sidelength = 40; double _rotation_ang = 0; //for the top triangle
		int __sl = 20; double r_ang1 = -90; double r_ang2 = 90; //for the bottomleft and bottomright triangles

	}RocketShape;

	////------ Fish shape Configuration --------////
	struct {
		int fradius = 80;
		int Headsidelength = 70; double HeadRotationang = 90;
		int Tailsidelength = 60; double TailRotationang = 90;
		int Finswdth = 60; int Finshght = 30;

	}FishShape;

	////------ watch shape Configuration --------////
	struct {
		int radious = 100;

	}watchShape;
	 
	int lives = 5;
	int level = 1;
	int Score = 0;
}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here

	
	
	//ITM_SIGN,
	//ITM_RECT,
	//ITM_CIRC,
	//ITM_TRI,


	ITM_WATCH,      
	ITM_FISH,       
	ITM_ROCKET,        
	ITM_CONE,



	ITM_MINI,		//Minimaize shape icon 

	ITM_INC,		//Maximize shape icon

	ITM_DEL,		//Delete shape Icon

	ITM_ROTATE,     //Rotate shape item
	
	ITM_REFRESH,
	
	ITM_HINT,
	 	 
	ITM_SELECT,
	 
	ITM_SAVE,

	ITM_EXIT,			//Exit item

	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};



