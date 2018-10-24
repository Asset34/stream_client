#ifndef VLCMANAGER_HPP
#define VLCMANAGER_HPP

#include <QObject>
#include <QString>

class VlcInstance;
class VlcMedia;
class VlcMediaList;
class VlcMediaPlayer;
class VlcMediaDiscoverer;
class VlcMetaManager;
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

    void openDirect(const QString &ip, int port);
    void openDiscovered(int index);

    void pause();
    void resume();
    void stop();

private:
    explicit VlcManager(QObject *parent = nullptr);
    virtual ~VlcManager();

    void createMedia(const QString &ip, int port);
    void clearMedia();
    void resetMedia(const QString &ip, int port);

    QString buildMRL(const QString ip, int port);

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;
    VlcMediaDiscoverer *m_mediaDiscoverer;

    VlcMediaList *m_discoveredMediaList;

signals:
    void mediaOpened();
    void mediaDiscovered(QString name);
    void mediaLost(int index);
    void errorOccured(QString error);

};

#endif // VLCMANAGER_HPP
