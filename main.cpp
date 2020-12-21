#include "mainwindow.h"
#include "napplication.h"
#include "keydetect.h"
#include "keydetectthread.h"
#include <QApplication>
#include <QSoundEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyDetectThread t;
    t.start();
    return a.exec();
}
