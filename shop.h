#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QWidget>
#include "townhall.h"
#include "playermoney.h"
#include "cannon.h"
#include "fence1.h"
#include <QDialog>
#include <QStackedLayout>
class shop : public QWidget
{
public:
    shop(QWidget *parent=nullptr);

    void upgradeFence();
    void upgradeCannon();
    void upgradeTownhall();
    playerMoney* money;
    Townhall* town;
    Cannon* cannon;
    Fence1* fence;


private:
    // Game* game;
    QDialog* shopWindow;
    // enum SelectedItem {
    //     None,
    //     Townhall,
    //     Fence,
    //     Cannon
    // };
    // SelectedItem selectedItem;

signals:


};

#endif // SHOP_H
