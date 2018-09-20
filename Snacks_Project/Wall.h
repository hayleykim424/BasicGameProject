#pragma once
#include "GameObject.h"
class Wall :
	public GameObject
{
private:
	int w, h;

public:
	Wall();
	~Wall();

	void setWidthAndHeight(int w, int h);

	//override
	virtual void draw();
};

