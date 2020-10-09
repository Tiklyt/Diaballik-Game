#include "CellView.h"
CellView::CellView(Observable * obs,int x,int y,QGraphicsItem * parent)
    :QGraphicsRectItem(parent){
    pCell = (Cell *) obs;
    pCell->attach(this);
    this->xPos= x;
    this->yPos= y;

}

void CellView::setOriginalColor(QColor color){
    brush.setColor(color);
        setBrush(color);
}

void CellView::updateImage(){
    if(pCell->getPawn().getColor() == Color::BLACK && !pCell->getPawn().containBall()){
        Image->setPixmap(QPixmap("C:\\Users\\braro\\Desktop\\Diaballik_pic\\noir.png"));
    } else if(pCell->getPawn().getColor() == Color::BLACK && pCell->getPawn().containBall()){
        Image->setPixmap(QPixmap("C:\\Users\\braro\\Desktop\\Diaballik_pic\\noir_bille.png"));
    } else if(pCell->getPawn().getColor() == Color::BROWN && !pCell->getPawn().containBall()){
        Image->setPixmap(QPixmap("C:\\Users\\braro\\Desktop\\Diaballik_pic\\rouge.png"));
    } else if(pCell->getPawn().getColor() == Color::BROWN && pCell->getPawn().containBall()){
        Image->setPixmap(QPixmap("C:\\Users\\braro\\Desktop\\Diaballik_pic\\rouge_bille.png"));
    } else if(pCell->getPawn().getColor() == Color::NUL){
        Image->setPixmap(QPixmap("C:\\Users\\braro\\Desktop\\Diaballik_pic\\invisible.png"));
    }

}

void CellView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Board & board = g->getBoard();
    Position pos(xPos,yPos);
    if(!board.getCell(pos).isFree() && !board.getCell(*st).getPawn().containBall()){
        g->select(pos);
        st = new Position(xPos,yPos);
    } else {
        ed = new Position(xPos,yPos);
        std::vector<Move> mv = g->getMoves();
        for(unsigned i = 0;i<mv.size();i++){
            if(mv[i].getStart().equals(*st) && mv[i].getEnd().equals(*ed)){
                g->mov(mv[i]);
            }
        }
    }

}
