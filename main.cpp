﻿//#define LOBBY
#include <QMetaType>
#include <QtGui>
#include <QApplication>
#include "widget/Animation.h"
#include "widget/RoomView.h"
#include "data/DataInterface.h"
#include "widget/GUI.h"
#include "client/ClientUI.h"
#include "client/Lobby.h"
#include "logic/Logic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("simsun", 9));
    QDir dir(QCoreApplication::applicationDirPath());
    if (dir.dirName() == "MacOS")
    {
        dir.cdUp();
        dir.cdUp();
        dir.cdUp();
        QDir::setCurrent(dir.absolutePath());
    }
    dataInterface = new DataInterface;
    logic = new Logic;
    animation = new Animation;
    gui = new GUI;
    //FIXME: use ClientUI login and then destroy it
    ClientUI c;
#ifdef LOBBY
    c.disconnect(&c);
    Lobby l;
    l.show();
    return a.exec();
#else
    if(c.exec() == QDialog::Accepted)
    {
        c.disconnect(&c);
        Lobby l;
        l.show();
        return a.exec();
    }
    return 0;
#endif
}
