#ifndef PRODUCT_H
#define PRODUCT_H
#include "basemodel.h"

class Product :public BaseModel
{
private:
    int id;
    QString pro_name;
    int sup_id;
protected:
     virtual QString getTableName();
     virtual void bindValue();
     virtual QString getFieldValues();
     virtual QString getField();
public:
    Product();
};

#endif // PRODUCT_H
