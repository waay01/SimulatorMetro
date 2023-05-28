#include "database.h"

void database::execQuery(const QString& strQuery) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("metro.db");

    if (db.open()) {
        QSqlQuery query(db);
        query.exec(strQuery);
        db.close();
    }
}

QSqlQueryModel* database::execSelectQuery(const QString& strQuery) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("metro.db");
    QSqlQueryModel* model = new QSqlQueryModel();

    if (db.open()) {
        QSqlQuery query(db);
        query.exec(strQuery);
        model->setQuery(std::move(query));
        db.close();
    }
    return model;
}

QStringList database::execQueryPRAGMA(const QString& strTable) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("metro.db");
    QStringList nameColumn;

    if (!db.open())
        return nameColumn;

    QSqlQuery query(db);
    query.exec(QString("PRAGMA table_info(%1)").arg(strTable));
    while(query.next())
        nameColumn += query.value(1).toStringList();

    return nameColumn;
}
