#include "controlsubpanel.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <VLCQtWidgets/WidgetVolumeSlider.h>

#include <vlcmanager.hpp>

ControlSubpanel::ControlSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    // Create pause button
    m_pauseButton = new QPushButton("Pause");
    m_pauseButton->setCheckable(true);
    m_pauseButton->setChecked(false);
    m_pauseButton->setEnabled(false);

    // Create stop button
    m_stopButton = new QPushButton("Stop");
    m_stopButton->setEnabled(false);

    // Create volume label
    m_volumeLabel = new QLabel("Volume:");

    // Create volume slider
    m_volumeSlider = new VlcWidgetVolumeSlider(Qt::Horizontal);
    m_volumeSlider->setMinimumWidth(100);
    m_volumeSlider->setVolume(50);
    manager.setVolumeWidget(m_volumeSlider);

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_pauseButton);
    m_layout->addWidget(m_stopButton);
    m_layout->addStretch(1);
    m_layout->addWidget(m_volumeLabel);
    m_layout->addWidget(m_volumeSlider);
    m_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    // Create widget
    setTitle("Control");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);

    // Create connections
    connect(m_pauseButton, &QPushButton::clicked,
            [this, &manager](bool checked){
        if (checked) {
            manager.pause();

            m_pauseButton->setText("Resume");
        }
        else {
            manager.resume();

            m_pauseButton->setText("Pause");
        }
    });
    connect(m_stopButton, &QPushButton::clicked,
            [this, &manager](){
            manager.stop();
    });
    connect(&manager, &VlcManager::mediaOpened,
            [this, &manager](){
        m_pauseButton->setEnabled(true);
        m_stopButton->setEnabled(true);
    });
    connect(&manager, &VlcManager::mediaClosed,
            [this, &manager](){
        m_pauseButton->setEnabled(false);
        m_stopButton->setEnabled(false);
    });
}
