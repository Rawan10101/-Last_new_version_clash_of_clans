#ifndef GAME_H
#define GAME_H

#include "cannon.h"
#include "troop.h"
#include "fence1.h"
#include "townhall.h"
#include "health.h"
#include "bullet.h"
#include "levels.h"
#include"workers.h"

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include<QTimer>
#include<QLabel>
#include<QPushButton>
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFrame>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QProgressBar>
#include <QTime>
#include <QGraphicsProxyWidget>
#include <QCoreApplication>
#include <QtNumeric>
#include"shop.h"
class shop;
class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);

  //  void printClanDesign();
    void displayClanDesign();
    void adjustSceneSize();
    void startGame();
    void resetTimer();

    void handleSoundSettingsButton();
    // void handleShopButton();
    void increaseMoney(int value);
    void decreaseMoney(int value);
    int getCurrentMoney();
    void setMoney(int value);

     QTimer* m_timer;

    // shop* shopWindow;
private:

     QLabel* moneyLabel;
    Levels* level;
    int currentMoney;
    void startLevel();
    QGridLayout *layout;
    QVector<QVector<int>> clanDesign;
    QProgressBar* moneyBar;
   QGraphicsView* view;
   QGraphicsScene* scene;
    int cellSize;
    int sceneWidth;
    int sceneHeight;
    //QProgressBar* timerBar;
    QTimer* timer;
    QRectF timerRect;
    QLabel* timerLabel;
    bool gameStarted;
    int elapsedSeconds;
    QGraphicsTextItem* timerText;
    QPushButton* startButton;
    Fence1* fence;
    Cannon* cannon;
    Townhall* townhall;
    QPixmap scalePixmap(const QPixmap& pixmap, int width, int height);
    Health* health;
    Townhall*findNearestTownhall(const QPointF& position);
    bool townHallDestroyed;
    void mousePressEvent(QMouseEvent *event);
    bool cannonDestroyed;
    QRandomGenerator* randomGenerator;
    QTimer* spawnTimer;


private slots:
    void handleStartButton();
    void updateTimer();

   void showShopWindow();

public slots:
    void checkCollisions(Troop* troop);
    void moveTroops();
    void formTroops();

    void onFenceRepaired(Fence1* fence);


};

#endif // GAME_H
