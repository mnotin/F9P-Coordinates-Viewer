#include <QApplication>

#include "../headers/MyWindow.h"
#include "gps_driver/drotek_f9p_rover.cpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWindow window;
    window.show();

    return app.exec();
}
