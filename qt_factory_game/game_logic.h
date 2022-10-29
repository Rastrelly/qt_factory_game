#pragma once

#include <string>


enum bldgType {
	ebHouse, ebPlant, ebGenerator, ebBar
};

// Library classes 
class gameBuilding {
private:
	std::string bName;
	float popChange;
	float powChange;
	float upkeep;
	float housing;
	float wforce_rq;
	float wforce;
	float income;
public:
	virtual void setupBuilding() = 0;
	virtual void processTurn(float &moneytransf) = 0;

	static gameBuilding* Create(bldgType type);

	std::string getName() { return bName; }
	float getPopChange() { return popChange; }
	float getPowChange() { return powChange; }
	float getUpkeep() { return upkeep; }
	float getHousing() { return housing; }
	float getWForceRq() { return wforce_rq; }
	float getWForce() { return wforce; }
	float getIncome() { return income; }
	void setName(std::string nm) { bName = nm; }
	void setPopChange(float val) { popChange = val; };
	void setPowChange(float val) { powChange = val; };
	void setUpkeep(float val) { upkeep = val; };
	void setHousing(float val) { housing = val; };
	void setWForceRq(float val) { wforce_rq = val; };
	void setWForce(float val) { wforce = val; };
	void setIncome(float val) { income = val; }
};

class bBar : public gameBuilding {
public:
	void setupBuilding() {
		setName("Bar");
		setPopChange(0);
		setUpkeep(5);
		setHousing(0);
		setWForceRq(10);
		setWForce(0);
	}
	void processTurn(float &moneytransf)
	{
		moneytransf = 10 * (getWForce() / getWForceRq());
	}
};

class bPlant : public gameBuilding {
public:
	void setupBuilding() {
		setName("Plant");
		setPopChange(0);
		setUpkeep(15);
		setHousing(0);
		setWForceRq(20);
		setWForce(0);
	}
	void processTurn(float &moneytransf)
	{
		moneytransf = 50 * (getWForce() / getWForceRq());
	}
};

class bGenerator : public gameBuilding {
public:
	void setupBuilding() {
		setName("Generator");
		setPopChange(0);
		setUpkeep(0);
		setHousing(0);
		setWForceRq(10);
		setWForce(0);
	}
	void processTurn(float &moneytransf)
	{
		moneytransf = 1 * (getWForce() / getWForceRq());
	}
};

class bHouse : public gameBuilding {
public:
	void setupBuilding() {
		setName("House");
		setPopChange(1);
		setUpkeep(5);
		setHousing(50);
		setWForceRq(0);
		setWForce(0);
	}
	void processTurn(float &moneytransf)
	{
		moneytransf = 0;
	}
};

// Client class 
class gameClient {
private:
	gameBuilding *pBuilding;

public:
	// Client doesn't explicitly create objects 
	// but passes type to factory method "Create()" 
	gameClient() {}
	~gameClient() {
		if (pBuilding) {
			delete[] pBuilding;
			pBuilding = NULL;
		}
	}

	gameBuilding* getBuilding(bldgType type) {
		pBuilding = gameBuilding::Create(type);
		return pBuilding;
	}
};

