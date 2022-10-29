#include "stdafx.h"
#include "qt_factory_game.h"

qt_factory_game::qt_factory_game(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.btnBuild, SIGNAL(clicked()), SLOT(buttonBuildClick()));
	connect(ui.cbBuildings, SIGNAL(currentIndexChanged(int)), SLOT(indexUpdate(int)));
	connect(ui.lbBuildingsList, SIGNAL(currentRowChanged(int)), SLOT(showBuilding(int)));
}

qt_factory_game::~qt_factory_game()
{}

void qt_factory_game::setGameManager(gameManager * val)
{ gm = val; }

void qt_factory_game::buttonBuildClick()
{
	bldgType cbt;

	switch (ui.cbBuildings->currentIndex())
	{
	//ebHouse, ebPlant, ebGenerator, ebBar
	case 0: cbt = ebHouse; break;
	case 1: cbt = ebPlant; break;
	case 2: cbt = ebGenerator; break;
	case 3: cbt = ebBar; break;
	default: cbt = ebHouse; break;
	}
	
	gm->constructBuilding(cbt);
	refreshBuildingList();
}

void qt_factory_game::refreshBuildingList()
{
	ui.lbBuildingsList->clear();
	int l = gm->getBuildingsAmt();
	if (l > 0)
	{
		for (int i = 0; i < l; i++)
		{
			QString aText;
			aText.setNum(i);
			aText += ") ";
			QString bText;
			bText.fromStdString(gm->getListBuilding(i)->getName());
			ui.lbBuildingsList->addItem(aText + bText);
			QString cText;
			cText.setNum(gm->getListBuilding(i)->getUpkeep());
			ui.labelName->setText(cText);
		}
	}
	else
	{
		ui.lbBuildingsList->addItem("No buidings found!");
	}
}

void qt_factory_game::indexUpdate(int id)
{
	QString ltxt; ltxt.setNum(id);
	ui.labelIndex->setText(ltxt);
}

void qt_factory_game::showBuilding(int id)
{
	QString ltxt;
	QString ltxt2;
	/*
	std::string getName() { return bName; }
	float getPopChange() { return popChange; }
	float getPowChange() { return powChange; }
	float getUpkeep() { return upkeep; }
	float getHousing() { return housing; }
	float getWForceRq() { return wforce_rq; }
	float getWForce() { return wforce; }
	float getIncome() { return income; }
	*/
	gameBuilding * gb = gm->getListBuilding(id);
	ui.txtBData->clear();
	ltxt.fromStdString(gb->getName());
	ui.txtBData->appendPlainText(ltxt);
	ltxt = "Upkeep: ";
	ltxt2.setNum(gb->getUpkeep());
	ui.txtBData->appendPlainText(ltxt+ltxt2);
}