#ifndef STREAMPANEL_HPP
#define STREAMPANEL_HPP

#include <QWidget>

class QVBoxLayout;
class VlcWidgetVideo;
class ControlSubpanel;

class StreamPanel : public QWidget
{
    Q_OBJECT

public:
    explicit StreamPanel(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;

    VlcWidgetVideo *m_videoWidget;

    ControlSubpanel *m_controlSubpanel;

};

#endif // STREAMPANEL_HPP
