#ifndef STREAMCLIENTMANAGER_HPP
#define STREAMCLIENTMANAGER_HPP

#include <QObject>
#include <QString>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class VlcWidgetVideo;
class VlcWidgetVolumeSlider;

class StreamClientManager : public QObject
{
    Q_OBJECT

public:
    StreamClientManager(const StreamClientManager &other) = delete;
    StreamClientManager &operator=(const StreamClientManager &other) = delete;

    static StreamClientManager &getInstance();

    void setVideoWidget(VlcWidgetVideo *widget);
    void setVolumeWidget(VlcWidgetVolumeSlider *widget);

    void open(const QString &ip, int port);

    void pause();
    void resume();
    void stop();

private:
    QString buildMRL(const QString ip, int port);

    explicit StreamClientManager(QObject *parent = nullptr);
    virtual ~StreamClientManager();

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;

signals:
    void errorOccured(QString error);

};

#endif // STREAMCLIENTMANAGER_HPP
