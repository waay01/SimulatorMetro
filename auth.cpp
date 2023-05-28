#include "auth.h"
#include "ui_auth.h"

bool status = false;

auth::auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
}

QString simpleHash(const QString& input) {
    int hash = 0;

    for (auto &ch : input)
        hash ^= ch.unicode();

    return QString::number(hash+110000);
}

auth::~auth()
{
    delete ui;
}

bool auth::authenticator() {
    return status;
}

QString auth::sendUid() {
    return ui->lineEdit->text();
}

void auth::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty()) {
        database dbQuery;

        QSqlQueryModel *query = dbQuery.execSelectQuery(QString("select count(*) from user where uid = %1 and password = '%2'").arg(ui->lineEdit->text(), simpleHash(ui->lineEdit_2->text())));
        if (query->data(query->index(0, 0)).toString() == "1") {
            status = true;
            close();
        }
    }
}

