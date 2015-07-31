#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>

class DataBase : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString family READ family WRITE setFamily NOTIFY familyChanged)

public:
	explicit DataBase(QObject *parent = 0);

	QString name();
	QString family();

	void setName(const QString &name);
	void setFamily(const QString &family);

private:
	QSqlDatabase db;

	QString myName;
	QString myFamily;
	QList<QString> list_name;
	QList<QString> list_family;

signals:
	void nameChanged();
	void familyChanged();

public slots:
	void getName(const int i);
	void getFamily(const int i);
};

#endif // DATABASE_H
