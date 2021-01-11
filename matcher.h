#ifndef MATCHER_H
#define MATCHER_H

#include "sound.h"
#include <QQueue>
#include <QPair>
class matcher
{
public:
  matcher();
  void match(QQueue<QString>);
  QList<QPair<QList<QString>, Sound*>> *pairs;
  QString eventsToString(QQueue<QString>);
  bool equal(QString, QString);
  int cur = -1;
private:

};

#endif // MATCHER_H
