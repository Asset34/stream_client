#include "streampanel.hpp"

#include <QVBoxLayout>
#include <VLCQtWidgets/WidgetVideo.h>

#include <ui/subpanels/controlsubpanel.hpp>

#include <vlcmanager.hpp>

StreamPanel::StreamPanel(QWidget *parent)
    : QWidget(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    // Create video widget
    m_videoWidget = new VlcWidgetVideo;
    m_videoWidget->setFrameStyle(QFrame::Box | QFrame::Sunken);
    m_videoWidget->setLineWidth(1);
    m_videoWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    manager.setVideoWidget(m_videoWidget);

    // Create control subpanel
    m_controlSubpanel = new ControlSubpanel;
    m_controlSubpanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    m_layout->addWidget(m_videoWidget);
    m_layout->addWidget(m_controlSubpanel);

    // Create widget
    setLayout(m_layout);
    setContentsMargins(5, 5, 5, 5);
}
