#include "connectpanel.hpp"

#include <QVBoxLayout>
#include <QPushButton>

#include <ui/subpanels/addresssubpanel.hpp>
#include <ui/subpanels/channelssubpanel.hpp>

ConnectPanel::ConnectPanel(QWidget *parent)
    : QWidget(parent)
{
    // Create address subpanel
    m_addressSubpanel = new AddressSubpanel;
    m_addressSubpanel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    // Create channels subpanel
    m_channelsSubpanel = new ChannelsSubpanel;

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_addressSubpanel);
    m_layout->addWidget(m_channelsSubpanel);

    // Create widget
    setLayout(m_layout);
    setContentsMargins(5, 5, 5, 5);
}
