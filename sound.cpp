#include "sound.h"
#include <QDebug>

Sound::Sound(QString path, bool repeat)
{
  this->path = path;
  this->repeat = repeat;
  for(int i = 0; i < getSize(); i++)
  {
    seArray[i] = new QSoundEffect(this);
    qDebug() << path;
    seArray[i]->setSource(QUrl::fromLocalFile(path));
    if (repeat)
      {
         seArray[i]->setLoopCount(QSoundEffect::Infinite);
      }
  }
  index = 0;
}

Sound::~Sound()
{

}

void Sound::play()
{
  if(!repeat || !isPlaying())
    {
      seArray[index]->play();
    }
  if (!repeat)
  {
    index = (index + 1) % N;
  }
}

void Sound::stop() {
  for(int i = 0; i < getSize(); i++)
  {
    if(seArray[i]->isPlaying())
    {
      seArray[i]->stop();
    }
  }
  index = 0;
}

bool Sound::isPlaying() {
  for(int i = 0; i < getSize(); i++)
  {
    if(seArray[i]->isPlaying())
    {
      return true;
    }
  }
  return false;
}

int Sound::getSize() {
  return !repeat ? N : 1;
}
