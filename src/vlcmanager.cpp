#include "vlcmanager.hpp"

#include <QString>

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaList.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/MediaDiscoverer.h>
#include <VLCQtCore/MetaManager.h>
#include <VLCQtCore/Error.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtWidgets/WidgetVolumeSlider.h>

#include <QDebug>

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

void VlcManager::openDirect(const QString &ip, int port)
{
    resetMedia(ip, port);
    m_mediaPlayer->open(m_media);

    emit mediaOpened();
}

void VlcManager::openDiscovered(int index)
{
    if (index < 0 ||
        index > m_discoveredMediaList->count()) {
        return;
    }

    clearMedia();
    m_mediaPlayer->open(m_discoveredMediaList->at(index));

    emit mediaOpened();
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

    emit mediaClosed();
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
    m_mediaDiscoverer = new VlcMediaDiscoverer("sap", m_instance);
    m_discoveredMediaList = m_mediaDiscoverer->getList();

    connect(m_mediaPlayer, &VlcMediaPlayer::error,
            [this](){
        emit errorOccured(VlcError::errmsg());
    });

    connect(m_mediaDiscoverer, &VlcMediaDiscoverer::mediaDiscovered, this,
            [this](VlcMedia *media, int index){
        VlcMetaManager metaManager(media);
        emit mediaDiscovered(metaManager.title());
    });
    connect(m_mediaDiscoverer, &VlcMediaDiscoverer::mediaLost, this,
            [this](VlcMedia *media, int index){
        emit mediaLost(index);
    });
}

VlcManager::~VlcManager()
{
    delete m_discoveredMediaList;
    delete m_mediaDiscoverer;
    delete m_mediaPlayer;
    delete m_media;
}

void VlcManager::createMedia(const QString &ip, int port)
{
    m_media = new VlcMedia(buildMRL(ip, port), m_instance);
}

void VlcManager::clearMedia()
{
    if (m_media) {
        m_media->deleteLater();
    }

    m_media = nullptr;
}

void VlcManager::resetMedia(const QString &ip, int port)
{
    clearMedia();
    createMedia(ip, port);
}
