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
	Q_PROPERTY(QVariant searchResualt READ searchResualt WRITE setSearchResualt NOTIFY searchResualtChanged)

public:
	explicit DataBase(QObject *parent = 0);

	QVariant searchResualt();
	void setSearchResualt(const QVariant &r);

private:
	QSqlDatabase db;
	QVariant resualt;

signals:
	void searchResualtChanged();

public slots:
	void initData();
	QString getName(const int i);
	QVariant getNames();
	QString getFamily(const int i);
	QVariant getFamiles();
	void search_in_name(QString name);
};

#endif // DATABASE_H
