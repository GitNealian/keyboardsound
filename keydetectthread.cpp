#include "keydetectthread.h"
#include "keydetect.h"

KeyDetectThread::KeyDetectThread()
{
  normalType = new QSoundEffect(NULL);
  normalType->setSource(QUrl::fromLocalFile("/home/nealian/Workspace/keyboardsound/msounds/normal_type.wav"));
  repeat =new QSoundEffect(NULL);
  repeat->setSource(QUrl::fromLocalFile("/home/nealian/Workspace/keyboardsound/msounds/continue.wav"));
  repeat->setLoopCount(QSoundEffect::Infinite);
}

void KeyDetectThread::run()
{
  input_event ie;

  int fd;
  fd_set fds;
  fd = open((input_file_header + "3").c_str(), O_RDONLY);

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
          switch (ie.value) {
            case KEY_PRESS:
              {
                this->normalType->play();
                break;
              }
            case KEY_RELEASE:
              {
                if(repeat->isPlaying()){
                    repeat->stop();
                  }
                break;
              }
            case KEY_REPEAT:
              {
                if(!repeat->isPlaying()){
                    repeat->play();
                  }
                break;
              }
            default: break;
            }
        }
    }

  if (fd>0) close(fd);
}


