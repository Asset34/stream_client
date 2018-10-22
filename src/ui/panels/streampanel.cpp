#include "streampanel.hpp"

#include <QVBoxLayout>
#include <VLCQtWidgets/WidgetVideo.h>

#include <ui/subpanels/controlsubpanel.hpp>

#include <streamclientmanager.hpp>

StreamPanel::StreamPanel(QWidget *parent)
    : QWidget(parent)
{
    // Create video widget
    m_videoWidget = new VlcWidgetVideo;
    m_videoWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    StreamClientManager &streamManager = StreamClientManager::getInstance();
    streamManager.setVideoWidget(m_videoWidget);

    // Create control subpanel
    m_controlSubpanel = new ControlSubpanel;
    m_controlSubpanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_videoWidget);
    m_layout->addWidget(m_controlSubpanel);

    // Create widget
    setLayout(m_layout);
    setContentsMargins(5, 5, 5, 5);
}

StreamPanel::~StreamPanel()
{
}
