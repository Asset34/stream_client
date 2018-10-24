#include "vlcmanager.hpp"

#include <QString>

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Error.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtWidgets/WidgetVolumeSlider.h>

VlcManager &VlcManager::getInstance()
{
    static VlcManager instance;

    return instance;
}

void VlcManager::setVideoWidget(VlcWidgetVideo *widget)
{
    m_mediaPlayer->setVideoWidget(widget);
    widget->setMediaPlayer(m_mediaPlayer);
}

void VlcManager::setVolumeWidget(VlcWidgetVolumeSlider *widget)
{
    widget->setMediaPlayer(m_mediaPlayer);
}

void VlcManager::open(const QString &ip, int port)
{
    m_media = new VlcMedia(buildMRL(ip, port), m_instance);
    m_mediaPlayer->open(m_media);

    emit streamOpened();
}

void VlcManager::pause()
{
    m_mediaPlayer->pause();
}

void VlcManager::resume()
{
    m_mediaPlayer->resume();
}

void VlcManager::stop()
{
    m_mediaPlayer->stop();

    delete m_media;
}

QString VlcManager::buildMRL(const QString ip, int port)
{
    QString mrl;

    mrl.push_back("rtp://");
    mrl.push_back(ip);
    mrl.push_back(":");
    mrl.push_back(QString::number(port));

    return mrl;
}

VlcManager::VlcManager(QObject *parent)
    : QObject(parent),
      m_media(nullptr)
{
    QStringList args;
    args << "--no-osd"
         << "--drop-late-frames"
         << "--skip-frames"
         << "--no-loop";

    m_instance = new VlcInstance(args);
    m_mediaPlayer = new VlcMediaPlayer(m_instance);

    connect(m_mediaPlayer, &VlcMediaPlayer::error,
            [this](){
        emit errorOccured(VlcError::errmsg());
    });
}

VlcManager::~VlcManager()
{
}
