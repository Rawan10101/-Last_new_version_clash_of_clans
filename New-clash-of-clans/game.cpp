#include "Game.h"
using namespace std;

Game::Game(QWidget *parent) : QWidget(parent)
{
    int seed = QDateTime::currentMSecsSinceEpoch(); //seeding randomgenerator for troop spawning
    randomGenerator = new QRandomGenerator(seed);

    level = new Levels; //creating an instance of level
    layout = new QGridLayout(this);
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    //setting background
    QPixmap backgroundPixmap(":/images/Background.png"); // background image empty field
    if (!backgroundPixmap.isNull())
    {
        view->setBackgroundBrush(backgroundPixmap);
    }

    //layout
    setLayout(layout);
    view->setStyleSheet("background: transparent; border: 0px");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    layout->addWidget(view);

    //START BUTTON
    startButton = new QPushButton("Start Level " + QString::number(level->currLevel), this);
    startButton->setStyleSheet("font-size: 20px;");
    startButton->move(100,100);
    connect(startButton, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    layout->addWidget(startButton);
    layout->setAlignment(startButton, Qt::AlignCenter | Qt::AlignTop);

    gameStarted = false;
    startLevel(); //sets scene and view and clan design and timertext

    QGraphicsProxyWidget *buttonProxy = scene->addWidget(startButton); //adding start button to scene
    buttonProxy->setPos(scene->width() - startButton->width() - 10, 10);


    Fence1* fence;
    Cannon* cannon;
    Townhall* townhall;

    //-----------------------------------------------//

    //sound settings button
    QPushButton* soundSettingsButton = new QPushButton("Sound Settings", this);
    soundSettingsButton->setGeometry(100, 100, 150, 30);
    layout->addWidget(soundSettingsButton);

    //shop button
    QPushButton* shopButton = new QPushButton("Shop", this);
    shopButton->setGeometry(100, 140, 150, 30);
    layout->addWidget(shopButton);

    connect(soundSettingsButton, &QPushButton::clicked, this, &Game::handleSoundSettingsButton);
    connect(shopButton, &QPushButton::clicked, this, &Game::handleShopButton);

    //MoneyBar will increase by 5 after killing one troop and increase by 20 when a level is completed
    QProgressBar* moneyBar= new QProgressBar(this);
    moneyBar->setMinimum(0);
    moneyBar->setMaximum(1000);
    currentMoney=0;
    moneyBar->setValue(currentMoney);



}

void Game::startLevel()
{
        startButton->setText("Start Level " + QString::number(level->currLevel)); //to update start button text
        startButton->setEnabled(true);
        gameStarted = false;


    clanDesign = level->getDesignVector(); //sends a vector for the clan design based on the current level

    scene->setSceneRect(0, 0, clanDesign[0].size() * 50, clanDesign.size() * 50); //set scene and view
    view->setFixedSize(clanDesign[0].size() * 50, clanDesign.size() * 50);


    //----------------------------------------------//

    //TIMER LABEL
    timerRect = QRectF(10, 10, 100, 40); // Position and size of the timer rectangle
    timerText = new QGraphicsTextItem();
    timerText->setPos(timerRect.topLeft());
    timerText->setPlainText("0:00");
    timerText->setDefaultTextColor(Qt::white);
    timerText->setFont(QFont("Arial", 20));
    timerText->setOpacity(0.8);
    timerText->setPos(0,0);
    scene->addItem(timerText);


    startButton->show();

    qDebug()<<"Working";

    townHallDestroyed=false;

    //-----------------------------------------------//

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer())); //game timer

    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT (moveTroops())); //to move troops
    // m_timer->start(100);

    spawnTimer = new QTimer();
    connect(spawnTimer, SIGNAL(timeout()),this, SLOT (formTroops()));
    qDebug()<< "end";
}

void Game::handleSoundSettingsButton()
{



}

void Game::handleShopButton()
{
    QMessageBox shopMessageBox(this);
    shopMessageBox.setWindowTitle("Shop");
    shopMessageBox.setIcon(QMessageBox::Information);


    QLabel townhallLabel("Townhall", &shopMessageBox);
    QLabel fenceLabel("Fence", &shopMessageBox);
    QLabel cannonLabel("Cannon", &shopMessageBox);


    QPushButton* townhallUpgradeButton = new QPushButton("Upgrade", &shopMessageBox);
    QPushButton* fenceUpgradeButton = new QPushButton("Upgrade", &shopMessageBox);
    QPushButton* cannonUpgradeButton = new QPushButton("Upgrade", &shopMessageBox);


    // connect(townhallUpgradeButton, &QPushButton::clicked, this, &Game::handleTownhallUpgradeButton);
    // connect(fenceUpgradeButton, &QPushButton::clicked, this, &Game::handleFenceUpgradeButton);
    // connect(cannonUpgradeButton, &QPushButton::clicked, this, &Game::handleCannonUpgradeButton);


    QVBoxLayout* layout1 = new QVBoxLayout;
    layout1->addWidget(&townhallLabel);
    layout1->addWidget(townhallUpgradeButton);
    layout1->addWidget(&fenceLabel);
    layout1->addWidget(fenceUpgradeButton);
    layout1->addWidget(&cannonLabel);
    layout1->addWidget(cannonUpgradeButton);

    shopMessageBox.setLayout(layout1);

    int newMoney = currentMoney - 50;

    int result = shopMessageBox.exec();

    if (result == QMessageBox::Ok) {
        //new photo for the item which is upgraded
        if (newMoney >= 0) {
            currentMoney = newMoney;
        } else {
            QMessageBox::critical(this, "Not enough Money", "You don't have enough money for the upgrades.");
        }
    }
}


