#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>

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
//	QStringList list_name;
//	QStringList list_family;

signals:
	void nameChanged();
	void familyChanged();

public slots:
	void initData();
	QString getName(const int i);
	QVariant getNames();
	QString getFamily(const int i);
	QVariant getFamilys();
};

#endif // DATABASE_H
