#ifndef CONTROLSUBPANEL_HPP
#define CONTROLSUBPANEL_HPP

#include <QGroupBox>

class QHBoxLayout;
class QPushButton;
class VlcWidgetVolumeSlider;

class ControlSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    ControlSubpanel(QWidget *parent = nullptr);
    virtual ~ControlSubpanel();

private:
    QHBoxLayout *m_layout;

    QPushButton *m_pauseButton;
    QPushButton *m_stopButton;

    VlcWidgetVolumeSlider *m_volumeSlider;

};

#endif // CONTROLSUBPANEL_HPP
