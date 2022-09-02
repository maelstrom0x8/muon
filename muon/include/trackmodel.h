#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include "muon.h"

#include <QAbstractListModel>

namespace muon {
class TrackModel : public QAbstractListModel {
  Q_OBJECT
public:
  enum TrackItemRoles { TitleRole = Qt::UserRole + 1, ArtistRole, FileRole };

  explicit TrackModel(QAbstractListModel *parent = nullptr);
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;
  QModelIndex currentIndex() const;

signals:
  void currentIndexChanged(const QModelIndex &index);

public slots:
  void setCurrentIndex(const QModelIndex &);
  void loadData(const QString &);

private:
  QStringList audioItems;
  QString folder;
  QModelIndex _currentIndex;
  AudioInfo *info;
};
} // namespace muon

#endif