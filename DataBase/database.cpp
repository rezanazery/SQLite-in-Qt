#include "database.h"
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
	myName = "name field is blank";
	myFamily = "family field is blank";

	const QString path = "myDB";
	db = QSqlDatabase::addDatabase("QSQLITE");  //not dbConnection
	db.setDatabaseName(path);
	db.open();

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

void DataBase::initData()
{
	if (db.open()) {
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
}

QString DataBase::getName(const int i)
{
	if (db.open()) {
		QSqlQuery query;
		query.exec(QString("select name from person where id=%1").arg(i));
		query.next();

		return query.value(0).toString();
	}

	return "ERROR";
}

QVariant DataBase::getNames()
{
	QStringList list;
	if (db.open()) {
		QSqlQuery query;
		query.exec("select name from person;");

		while (query.next()) {
			list.append(query.value(0).toString());
		}
	}

	return QVariant::fromValue(list);
}

QString DataBase::getFamily(const int i)
{
	if (db.open()) {
		QSqlQuery query;
		query.exec(QString("select family from person where id=%1").arg(i));
		query.next();

		return query.value(0).toString();
	}

	return "ERROR";
}

QVariant DataBase::getFamilys()
{
	QStringList list;
	if (db.open()) {
		QSqlQuery query;
		query.exec("select name from person;");

		while (query.next()) {
			list.append(query.value(0).toString());
		}
	}

	return QVariant::fromValue(list);
}
