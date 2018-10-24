#ifndef CONTROLSUBPANEL_HPP
#define CONTROLSUBPANEL_HPP

#include <QGroupBox>

class QHBoxLayout;
class QLabel;
class QPushButton;
class VlcWidgetVolumeSlider;

class ControlSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    ControlSubpanel(QWidget *parent = nullptr);

private:
    QHBoxLayout *m_layout;

    QPushButton *m_pauseButton;
    QPushButton *m_stopButton;

    QLabel *m_volumeLabel;

    VlcWidgetVolumeSlider *m_volumeSlider;

};

#endif // CONTROLSUBPANEL_HPP
