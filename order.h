#ifndef ORDER_H
#define ORDER_H
#include "basemodel.h"

class Order : public BaseModel
{
 private:
    int id;
    int status;
    int pro_id;
    QString pro_name;
    QString order_code;
protected:
     virtual QString getTableName();
     virtual void bindValue();
     virtual QString getFieldValues();
     virtual QString getField();
public:
    Order();
    Order(int i, int sta, int pi,const QString & qn, const QString &pc,  QString &name);
    ~Order();

};

#endif // ORDER_H
