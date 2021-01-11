#include "config.h"

#include <QJsonDocument>
#include <QJsonArray>

config::config()
{
  QFile file("config.json");
  if(!file.open(QIODevice::ReadOnly))
    {
      qDebug() << "read json file failed";
      return ;
    }
  QByteArray ba = file.readAll();
  QJsonParseError e;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(ba, &e);
  if(e.error == QJsonParseError::NoError && !jsonDoc.isNull())
    {
      root = jsonDoc.object();
      device = root.take("device").toString();
      path = root.take("path").toString();
      initMatcher();
    }
}


void config::initMatcher()
{
  m = new matcher();
  QJsonArray events = root.take("events").toArray();
  for (int i = 0; i < events.size(); i++)
    {
      QJsonObject event = events.at(i).toObject();
      QString name = event.take("name").toString();
      QString audio = event.take("audio").toString();
      bool repeat = event.take("repeat").toBool();
      Sound* sound = new Sound(path + audio, repeat);
      QList<QString> descList = expendOptional(name);
      for(int j = 0; j < descList.size(); j++)
        {
          descList.replace(j, expendClick(descList.at(j)));
          qDebug() << expendClick(descList.at(j));
        }
      m->pairs->append(QPair<QList<QString>, Sound*>(descList, sound));
    }

}

QList<QString> config::expendOptional(QString before)
{
  QList<QString> list;
  QList<QString> optional;
  int i = 0;
  while (i < before.length())
    {
      QString cur;
      if(before.at(i) == "(")
        {
          cur = before.mid(i+1, 3);
          i+=5;
          int l = list.size();
          if(l == 0)
            {
              list.append("");
              list.append(cur);
              continue;
            }
          for(int j = 0; j < l; j++)
            {
              list.append(list.at(j) + cur);
            }
        }
      else
        {
          cur = before.mid(i, 3);
          i+=3;
          if(list.size() == 0)
            {
              list.append(cur);
              continue;
            }
          for(int j = 0; j < list.size(); j ++)
            {
              list.replace(j, list.at(j) + cur);
            }
        }
    }
  return list;
}

QString config::expendClick(QString before)
{
  QString after;
  int i = 0;
  while(i < before.length())
    {
      QString cur;
      cur = before.mid(i, 3);
      i +=3;
      if(cur.endsWith("C"))
        {
          after = after + cur.mid(0, 2) + "D";
          after = after + cur.mid(0, 2) + "U";
        }
      else
        {
          after = after + cur;
        }
    }
  return after;
}
