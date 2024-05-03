#ifndef GAME_H
#define GAME_H

#include "cannon.h"
#include "troop.h"
#include "fence1.h"
#include "townhall.h"
#include "health.h"
#include "bullet.h"
#include "levels.h"
#include "workers.h"
#include "playermoney.h"
#include "shop.h"
#include "buttons.h"


#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
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
class shop;

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);

private:

    //VARIABLES
    QRandomGenerator* randomGenerator;
    QVector<QVector<int>> clanDesign;
    Levels* level;
    QGridLayout *layout;
    QGraphicsScene* scene;
    QGraphicsView* view;

    QPushButton* startButton;
    QPushButton* shopButton;
    pauseButton* pause;


    bool gameStarted;
    bool townHallDestroyed;


    QProgressBar* moneyBar;
    QLabel* moneyLabel;
    playerMoney* money;


    QRectF timerRect;
    QGraphicsTextItem* timerText;
    QLabel* timerLabel;
    QTimer* timer;

    QTimer* m_timer;
    QTimer* spawnTimer;
    QTimer* workerTimer;

    Townhall* townhall;
    Cannon* cannon;
    Fence1* fence;


    int workerCount = 0;

    shop* shopWindow;
    // Workers* worker;
    // int cellSize;
    // int sceneWidth;
    // int sceneHeight;
    //QProgressBar* timerBar;
    // int elapsedSeconds;


    //FUNCTIONS
    void startLevel();
    void displayClanDesign();
    void startGame();
    Townhall* findNearestTownhall(const QPointF& position);
    void checkCollisions(Troop* troop);
    void resetTimer();
    void mousePressEvent(QMouseEvent *event);
    void showPauseMenu();
    // void checkCollisionsworkers(Workers* worker);
    // void rebuildStructures();
    // void handleShopButton();

private slots:
    void handleStartButton();
    void handleSoundSettingsButton();
    void handlePauseButton();
    void formTroops();
    void moveTroops();
    void updateTimer();
    // void onFenceRepaired(Fence1* fence);
    void showShopWindow();
    // void moveWorkers();



};

#endif // GAME_H
