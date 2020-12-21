#ifndef KEYDETECTTHREAD_H
#define KEYDETECTTHREAD_H

#include <QSoundEffect>
#include <QThread>

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
  KeyDetectThread();
private:
   const std::string input_file_header = "/dev/input/event";
  QSoundEffect *normalType;
  QSoundEffect *repeat;

protected:
    void run();
};

#endif // KEYDETECTTHREAD_H
