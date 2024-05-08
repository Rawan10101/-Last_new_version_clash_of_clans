#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QObject>

class pauseButton : public QPushButton
{
    QGraphicsScene* scene;
public:
    pauseButton();

public slots:
    void handlePauseButton();

};

#endif // BUTTONS_H
