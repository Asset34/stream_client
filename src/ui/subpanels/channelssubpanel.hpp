#ifndef CHANNELSSUBPANEL_HPP
#define CHANNELSSUBPANEL_HPP

#include <QGroupBox>

class QVBoxLayout;
class QListWidget;
class QPushButton;

class ChannelsSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit ChannelsSubpanel(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;

    QListWidget *m_channelsList;

    QPushButton *m_connectButton;

};

#endif // CHANNELSSUBPANEL_HPP
