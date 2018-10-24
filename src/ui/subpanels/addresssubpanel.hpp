#ifndef ADDRESSSUBPANEL_HPP
#define ADDRESSSUBPANEL_HPP

#include <QGroupBox>

class QVBoxLayout;
class QFormLayout;
class QPushButton;
class IpInputBox;

class AddressSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit AddressSubpanel(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_mainLayout;
    QFormLayout *m_addressLayout;

    IpInputBox *m_ipInputBox;

    QPushButton *m_connectButton;

};

#endif // ADDRESSSUBPANEL_HPP
