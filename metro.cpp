#include "metro.h"
#include "./ui_metro.h"

Metro::Metro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Metro)
{
    ui->setupUi(this);

    database dbQuery;
    auth auth;

    QSqlQueryModel *query = dbQuery.execSelectQuery(QString("select name from user where uid = %1").arg(auth.sendUid()));
    ui->label_6->setText(query->data(query->index(0, 0)).toString());

    query = dbQuery.execSelectQuery(QString("select balance from cards where user_id = %1").arg(auth.sendUid()));
    ui->label_2->setText(query->data(query->index(0, 0)).toString());
}

Metro::~Metro()
{
    delete ui;
}

