#include "database.h"
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
	myName = "";
	myFamily = "";

	QString path = "database.sqlite";
	db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
	db.setDatabaseName(path);
	db.open();

	QSqlQuery query;
	qDebug() << query.exec("CREATE TABLE IF NOT EXISTS Testing2(Id INTEGER);");
	/*query.exec("create table person "
			  "(id integer primary key, "
			  "firstname varchar(20), "
			  "lastname varchar(30), "
			  "age integer)");*/
}

QString DataBase::name()
{
	return this->myName;
}

QString DataBase::family()
{
	return this->myFamily;
}

void DataBase::setName(const QString &name)
{
	this->myName = name;
	emit nameChanged();
}

void DataBase::setFamily(const QString &family)
{
	this->myFamily = family;
	emit familyChanged();
}

void DataBase::getName(const int i)
{

}

void DataBase::getFamily(const int i)
{

}

