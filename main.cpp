
#include "config.h"
#include "keydetectthread.h"
#include <QApplication>
#include <QSoundEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    config *v = new config();
    KeyDetectThread t(v);
    t.start();
    return a.exec();
}
