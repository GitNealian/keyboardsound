#ifndef KEYDETECTTHREAD_H
#define KEYDETECTTHREAD_H

#include "config.h"
#include "matcher.h"

#include <QSoundEffect>
#include <QThread>
#include <QMap>
#include <sound.h>
#include <QQueue>

extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/ipc.h>
}
#define KEY_RELEASE 0
#define KEY_PRESS 1
#define KEY_REPEAT 2


class KeyDetectThread : public QThread
{
public:
  KeyDetectThread(config*);
private:
  QMap <QString, Sound*> sounds;
  QQueue<QString> events;
  config* c;

protected:
  void run();
};

#endif // KEYDETECTTHREAD_H