void Game::displayClanDesign()
{
    const int tileSize = 50;
    const int fenceSize = tileSize ;
    const int castleSize = tileSize;
    const int cannonSize = tileSize;

    qDebug()<<"inside displayClanDesign";

    for (int i = 0; i < clanDesign.size(); i++)
    {
        for (int j = 0; j < clanDesign[i].size(); j++)
        {
            int element = clanDesign[i][j]; //element at the current position

            if (element == 1) // castle
            {
                townhall = new Townhall();
                townhall->setPos(j * castleSize, i * castleSize);
                scene->addItem(townhall);
            }
            else if (element == 2) // cannon
            {
                 cannon = new Cannon();
                cannon->setPos(j * cannonSize, i * cannonSize);
                scene->addItem(cannon);
            }
            else if (element == 3) // fence
            {
              qDebug()<<"Fence1";
               fence = new Fence1();
                 fence->setPos(j * fenceSize, i * fenceSize);
                scene->addItem(fence);
                 qDebug()<<"Fence2";
            }
        }
    }
}


void Game::startGame()
{
    startButton->hide();
    resetTimer();
    timerText->show();
    timer->start(1000);
    displayClanDesign();

    if (level->currLevel == 1) //enemies spawn more frequently as level increases
        spawnTimer->start(4000);

    else if (level->currLevel == 2)
        spawnTimer->start(3000);

    else if (level->currLevel == 3)
        spawnTimer->start(2000);

    else if (level->currLevel == 4)
        spawnTimer->start(1000);

    else if (level->currLevel == 5)
        spawnTimer->start(500);
}

void Game::formTroops()
{
    int randomX;
    int randomY;

    do{
        randomX = randomGenerator->bounded(0, clanDesign[0].size()-1); //generating a random X and Y within scene dimensions
        randomY = randomGenerator->bounded(0, clanDesign.size()-1);
         qDebug()<< randomX << " " << randomY;
    } while (clanDesign[randomY][randomX] != 0); //keeps generating until position is a 0


    Troop* troop = new Troop();
    scene->addItem(troop);
    troop->setPos(randomY * 50, randomX * 50);

    if (level->currLevel == 1) //enemies move faster as level increases
        m_timer->start(30);

    else if (level->currLevel == 2)
        m_timer->start(25);

    else if (level->currLevel == 3)
        m_timer->start(20);

    else if (level->currLevel == 4)
        m_timer->start(15);

    else if (level->currLevel == 5)
        m_timer->start(10);

}

void Game::moveTroops()
{
    qDebug()<<"move troops";
    QList<QGraphicsItem*> items = scene->items();
    foreach (QGraphicsItem* item, items) {
        Troop* troop = dynamic_cast<Troop*>(item);
        if (troop && !troop->stopped) {
            Townhall* nearestTownhall = findNearestTownhall(troop->pos()); //troops move towards the castle/townhall
            if (nearestTownhall) {
                QPointF direction = nearestTownhall->pos() - troop->pos();
                direction /= QVector2D(direction).length();
                qreal dx = direction.x() * troop->speed;
                qreal dy = direction.y() * troop->speed;
                troop->setPos(troop->x() + dx, troop->y() + dy);

                checkCollisions(troop); //to destroy obstacles between troop and the castle/townhall
            }
        }
    }
}

