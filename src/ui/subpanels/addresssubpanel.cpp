#include "addresssubpanel.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>

#include <ui/widgets/ipinputbox.hpp>

#include <vlcmanager.hpp>

AddressSubpanel::AddressSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    // Create ip input box
    m_ipInputBox = new IpInputBox;

    // Create address layout
    m_addressLayout = new QFormLayout;
    m_addressLayout->setContentsMargins(0, 0, 0, 0);
    m_addressLayout->addRow("Address:", m_ipInputBox);

    // Create connect button
    m_connectButton = new QPushButton("Connect");

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_addressLayout);
    m_mainLayout->addWidget(m_connectButton);

    // Create widget
    setTitle("Address");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_mainLayout);

    // Create connections
    connect(m_connectButton, &QPushButton::clicked,
            [this, &manager](){
        manager.openDirect(
            m_ipInputBox->getIp(),
            m_ipInputBox->getPort()
        );
    });
}
