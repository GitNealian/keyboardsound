#ifndef CONFIG_H
#define CONFIG_H
#include "matcher.h"

#include <QDebug>
#include <QFile>
#include <QJsonObject>
class config
{
public:
  config();
  matcher* m;
  void initMatcher();
  QString device;
  QJsonObject root;
  QString path;
private:
  QList<QString> expendOptional(QString);
  QString expendClick(QString);
};

#endif // CONFIG_H
