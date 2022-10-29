#include "stdafx.h"
#include "qt_factory_game.h"
#include <QtWidgets/QApplication>

gameManager mgm;
gameClient mgc;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_factory_game w;
	w.setGameManager(&mgm);
	w.getGameManager()->setFClient(&mgc);
    w.show();
    return a.exec();
}
