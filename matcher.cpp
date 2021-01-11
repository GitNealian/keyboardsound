#include "matcher.h"
#include <QtDebug>
matcher::matcher()
{
  pairs = new QList<QPair<QList<QString>, Sound*>>();
}

void matcher::match(QQueue<QString> events)
{
  QString eventString = events.join("");
  int k = -1, l = -1;
  for(int i = 0; i < pairs->size(); i++)
    {
      QList<QString> s = pairs->at(i).first;
      for (int j = 0; j < s.size(); j++)
        {
          QString desc = s.at(j);
          bool flag = true;
          for (int m = 0; m < desc.length() / 3; m++)
            {
              if(!equal(desc.mid(desc.length()-(m+1)*3, 3), eventString.mid(eventString.length()-(m+1)*3, 3)))
              {
                flag = false;
                break;
              }
            }
          if(flag)
            {
              if(k < 0 || s.at(j).length() > pairs->at(k).first.at(l).length())
                {
                  k = i;
                  l = j;
                }
            }
        }
    }
  if(k >= 0 && l >=0)
    {
      if(cur >= 0 && cur != k && pairs->at(cur).second->repeat)
        {
          pairs->at(cur).second->stop();
        }
      cur = k;
      qDebug() << pairs->at(k).second->path;
      pairs->at(k).second->play();
    }else
    {
      if(cur >= 0 && pairs->at(cur).second->repeat)
        {
          pairs->at(cur).second->stop();
          cur = -1;
        }
    }
}

bool matcher::equal(QString a, QString b)
{
  return QString::compare(a,b) == 0 ||
      (a.at(2) == b.at(2) &&
      ((a.startsWith("K") && b.startsWith("XK")) ||
      (a.startsWith("F") && b.startsWith("XF")) ||
      (a.startsWith("N") && b.startsWith("XN")) ||
      (b.startsWith("K") && a.startsWith("XK")) ||
      (b.startsWith("F") && a.startsWith("XF")) ||
      (b.startsWith("N") && a.startsWith("XN"))));
}
