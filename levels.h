#ifndef LEVELS_H
#define LEVELS_H
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFrame>
#include <QWidget>

class Levels : public QWidget
{
    QVector<QVector<int>> designVector;

    // QFile file1;
    // QFile file2;
    // QFile file3;
    // QFile file4;
    // QFile file5;

    QFile filename;
    void createLevel();
    // void createLevel1();
    // void createLevel2();
    // void createLevel3();
    // void createLevel4();
    // void createLevel5();


public:
    Levels(QWidget *parent = nullptr);
    QVector<QVector<int>> getDesignVector();
    void nextLevel();

    int currLevel = 1;



};

#endif // LEVELS_H
