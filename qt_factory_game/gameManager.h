#pragma once
#include "stdafx.h"
#include "game_logic.h"

class gameManager
{
private:
	float money, power, pop;
	std::vector <gameBuilding*> buildings;
	gameClient * fClient;
public:
	gameManager();
	void setFClient(gameClient * cl) { fClient = cl; };
	float getMoney() { return money; }
	float getPower() { return power; }
	float getPop() { return pop; }
	void changeMoney(float val) { money += val; };
	void changePower(float val) { power += val; };
	void changePop(float val) { pop += val; };
	void setMoney(float val) { money = val; };
	void setPower(float val) { power = val; };
	void setPop(float val) { pop = val; };
	void constructBuilding(bldgType btp);
	void pushBuilding(gameBuilding * gb);
	int getBuildingsAmt() { return buildings.size(); }
	gameBuilding * getListBuilding(int id) { return buildings[id]; }
};

