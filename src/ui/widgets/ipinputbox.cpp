#include "ipinputbox.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QRegExp>
#include <QRegExpValidator>

IpInputBox::IpInputBox(QWidget *parent)
    : QWidget(parent)
{
    // Create ip line edit
    m_ipLineEdit = new QLineEdit;
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    m_ipLineEdit->setValidator(ipValidator);

    // Create separator label
    m_separatorLabel = new QLabel(":");

    // Create port spinbox
    m_portSpinBox = new QSpinBox;
    m_portSpinBox->setRange(0, 65535);

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_ipLineEdit);
    m_layout->addWidget(m_separatorLabel);
    m_layout->addWidget(m_portSpinBox);

    // Create widget
    setLayout(m_layout);
}

IpInputBox::~IpInputBox()
{
}

QString IpInputBox::getIp() const
{
    return m_ipLineEdit->text();
}

int IpInputBox::getPort() const
{
    return m_portSpinBox->value();
}
