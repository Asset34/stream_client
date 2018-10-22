#include <QApplication>

#include <ui/subpanels/addresssubpanel.hpp>
#include <ui/panels/streampanel.hpp>
#include <ui/panels/connectpanel.hpp>

#include <ui/windows/mainwindow.hpp>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
