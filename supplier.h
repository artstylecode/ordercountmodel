#ifndef SUPPLIER_H
#define SUPPLIER_H
#include "basemodel.h"
class Supplier : public BaseModel
{
protected:
     virtual QString getTableName();
     virtual void bindValue();
     virtual QString getFieldValues();
     virtual QString getField();
public:
    Supplier();
};

#endif // SUPPLIER_H
