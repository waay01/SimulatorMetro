#include "metro.h"
#include "auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auth auth;
    auth.exec();

    if (auth.authenticator()) {
        Metro w;
        w.show();
        return a.exec();
    }

    return 0;
}
