#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsRectItem>
#include <QBrush>
#include "Cell.h"
#include "Observer.h"
#include "Game.h"
#include <vector>
#include <utility>
extern Game * g;
extern Position * st;
extern Position * ed;
class CellView : public QGraphicsRectItem,Observer{
private:
    Cell * pCell;
    QBrush brush;
    int xPos = 0;
    int yPos = 0;

public:
    QGraphicsPixmapItem * Image = nullptr;
    CellView(Observable * obs,int x,int y,QGraphicsItem * parent=0);
    CellView() = default;
    void setOriginalColor(QColor color);
    void updateImage();
    void update() override{
        updateImage();
    }
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CELLVIEW_H