void Game::checkCollisions(Troop* troop)
{
    QList<QGraphicsItem*> collidingItems = troop->collidingItems();
    foreach (QGraphicsItem* collidingItem, collidingItems)
    {

        if (!scene->items().contains(collidingItem))
            continue;

        //redirect troop if cannon is in their way
        if (typeid(*collidingItem) == typeid(Cannon)) {
            if (troop->x() <= collidingItem->x() + 50 )
                troop->setPos(troop->x()-10, troop->y());
            else
                troop->setPos(troop->x()+10, troop->y()-10);
        }

        else if (typeid(*collidingItem) == typeid(Townhall)) {
            Townhall *townhall = dynamic_cast<Townhall*>(collidingItem);

            qDebug()<<"townhall collision";

            qreal dx = troop->x() - collidingItem->x();
            qreal dy = troop->y() - collidingItem->y();

            if (qAbs(dx) > qAbs(dy))//move left or right
            {
                if (dx < 0) //move left
                    troop->setPos(townhall->x()-80, townhall->y());
                else //move right
                    troop->setPos(townhall->x()+80, townhall->y());
            }
            else //move up or down
            {
                if (dy < 0) //move up
                    troop->setPos(townhall->x(), townhall->y()-80);
                else //move down
                    troop->setPos(townhall->x(), townhall->y()+80);
            }

            townhall->townhallHealth->decrementHealth();
            qDebug()<< townhall->townhallHealth->getHealth();
            if (townhall->townhallHealth->getHealth() <= 0)
            {
                scene->removeItem(townhall);
                delete townhall;
                townHallDestroyed = true;

            }

        }


        else if (typeid(*collidingItem) == typeid(Fence1)) {
            Fence1 *fence = dynamic_cast<Fence1*>(collidingItem);

            qDebug()<<"fence collision";

            qreal dx = troop->x() - collidingItem->x();
            qreal dy = troop->y() - collidingItem->y();

            if (qAbs(dx) >= qAbs(dy))//move left or right
            {
                if (dx <= 0) //move left
                    troop->setPos(fence->x()-50, troop->y());
                else //move right
                    troop->setPos(fence->x()+50, troop->y());
            }
            else //move up or down
            {
                if (dy <= 0) //move up
                    troop->setPos(troop->x(), fence->y()-50);
                else //move down
                    troop->setPos(troop->x(), fence->y()+50);
            }

            fence->fenceHealth->decrementHealth();
            qDebug()<< fence->fenceHealth->getHealth();
            if (fence->fenceHealth->getHealth() <= 0)
            {
                scene->removeItem(fence);
                delete fence;

            }

        }

        if (typeid(*collidingItem) == typeid(Bullet)) {
            Bullet* bullet = dynamic_cast<Bullet*>(collidingItem);
                if (scene->items().contains(bullet)) {
                    scene->removeItem(collidingItem);

                    delete bullet;
                scene->removeItem(troop);
                    delete troop;
                     // disconnect(m_timer,SIGNAL(timeout()),this,SLOT (moveTroops()));
                    scene->removeItem(bullet);
                }
            }
        }
    }


void Game::handleStartButton()
{
    if (!gameStarted)
    {
        startButton->setEnabled(false);
        gameStarted = true;
        startGame();
    }

}


void Game::updateTimer()
{
    QTime currentTime = QTime::fromString(timerText->toPlainText(), "m:ss");

    currentTime = currentTime.addSecs(1);
    timerText->setPlainText(currentTime.toString("m:ss"));

    if (currentTime.second() == 10 )    {
        timer->stop();
        m_timer->stop();
        spawnTimer->stop();
        QMessageBox::information(this, "Player wins!", "Level " + QString::number(level->currLevel) + " completed succesfully!"); //!!HANDLE THE BUTTONS
        level->nextLevel(); //increment current level
        scene->clear(); //to remove old layout
        startLevel(); //starts next level
    }
    else if(townHallDestroyed==true){
        timer->stop();
        m_timer->stop();
        spawnTimer->stop();
        QMessageBox::information(this, "Game Over", "Game Over"); //!!HANDLE THE BUTTONS!!
        scene->clear(); //to remove old layout
        startLevel(); //restarts the level
    }

}

void Game::resetTimer()
{
    timerText->setPlainText("0:00");
}

Townhall* Game::findNearestTownhall(const QPointF& position)
{
    qreal minDistanceSquared = numeric_limits<qreal>::max();
    Townhall* nearestTownhall = nullptr;
    foreach (QGraphicsItem* item, scene->items()) {
        Townhall* townhall = dynamic_cast<Townhall*>(item);
        if (townhall) {
            qreal distanceSquared = QPointF(townhall->x() - position.x(), townhall->y() - position.y()).manhattanLength();
            if (distanceSquared < minDistanceSquared) {
                minDistanceSquared = distanceSquared;
                nearestTownhall = townhall;
            }
        }
    }
    return nearestTownhall;

}

void Game::mousePressEvent(QMouseEvent *event) //release bullet when player clicks left
{
    if (event->button() == Qt::LeftButton)
    {
        if (cannonDestroyed==true)
        {
            return;
        }

        // QPointF targetPos = event->pos();
        QPoint targetPos = QCursor::pos();
        qreal dx = targetPos.x() - cannon->pos().x();
        qreal dy = targetPos.y() - cannon->pos().y();
        qreal length = qSqrt(dx * dx + dy * dy);
        qreal directionX = dx / length;
        qreal directionY = dy / length;

        qDebug() << "Direction X:" << directionX << "Direction Y:" << directionY;

        Bullet *bullet = new Bullet(targetPos.x(), targetPos.y(), cannon->pos().x() , cannon->pos().y());
        bullet->setDirection(directionX, directionY);

        bullet->setPos(cannon->pos().x() + 50, cannon->pos().y() + 50); //bullet comes out of cannon

        scene->addItem(bullet);
    }
}


