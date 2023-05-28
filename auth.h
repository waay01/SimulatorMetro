#ifndef AUTH_H
#define AUTH_H

#include <QDialog>

#include "database.h"

namespace Ui {
class auth;
}

class auth : public QDialog
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = nullptr);
    ~auth();

    bool authenticator();

    QString sendUid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::auth *ui;
};

#endif // AUTH_H
