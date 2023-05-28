#ifndef METRO_H
#define METRO_H

#include <QMainWindow>
#include "auth.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Metro; }
QT_END_NAMESPACE

class Metro : public QMainWindow
{
    Q_OBJECT

public:
    Metro(QWidget *parent = nullptr);
    ~Metro();

private:
    Ui::Metro *ui;
};
#endif // METRO_H
