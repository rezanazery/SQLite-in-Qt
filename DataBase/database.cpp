#include "database.h"
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
	myName = "blank";
	myFamily = "";

//	qDebug() << query.exec("CREATE TABLE IF NOT EXISTS Testing2(Id INTEGER);");
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
	qDebug() << "getName called" << i;

	const QString path = "myDB";
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //not dbConnection
	db.setDatabaseName(path);
	db.open();
	QSqlQuery query;

	qDebug() << query.exec("select * from person;");

	query.last();	// point to last resualt
	const int row = query.at() + 1;		// save position of last row
	qDebug() << "row numbers is: " << row;

	query.first();	// point to first resualt
	query.previous();	// point to start

	while (query.next()) {
		qDebug() << query.value(0).toString();
		qDebug() << query.value(1).toString();
		qDebug() << query.value(2).toString();
		qDebug() << "";
	}
}

void DataBase::getFamily(const int i)
{
	qDebug() << "getFamily called" << i;
}

