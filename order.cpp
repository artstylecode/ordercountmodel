#include "order.h"
#include <QVariant>
#include<QDebug>
#include <QSql>
Order::Order(): BaseModel()
{
}

Order::Order(int i, int sta, int pi, const QString & pn, const QString &oc, QString &name): BaseModel(name)
{
    id = i;
    status = sta;
    pro_id = pi;
    pro_name = pn;
    order_code = oc;
}
Order::~Order()
{
}
 QString Order::getTableName()
{
    return "PRO_ORDER";
}

 void Order::bindValue()
 {

     QVariant sta(status);
     QVariant pi(pro_id);

    qDebug()<< "add bindvalue\n";
 }
 QString Order::getFieldValues()
 {
     QString sta;
     QString pi;
     sta.setNum(status);
     pi.setNum(pro_id);
     return QString("'%1', '%2', '%3', '%4'").arg(pro_name, order_code, sta,pi);
 }

 QString Order::getField()
 {
     return QString("pro_name, pro_code, pro_status, pro_id");
 }
