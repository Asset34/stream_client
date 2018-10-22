#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class StreamPanel;
class ConnectPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    StreamPanel *m_streamPanel;
    ConnectPanel *m_connectPanel;

};

#endif // MAINWINDOW_HPP
