#include "levels.h"

Levels::Levels(QWidget* parent) : QWidget(parent){}

void Levels::nextLevel()
{
    currLevel++;
}


QVector<QVector<int>> Levels::getDesignVector()
{
    switch (currLevel)
    {
    case(1): filename.setFileName(":/textfiles/Text files/File.txt");
        break;
    case(2):filename.setFileName(":/textfiles/Text files/File2.txt");
        break;
    case(3): filename.setFileName(":/textfiles/Text files/File3.txt");
        break;
    case(4): filename.setFileName(":/textfiles/Text files/File4.txt");
        break;
    case(5): filename.setFileName(":/textfiles/Text files/File5.txt");
        break;
    }

    createLevel();
    return designVector;
}

void Levels::createLevel()
{
    designVector.clear();

    if (!filename.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Failed to open file");
        return;
    }

    QTextStream in(&filename);

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

    filename.close();

}

// void Levels::createLevel1()
// {
//     designVector.clear();

//     if (!file1.open(QFile::ReadOnly | QFile::Text))
//     {
//         QMessageBox::information(this, "Error", "Failed to open file: File1.txt");
//         return;
//     }

//     QTextStream in(&file1);

//     while (!in.atEnd())
//     {
//         QString line = in.readLine();
//         QStringList values = line.split(',');

//         QVector<int> row;
//         for (const QString& value : values)
//         {
//             bool ok;
//             int element = value.toInt(&ok);
//             if (ok)
//                 row.append(element);
//             else
//                 row.append(0);
//         }
//         designVector.append(row);
//     }

//     file1.close();
// }


// void Levels::createLevel2()
// {
//     designVector.clear();

//     if (!file2.open(QFile::ReadOnly | QFile::Text))
//     {
//         QMessageBox::information(this, "Error", "Failed to open file: File2.txt");
//         return;
//     }

//     QTextStream in(&file2);

//     while (!in.atEnd())
//     {
//         QString line = in.readLine();
//         QStringList values = line.split(',');

//         QVector<int> row;
//         for (const QString& value : values)
//         {
//             bool ok;
//             int element = value.toInt(&ok);
//             if (ok)
//                 row.append(element);
//             else
//                 row.append(0);
//         }
//         designVector.append(row);
//     }

//     file2.close();
// }

// void Levels::createLevel3()
// {
//     designVector.clear();

//     if (!file3.open(QFile::ReadOnly | QFile::Text))
//     {
//         QMessageBox::information(this, "Error", "Failed to open file: File3.txt");
//         return;
//     }

//     QTextStream in(&file3);

//     while (!in.atEnd())
//     {
//         QString line = in.readLine();
//         QStringList values = line.split(',');

//         QVector<int> row;
//         for (const QString& value : values)
//         {
//             bool ok;
//             int element = value.toInt(&ok);
//             if (ok)
//                 row.append(element);
//             else
//                 row.append(0);
//         }
//         designVector.append(row);
//     }

//     file3.close();
// }
// void Levels::createLevel4()
// {
//     designVector.clear();

//     if (!file4.open(QFile::ReadOnly | QFile::Text))
//     {
//         QMessageBox::information(this, "Error", "Failed to open file: File4.txt");
//         return;
//     }

//     QTextStream in(&file4);

//     while (!in.atEnd())
//     {
//         QString line = in.readLine();
//         QStringList values = line.split(',');

//         QVector<int> row;
//         for (const QString& value : values)
//         {
//             bool ok;
//             int element = value.toInt(&ok);
//             if (ok)
//                 row.append(element);
//             else
//                 row.append(0);
//         }
//         designVector.append(row);
//     }

//     file4.close();
// }
// void Levels::createLevel5()
// {
//     designVector.clear();

//     if (!file5.open(QFile::ReadOnly | QFile::Text))
//     {
//         QMessageBox::information(this, "Error", "Failed to open file: File5.txt");
//         return;
//     }

//     QTextStream in(&file5);

//     while (!in.atEnd())
//     {
//         QString line = in.readLine();
//         QStringList values = line.split(',');

//         QVector<int> row;
//         for (const QString& value : values)
//         {
//             bool ok;
//             int element = value.toInt(&ok);
//             if (ok)
//                 row.append(element);
//             else
//                 row.append(0);
//         }
//         designVector.append(row);
//     }

//     file5.close();
// }



