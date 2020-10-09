#include <BoardView.h>
#include "button.h"

BoardView::BoardView(Game * g,Board * b,QWidget * parent)
    :QGraphicsView(parent){
    gameScene = new QGraphicsScene();
    askSize();
}

void BoardView::askSize(){
    gameScene->setSceneRect(0,0,500,250);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,250);
    setScene(gameScene);
    Button * five = new Button("FIVExFIVE");
    five->setPos(150,20);
    connect(five,SIGNAL(clicked()),this,SLOT(five()));
    Button * seven = new Button("SEVENxSEVEN");
    connect(seven,SIGNAL(clicked()),this,SLOT(seven()));
    seven->setPos(150,100);
    Button * nine = new Button("NINExNINE");
    connect(nine,SIGNAL(clicked()),this,SLOT(nine()));
    nine->setPos(150,180);
    gameScene->addItem(five);
    gameScene->addItem(seven);
    gameScene->addItem(nine);
}

void BoardView::five(){
    gameScene->setSceneRect(0,0,1000,700);
    setFixedSize(1000,700);
    collect.resize(5);
    g = new Game(5,"","");
    g->initializer();
    for (unsigned i = 0; i < 5; ++i)
        collect[i].resize(5);
    drawGame(5);
    turn->setPos(600,150);
    turn->setPlainText("RED TURN");
    gameScene->addItem(turn);
}

void BoardView::seven(){
    gameScene->setSceneRect(0,0,1000,700);
    setFixedSize(1000,700);
    collect.resize(7);
    g = new Game(7,"","");
    for (unsigned i = 0; i < 7; ++i)
        collect[i].resize(7);
    drawGame(7);
    turn->setPos(800,500);
    turn->setPlainText("RED TURN");
    gameScene->addItem(turn);
}
void BoardView::nine(){
    gameScene->setSceneRect(0,0,1200,900);
    setFixedSize(1200,900);
     g = new Game(9,"","");
     collect.resize(9);
     for (unsigned i = 0; i < 9; ++i)
         collect[i].resize(9);
     drawGame(9);
     turn->setPos(950,350);
     turn->setPlainText("RED TURN");
     gameScene->addItem(turn);
}
void BoardView::drawGame(int size){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    setBackgroundBrush(brush);
    drawBoard(size);
    drawPawn(size);
    Button * switchPlayer = new Button("skip turn and check win");
    switchPlayer->setPos(750,100);
    Button * anti = new Button("anti-game");
    anti->setPos(750,200);
    Button * give = new Button("give up");
    give->setPos(750,300);

    if(size == 9){
        switchPlayer->setPos(950,100);
        anti->setPos(950,200);
        give->setPos(950,300);
    }
    connect(switchPlayer,SIGNAL(clicked()),this,SLOT(skip()));
    connect(anti,SIGNAL(clicked()),this,SLOT(anti()));
    connect(give,SIGNAL(clicked()),this,SLOT(giveup()));
    gameScene->addItem(switchPlayer);
    gameScene->addItem(anti);
    gameScene->addItem(give);
}


void BoardView::skip(){
    if(g->thereIsWinner()){
        g->resetTable();
        if(g->getCurrentPlayer().getColor() == BLACK){
            turn->setPlainText("BLACK WON !");
        } else {
            turn->setPlainText("RED WON !");
        }
    }else if(g->askSkipTurn()){
        if(g->getCurrentPlayer().getColor() == BLACK){
            turn->setPlainText("BLACK TURN");
        } else {
            turn->setPlainText("RED TURN");
        }
    }
}

void BoardView::anti(){
    if(g->askAntiGame()){
        g->resetTable();
        if(g->getCurrentPlayer().getColor() == BLACK){
            turn->setPlainText("BLACK WON");
        } else {
            turn->setPlainText("RED WON");
        }
    }
}
void BoardView::giveup(){
    g->resetTable();
    if(g->getCurrentPlayer().getColor() == BROWN){
        turn->setPlainText("BLACK WON");
    } else {
        turn->setPlainText("RED WON");
    }
}

void BoardView::drawBoard(int size){
        for(int i = 0; i < size;i++){
            for(int j = 0;j < size;j++){
                collect[i][j] = new CellView(&g->getBoard().getCell(Position(i,j)),j,i);
                collect[i][j]->setRect(0,0,100,100);
                collect[i][j]->setPos(100*i,100*j);
                if((i+j)%2==0)
                    collect[i][j]->setBrush(Qt::lightGray);
                else
                    collect[i][j]->setBrush(Qt::darkRed);
                 gameScene->addItem(collect[i][j]);
            }
        }
}

void BoardView::drawPawn(int size){
    for(int i = 0; i < size;i++){
        for(int j = 0;j<size;j++){
            collect[i][j]->Image = new QGraphicsPixmapItem;
            collect[i][j]->updateImage();
            collect[i][j]->Image->setPos(collect[i][j]->y()+50- collect[i][j]->Image->pixmap().width()/2  ,collect[i][j]->x()+50-collect[i][j]->Image->pixmap().width()/2);
            gameScene->addItem(collect[i][j]->Image);
        }
    }
}
