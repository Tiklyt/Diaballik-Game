#include "mainwindow.h"
#include "Game.h"
#include "BoardView.h"
#include <QApplication>
Game * g = new Game(5,"Bilal","Jean");
Position * st = new Position(1,1);
Position * ed = new Position(1,1);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    BoardView * boardView =new BoardView(g,&g->getBoard());
    w.setCentralWidget(boardView);
    w.show();
    return a.exec();
}
