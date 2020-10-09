#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <Game.h>
#include <Board.h>
#include <CellView.h>
#include <vector>
extern Game * g;
class BoardView :  public QGraphicsView{


    Q_OBJECT

public:


    BoardView(Game * g,Board * b,QWidget * parent = 0);
    void drawBoard(int size);
    void drawPawn(int size);
    void askSize();
    void drawGame(int size);

public slots:
    void skip();
    void anti();
    void giveup();
    void five();
    void seven();
    void nine();

private :
    Board * b;
    QGraphicsScene *gameScene;
    std::vector<std::vector<CellView *>>collect;
    QGraphicsTextItem * turn = new QGraphicsTextItem;
};

#endif // BOARDVIEW_H
