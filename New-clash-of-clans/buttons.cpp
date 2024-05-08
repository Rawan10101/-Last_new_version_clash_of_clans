#include "buttons.h"

pauseButton::pauseButton()
{
    setFixedSize(80, 80);
    setStyleSheet("QPushButton { border-radius : 40px; background-color : transparent; }");
    setIcon(QIcon(":/images/pause.png"));
    setIconSize(QSize(80, 80));
    setFlat(false);
    // pauseButton->move(100,100);
}
