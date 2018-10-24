#include "channelssubpanel.hpp"

#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>

#include <vlcmanager.hpp>

ChannelsSubpanel::ChannelsSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    // Create channels list
    m_channelsList = new QListWidget;

    // Create connect button
    m_connectButton = new QPushButton("Connect");

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_channelsList);
    m_layout->addWidget(m_connectButton);

    // Create widget
    setTitle("Channels");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);

    // Create connections
    connect(&manager, &VlcManager::mediaDiscovered,
            [this](QString name){
        m_channelsList->addItem(name);
    });
    connect(&manager, &VlcManager::mediaLost,
            [this](int index){
        QListWidgetItem *item = m_channelsList->takeItem(index);

        delete item;
    });
    connect(m_connectButton, &QPushButton::clicked,
            [this, &manager](){
        int index = m_channelsList->currentRow();
        if (index < 0 || index >= m_channelsList->count()) {
            return;
        }

        manager.openDiscovered(index);
    });
}
