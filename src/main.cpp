#include "game.h"
#include <QApplication>
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //TableResults tr;
    //tr.show();
    game = new Game();
    game->show();
    game->displayMainMenu("Snake Master","Play");
    return a.exec();
}

