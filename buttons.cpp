#include "buttons.h"

pauseButton::pauseButton()
{
    setFixedSize(80, 80);
    setStyleSheet("QPushButton { border-radius : 40px; background-color : transparent; }");
    setIcon(QIcon(":/images/pause.png"));
    setIconSize(QSize(80, 80));
    setFlat(false);
}

startMenuButtons::startMenuButtons(QString text)
{
    setText(text);
    setStyleSheet("font-size: 20px;");
}

// moneyBar::moneyBar()
// {
//     backgroundRect = new QGraphicsRectItem;
//     backgroundRect->setRect(0,0,90,40);
//     QBrush grayBrush(Qt::gray);
//     backgroundRect->setBrush(grayBrush);

//     moneyText = new QGraphicsTextItem;
//     moneyText->setPlainText(QString::number(0));
//     moneyText->setFont(QFont("Arial", 16));
//     moneyText->setDefaultTextColor(Qt::white);

//     QPixmap pixmap1(":/images/coin.png");
//     pixmap1 = pixmap1.scaledToHeight(50);
//     pixmap1 = pixmap1.scaledToWidth(40);
//     moneyImage = new QGraphicsPixmapItem;
//     moneyImage->setPixmap(pixmap1);

//     moneyText->setParentItem(backgroundRect);
//     moneyImage->setParentItem(backgroundRect);

// }

// void moneyBar::setPos(qreal X, qreal Y)
// {
//     backgroundRect->setPos(X,Y);
//     moneyText->setPos(X,Y);
//     moneyImage->setPos(X + 90, Y);
// }
