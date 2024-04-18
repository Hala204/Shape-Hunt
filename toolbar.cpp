#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	//basic shapes
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_Sign.jpg";
	toolbarItemImages[ITM_RECT] = "images\\toolbarItems\\toolbar_Rect.jpg";
	toolbarItemImages[ITM_CIRC] = "images\\toolbarItems\\toolbar_Circ.jpg";
	toolbarItemImages[ITM_TRI] = "images\\toolbarItems\\toolbar_Tri.jpg";

	//composite shapes
	toolbarItemImages[ITM_WATCH] = "images\\toolbarItems\\watch.jpg";
	toolbarItemImages[ITM_HOME] = "images\\toolbarItems\\home.jpg";
	toolbarItemImages[ITM_ROCKET] = "images\\toolbarItems\\ROCKET.jpg";
	toolbarItemImages[ITM_CONE] = "images\\toolbarItems\\cone.jpg";
	
	//icons
	toolbarItemImages[ITM_INCREASE] = "images\\toolbarItems\\increase.jpg";
	toolbarItemImages[ITM_DECREASE] = "images\\toolbarItems\\decrease.jpg";
	toolbarItemImages[ITM_ROTATE] = "images\\toolbarItems\\rotate.jpg";
	toolbarItemImages[ITM_REFRESH] = "images\\toolbarItems\\refresh.jpg";
	toolbarItemImages[ITM_HINT] = "images\\toolbarItems\\hint.jpg";
	toolbarItemImages[ITM_DELETE] = "images\\toolbarItems\\del.jpg";
	toolbarItemImages[ITM_SELECT] = "images\\toolbarItems\\select.jpg";
	toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\save.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";


	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

