#include "trackmodel.h"
#include <QDir>
#include <QDirIterator>

muon::TrackModel::TrackModel(QAbstractListModel *parent)
    : QAbstractListModel(parent) {
  folder = QDir::homePath().append("/Music");
  loadData(folder);
  info = new AudioInfo();
}

void muon::TrackModel::loadData(const QString &_folder) {
  beginResetModel();
  if (!audioItems.isEmpty()) {
    audioItems.clear();
  }
  auto _iter = QDirIterator(_folder, QStringList() << "*.mp3", QDir::Files,
                            QDirIterator::Subdirectories);
  while (_iter.hasNext()) {
    audioItems.emplace_back(_iter.next());
  }
  audioItems.sort();
  endResetModel();
}

int muon::TrackModel::rowCount(const QModelIndex &parent) const {
  return parent.isValid() ? 0 : audioItems.size();
}

QVariant muon::TrackModel::data(const QModelIndex &index, int role) const {
  auto item = audioItems[(index.row())];

  if (!index.isValid())
    return QVariant();
  if (index.row() >= audioItems.size())
    return QVariant();
  if (role == TitleRole)
    return (*info)(item)->getTitle();
  if (role == ArtistRole)
    return (*info)(item)->getArtist();
  if (role == FileRole)
    return (*info)(item)->getFileName();

  return QVariant();
}

QHash<int, QByteArray> muon::TrackModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[TitleRole] = "title";
  roles[ArtistRole] = "artist";
  roles[FileRole] = "file";
  return roles;
}

void muon::TrackModel::setCurrentIndex(const QModelIndex &index) {
  _currentIndex = index;
  emit currentIndexChanged(_currentIndex);
}

QModelIndex muon::TrackModel::currentIndex() const { return _currentIndex; }