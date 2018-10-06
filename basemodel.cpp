#include "basemodel.h"
#include<QDebug>
#include <QSqlError>
BaseModel::BaseModel()
{
}
BaseModel::BaseModel(const char * name)
{
    qDebug()<<"db name:"<< name;
    dbname = name;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(dbname);
    if(database.open())
    {
        qDebug()<< "database opened!\n";
        sql_query = QSqlQuery();
    }else
    {
        qDebug() << "database open failed!error message:"<< database.lastError();
    }

}
BaseModel::BaseModel(const QString  &name)
{
     qDebug()<<"db name:"<< name;
    dbname = name;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(dbname);

    if(database.open())
    {
        qDebug()<< "database opened!\n";
        sql_query = QSqlQuery();

    }else
    {
        qDebug() << "database open failed!error message:"<< database.lastError();
    }

}
BaseModel::~BaseModel()
{
    //database.close();
}
bool BaseModel::add()
{

    QString sql = QString("insert into %1 (%2) Values(%3);").arg(getTableName(), getField(), getFieldValues());
    //qDebug() << "sql:" <<sql;
    sql_query.prepare(sql);
    bindValue();
    bool result;
    if(result = sql_query.exec())
    {
        qDebug() << "exec successfully!\n";
    }else
    {
        qDebug() << "execute sql failed!\n error message:"<< sql_query.lastError();
    }
    return result;
}
void BaseModel::fetch()
{
    int i = sql_query.value(0).toInt();
    QString pn = sql_query.value(1).toString();
    QString oc = sql_query.value(2).toString();
    int sta = sql_query.value(3).toInt();
    int pi = sql_query.value(4).toInt();
    qDebug() << "current info is : \nid :"<< i<< "\n pro_name:" <<pn << "\norder_code :"<<oc\
             << "\nstatus:"<< sta<< "\npro_id:"<<pi;
}
void BaseModel::getAll()
{
    QString sql = "select * from " + getTableName();
    sql_query.prepare(sql);
    if(sql_query.exec())
    {
        qDebug()<< "query successfully!\n";
        //qDebug()<<"current record size:"<< sql_query.size();
        while(sql_query.next())
        {
           fetch();
        }
    }
}
QString BaseModel::getField()
{
    return "defualt fields.\n";
}
QString BaseModel::getFieldValues()
{
    return "defualt fieldvalue.\n";
}
bool BaseModel::update()
{
    QString sql = "update " + getTableName() + "set ";
    return false;
}
bool BaseModel::remove()
{
    QString sql = "delete " + getTableName() + "where ";
    return false;
}
QString BaseModel::getTableName()
{
    return "no tables\n";
}
void BaseModel::bindValue()
{
    //qDebug()<< "defualt bindvalue!\n";
}
