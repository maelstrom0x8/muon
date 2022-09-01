#include "trackmodel.h"


muon::TrackModel::TrackModel(QAbstractListModel *parent)
    : QAbstractListModel(parent) {
  
}

int muon::TrackModel::rowCount(const QModelIndex& parent) const {
  return data_.size();
}


QVariant muon::TrackModel::data(const QModelIndex& index, int role) const {
  if(!index.isValid())
    return QVariant();
  if(index.row() >= data_.size())
    return QVariant();
  if(role == TitleRole)
    return data_[index.row()];
  if(role == ArtistRole)
    return data_[index.row()];
  
  return QVariant();
}

QHash<int, QByteArray> muon::TrackModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[TitleRole] = "title";
  roles[ArtistRole] = "artist";
  roles[FileRole] = "file";
  return roles;
}