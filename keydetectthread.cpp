#include "keydetectthread.h"
#include "desc.h"
#include <QDebug>

KeyDetectThread::KeyDetectThread(config* c)
{
  this->c = c;
}

void KeyDetectThread::run()
{
  input_event ie;
  int fd;
  fd_set fds;
  fd = open(c->device.toStdString().c_str(), O_RDONLY);

  if (fd == -1) {
      return;
    }

  while(true) {
      FD_ZERO(&fds);
      FD_SET(fd, &fds);

      int ret = select(fd+1, &fds, NULL, NULL, NULL);

      if (!(ret > 0 && FD_ISSET(fd, &fds))) {continue;}

      ssize_t num = read(fd, (void *)&ie, sizeof(struct input_event));

      if (num == sizeof(struct input_event) && ie.type == EV_KEY) {
          if (KEY_DESC.contains(ie.code))
            {
              QString desc = KEY_DESC[ie.code];
              switch (ie.value)
                {
                case KEY_PRESS:
                  {
                    desc = desc + "D";
                    break;
                  }
                case KEY_RELEASE:
                  {
                    desc = desc + "U";
                    break;
                  }
                case KEY_REPEAT:
                  {
                    desc = desc + "R";
                    break;
                  }
                default: break;
                }
              if (!desc.endsWith("R") || events.last()!=desc){
                  events.enqueue(desc);
                }
              c->m->match(events);
            }
        }
    }

  if (fd>0) close(fd);
}

