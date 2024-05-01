#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QWidget>
#include "townhall.h"
#include <QDialog>
class shop : public QWidget
{
public:
    shop(QWidget *parent=nullptr);

    void upgradeFence();
    void upgradeCannon();
    void upgradeTownhall();


private:
    // Game* game;
    QDialog* shopWindow;
    enum SelectedItem {
        None,
        Townhall,
        Fence,
        Cannon
    };
    SelectedItem selectedItem;

signals:


};

#endif // SHOP_H
