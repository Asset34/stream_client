#include "connectpanel.hpp"

#include <QVBoxLayout>
#include <QPushButton>

#include <ui/subpanels/addresssubpanel.hpp>

ConnectPanel::ConnectPanel(QWidget *parent)
    : QWidget(parent)
{
    // Create address subpanel
    m_addressSubpanel = new AddressSubpanel;
    m_addressSubpanel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_addressSubpanel);

    // Create widget
    setLayout(m_layout);
    setContentsMargins(5, 5, 5, 5);
}
