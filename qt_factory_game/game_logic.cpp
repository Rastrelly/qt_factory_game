#pragma once

#include "stdafx.h"
#include "game_logic.h"


// Factory method to create objects of different types. 
// Change is required only in this function to create a new object type 
gameBuilding* gameBuilding::Create(bldgType type) {
	switch (type)
	{
	case ebHouse:
		return new bHouse();
	case ebPlant:
		return new bPlant();
	case ebGenerator:
		return new bGenerator();
	case ebBar:
		return new bBar();
	default:
		return NULL;
	}
}
