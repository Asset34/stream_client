#include "mainwindow.hpp"

#include <QDockWidget>
#include <QMessageBox>

#include <ui/panels/streampanel.hpp>
#include <ui/panels/connectpanel.hpp>

#include <vlcmanager.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    QDockWidget *dock;

    // Create stream panel
    m_streamPanel = new StreamPanel;
    m_streamPanel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    dock = new QDockWidget("Stream", this);
    dock->setContentsMargins(0, 0, 0, 0);
    dock->setWidget(m_streamPanel);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    // Create connect panel
    m_connectPanel = new ConnectPanel;
    m_connectPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    dock = new QDockWidget("Connection", this);
    dock->setContentsMargins(0, 0, 0, 0);
    dock->setWidget(m_connectPanel);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    // Create window
    setWindowTitle("Stream client");
    resize(900, 500);

    // Create connections
    connect(&manager, &VlcManager::errorOccured,
            [this](QString error){
        QMessageBox errorBox(this);

        errorBox.setWindowTitle("Error");
        errorBox.setText(error);
        errorBox.exec();
    });
}
