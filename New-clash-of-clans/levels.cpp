#include "levels.h"

Levels::Levels(QWidget* parent) : QWidget(parent)
{
    file1.setFileName(":/textfiles/Text files/File.txt"); //files for the 5 levels
    file2.setFileName(":/textfiles/Text files/File2.txt");
    file3.setFileName(":/textfiles/Text files/File3.txt");
    file4.setFileName(":/textfiles/Text files/File4.txt");
    file5.setFileName(":/textfiles/Text files/File5.txt");
}

void Levels::nextLevel()
{
    currLevel++;
}


QVector<QVector<int>> Levels::getDesignVector()
{
    switch (currLevel)
    {
    case(1): createLevel1();
        break;
    case(2): createLevel2();
        break;
    case(3): createLevel3();
        break;
    case(4): createLevel4();
        break;
    case(5): createLevel5();
        break;
    }

    return designVector;
}


void Levels::createLevel1()
{
    designVector.clear();

    if (!file1.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Failed to open file: File1.txt");
        return;
    }

    QTextStream in(&file1);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QVector<int> row;
        for (const QString& value : values)
        {
            bool ok;
            int element = value.toInt(&ok);
            if (ok)
                row.append(element);
            else
                row.append(0);
        }
        designVector.append(row);
    }

    file1.close();
}


void Levels::createLevel2()
{
    designVector.clear();

    if (!file2.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Failed to open file: File2.txt");
        return;
    }

    QTextStream in(&file2);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QVector<int> row;
        for (const QString& value : values)
        {
            bool ok;
            int element = value.toInt(&ok);
            if (ok)
                row.append(element);
            else
                row.append(0);
        }
        designVector.append(row);
    }

    file2.close();
}

void Levels::createLevel3()
{
    designVector.clear();

    if (!file3.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Failed to open file: File3.txt");
        return;
    }

    QTextStream in(&file3);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QVector<int> row;
        for (const QString& value : values)
        {
            bool ok;
            int element = value.toInt(&ok);
            if (ok)
                row.append(element);
            else
                row.append(0);
        }
        designVector.append(row);
    }

    file3.close();
}
void Levels::createLevel4()
{
    designVector.clear();

    if (!file4.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Failed to open file: File4.txt");
        return;
    }

    QTextStream in(&file4);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QVector<int> row;
        for (const QString& value : values)
        {
            bool ok;
            int element = value.toInt(&ok);
            if (ok)
                row.append(element);
            else
                row.append(0);
        }
        designVector.append(row);
    }

    file4.close();
}
void Levels::createLevel5()
{
    designVector.clear();

    if (!file5.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Failed to open file: File5.txt");
        return;
    }

    QTextStream in(&file5);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QVector<int> row;
        for (const QString& value : values)
        {
            bool ok;
            int element = value.toInt(&ok);
            if (ok)
                row.append(element);
            else
                row.append(0);
        }
        designVector.append(row);
    }

    file5.close();
}



