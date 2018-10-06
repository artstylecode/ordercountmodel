#ifndef ORDERSUMMARY_H
#define ORDERSUMMARY_H
#include "basemodel.h"
class OrderSummary :public BaseModel
{
protected:
     virtual QString getTableName();
     virtual void bindValue();
     virtual QString getFieldValues();
     virtual QString getField();
public:
    OrderSummary();
};

#endif // ORDERSUMMARY_H
