#include "database.h"
#include <QDebug>
#include <QFile>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
	QFile file("://myDB");
	file.copy("./aaa");
	QFile::setPermissions("./aaa", QFile::WriteOwner | QFile::ReadOwner);

	const QString path = "myDB";
	db = QSqlDatabase::addDatabase("QSQLITE");  //not dbConnection
	db.setDatabaseName(path);
	db.open();

}

QVariant DataBase::searchResualt()
{
	return this->resualt;
}

void DataBase::setSearchResualt(const QVariant &r)
{
	this->resualt = r;
	emit searchResualtChanged();
}

void DataBase::initData()
{
	if (db.open()) {
		QSqlQuery q;

		qDebug() << q.exec("select * from person;");

		q.last();	// point to last resualt
		const int row = q.at() + 1;		// save position of last row
		qDebug() << "row numbers is: " << row;

		q.first();	// point to first resualt
		q.previous();	// point to start

		while (q.next()) {
			qDebug() << q.value(0).toString();
			qDebug() << q.value(1).toString();
			qDebug() << q.value(2).toString();
			qDebug() << "";
		}
	}
	else {
		qDebug() << "data base cant open in initData";
	}
}

QString DataBase::getName(const int i)
{
	if (db.open()) {
		QSqlQuery q;
		q.exec(QString("select name from person where id=%1").arg(i));
		q.next();

		return q.value(0).toString();
	}
	else {
		qDebug() << "data base cant open in getName";
		return "ERROR";
	}

}

QVariant DataBase::getNames()
{
	QStringList list;
	if (db.open()) {
		QSqlQuery q;
		q.exec("select name from person;");

		while (q.next()) {
			list.append(q.value(0).toString());
		}
	}
	else {
		qDebug() << "data base cant open in getNames";
	}

	return QVariant::fromValue(list);
}

QString DataBase::getFamily(const int i)
{
	if (db.open()) {
		QSqlQuery q;
		q.exec(QString("select family from person where id=%1").arg(i));
		q.next();

		return q.value(0).toString();
	}
	else {
		qDebug() << "data base cant open in getFamily";
		return "ERROR";
	}
}

QVariant DataBase::getFamiles()
{
	QStringList list;
	if (db.open()) {
		QSqlQuery q;
		q.exec("select family from person;");

		while (q.next()) {
			list.append(q.value(0).toString());
		}
	}
	else {
		qDebug() << "data base cant open in getFamiles";
	}

	return QVariant::fromValue(list);
}

void DataBase::search_in_name(QString name)
{
	if(db.isOpen()) {
		QStringList list;
		QSqlQuery q;
		q.exec(QString("select * from person where name=\"%1\";").arg(name));

		while (q.next()) {
			list.append(q.value(0).toString());
			list.append(q.value(1).toString());
			list.append(q.value(2).toString());
		}
		setSearchResualt(QVariant::fromValue(list));
	}
	else {
		qDebug() << "data base cant open in search_in_name slot";
	}
}
