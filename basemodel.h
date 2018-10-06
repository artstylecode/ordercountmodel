#ifndef BASEMODEL_H
#define BASEMODEL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class BaseModel
{

private:
    QString dbname;
    QSqlDatabase database;
    const QString CONNECTION_NAME="ORDER_CONNECTIONS";
protected:
     QSqlQuery sql_query;
     virtual QString getTableName();
     virtual void bindValue();
     virtual QString getField();
     virtual QString getFieldValues();
     virtual void fetch();
public:
     BaseModel();
    BaseModel(const QString & name);
    BaseModel(const char * name);
    ~BaseModel();
    virtual bool add();
    void getAll();
    virtual bool update();
    virtual bool remove();

};

#endif // BASEMODEL_H
