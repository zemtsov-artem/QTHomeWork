#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "movesnake.h"
#include <QGraphicsRectItem>
#include <QTableView>
#include "score.h"
#include "button.h"
#include "userinfo.h"
#include <QSqlDatabase>
#include "tableresults.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:

    Game(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    Score *score;
    QString userName;
    QString userScore;
    QGraphicsScene *gameScene ;
    MoveSnake *snake;
    MoveSnake *snake2;
    void displayMainMenu(QString title, QString play);
    QGraphicsTextItem *titleText;
    TableResults *mytable;
    UserInfo * player;
    void create_db();
    void read_db();
    void add_to_db();

    Button *b;
    void gameOver();
public slots:
    void start();
    void showTable();
};

#endif // GAME_H

