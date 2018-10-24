#ifndef CONNECTPANEL_HPP
#define CONNECTPANEL_HPP

#include <QWidget>

class QVBoxLayout;
class AddressSubpanel;

class ConnectPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectPanel(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;

    AddressSubpanel *m_addressSubpanel;

};

#endif // CONNECTPANEL_HPP
