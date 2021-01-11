#ifndef SOUND_H
#define SOUND_H

#include <QObject>
#include <QSoundEffect>

#define N 50

class Sound : public QObject
{
  Q_OBJECT
public:
  Sound(QString path, bool repeat = false);
  virtual ~Sound();
  void play();
  QString path;
  bool isPlaying();
  void stop();
  bool repeat;
private:
  QSoundEffect* seArray[N];
  int index;
  int getSize();
};
#endif // SOUND_H
