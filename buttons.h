#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QObject>

class pauseButton : public QPushButton
{
public:
    pauseButton();
};


class startMenuButtons : public QPushButton
{
public:
    startMenuButtons(QString text);
};

// class moneyBar : public QGraphicsRectItem
// {
//     QGraphicsRectItem* backgroundRect;
//     QGraphicsTextItem* moneyText;
//     QGraphicsPixmapItem* moneyImage;

// public:
//     moneyBar();
//     void setPos(qreal X, qreal Y);
// };

#endif // BUTTONS_H
