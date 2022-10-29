#pragma once

#include "stdafx.h"
#include "gameManager.h"

gameManager::gameManager()
{
	money = 1000;
	power = 0;
	pop = 0;	
}

void gameManager::constructBuilding(bldgType btp)
{
	pushBuilding(fClient->getBuilding(btp));	
}

void  gameManager::pushBuilding(gameBuilding * gb)
{
	gb->setupBuilding();
	buildings.push_back(gb);	
}