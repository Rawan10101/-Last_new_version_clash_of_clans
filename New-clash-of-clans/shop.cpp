#include "shop.h"
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QMessageBox>

shop::shop(QWidget *parent)
{
    // Initialize the selected item to None
    selectedItem = None;

    QVBoxLayout* mainLayout = new QVBoxLayout(this);


    QLabel* townhallLabel = new QLabel("Townhall", this);
    QPushButton* townhallUpgradeButton = new QPushButton("Upgrade", this);


    QVBoxLayout* townhallLayout = new QVBoxLayout();
    townhallLayout->addWidget(townhallLabel);
    townhallLayout->addWidget(townhallUpgradeButton);


    mainLayout->addLayout(townhallLayout);

    QLabel* fenceLabel = new QLabel("Fence", this);
    QPushButton* fenceUpgradeButton = new QPushButton("Upgrade", this);


    QVBoxLayout* fenceLayout = new QVBoxLayout();
    fenceLayout->addWidget(fenceLabel);
    fenceLayout->addWidget(fenceUpgradeButton);


    mainLayout->addLayout(fenceLayout);

    QLabel* cannonLabel = new QLabel("Cannon", this);
    QPushButton* cannonUpgradeButton = new QPushButton("Upgrade", this);


    QVBoxLayout* cannonLayout = new QVBoxLayout();
    cannonLayout->addWidget(cannonLabel);
    cannonLayout->addWidget(cannonUpgradeButton);

    mainLayout->addLayout(cannonLayout);

    // connect(townhallUpgradeButton, &QPushButton::clicked, this, &shop::upgradeTownhall);
    // connect(fenceUpgradeButton, &QPushButton::clicked, this, &shop::upgradeFence);
    // connect(cannonUpgradeButton, &QPushButton::clicked, this, &shop::upgradeCannon);
}




void shop::upgradeTownhall()
{
    selectedItem = Townhall;

    // Deduct money and perform the upgrade
    // int newMoney = game->getCurrentMoney() - 50;
    // if (newMoney >= 0) {
    //     game->setMoney(newMoney);
    // } else {
    //     QMessageBox::critical(nullptr, "Not enough Money", "You don't have enough money for the townhall upgrade.");
    // }
}

void shop::upgradeFence()
{
    selectedItem = Fence;

    // Deduct money and perform the upgrade
    // int newMoney = game->getCurrentMoney() - 50;
    // if (newMoney >= 0) {
    //     game->setMoney(newMoney);
    //     // Perform the upgrade for the fence
    //     // ...
    // } else {
    //     QMessageBox::critical(nullptr, "Not enough Money", "You don't have enough money for the fence upgrade.");
    // }
}

void shop::upgradeCannon()
{
    selectedItem = Cannon;

    // Deduct money and perform the upgrade
    // int newMoney = game->getCurrentMoney() - 50;
    // if (newMoney >= 0) {
    //     game->setMoney(newMoney);
    //     // Perform the upgrade for the cannon
    //     // ...
    // } else {
    //     QMessageBox::critical(nullptr, "Not enough Money", "You don't have enough money for the cannon upgrade.");
    // }
}
