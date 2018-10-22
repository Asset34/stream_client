#include "streamclientmanager.hpp"

#include <QString>

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Error.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtWidgets/WidgetVolumeSlider.h>

StreamClientManager &StreamClientManager::getInstance()
{
    static StreamClientManager instance;

    return instance;
}

void StreamClientManager::setVideoWidget(VlcWidgetVideo *widget)
{
    m_mediaPlayer->setVideoWidget(widget);
    widget->setMediaPlayer(m_mediaPlayer);
}

void StreamClientManager::setVolumeWidget(VlcWidgetVolumeSlider *widget)
{
    widget->setMediaPlayer(m_mediaPlayer);
}

void StreamClientManager::open(const QString &ip, int port)
{
    m_media = new VlcMedia(buildMRL(ip, port), m_instance);
    m_mediaPlayer->open(m_media);
}

void StreamClientManager::pause()
{
    m_mediaPlayer->pause();
}

void StreamClientManager::resume()
{
    m_mediaPlayer->resume();
}

void StreamClientManager::stop()
{
    m_mediaPlayer->stop();

    delete m_media;
}

QString StreamClientManager::buildMRL(const QString ip, int port)
{
    QString mrl;

    mrl.push_back("rtp://");
    mrl.push_back(ip);
    mrl.push_back(":");
    mrl.push_back(QString::number(port));

    return mrl;
}

StreamClientManager::StreamClientManager(QObject *parent)
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

StreamClientManager::~StreamClientManager()
{
}
