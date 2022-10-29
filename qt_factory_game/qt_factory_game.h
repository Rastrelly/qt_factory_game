#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt_factory_game.h"
#include "gameManager.h"

class qt_factory_game : public QMainWindow
{
	Q_OBJECT

public:
	qt_factory_game(QWidget *parent = nullptr);
	void setGameManager(gameManager * val);
	gameManager * getGameManager() { return gm; }
    ~qt_factory_game();

private slots:
	void buttonBuildClick();
	void indexUpdate(int id);
	void showBuilding(int id);

private:
    Ui::qt_factory_gameClass ui;
	gameManager * gm;
	void refreshBuildingList();
};
