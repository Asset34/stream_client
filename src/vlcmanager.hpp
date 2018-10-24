#ifndef VLCMANAGER_HPP
#define VLCMANAGER_HPP

#include <QObject>
#include <QString>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class VlcWidgetVideo;
class VlcWidgetVolumeSlider;

class VlcManager : public QObject
{
    Q_OBJECT

public:
    VlcManager(const VlcManager &other) = delete;
    VlcManager &operator=(const VlcManager &other) = delete;

    static VlcManager &getInstance();

    void setVideoWidget(VlcWidgetVideo *widget);
    void setVolumeWidget(VlcWidgetVolumeSlider *widget);

    void open(const QString &ip, int port);

    void pause();
    void resume();
    void stop();

private:
    explicit VlcManager(QObject *parent = nullptr);
    virtual ~VlcManager();

    QString buildMRL(const QString ip, int port);

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;

signals:
    void streamOpened();
    void errorOccured(QString error);

};

#endif // VLCMANAGER_HPP
