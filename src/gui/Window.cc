#include "Window.hh"


#define WINDOW_PADDING 8


Window(int offsetX,int offsetY,int width,int height):
Node(offsetX,offsetY,width,height)
{}


~Window()
{
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		delete *it;
	}
}


int onEvent(SDL_Event * e)
{
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		int value = (*it)->onEvent(e);
		if (value != 0) return value;
	}
	return 0;
}


void render(SDL_Renderer * renderer,int x = 0,int y = 0)
{
	erg;
}