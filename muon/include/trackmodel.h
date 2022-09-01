#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QAbstractListModel>
#include <utility>

namespace muon {
class TrackModel : public QAbstractListModel {
  Q_OBJECT
public:
  enum TrackItemRoles { TitleRole = Qt::UserRole + 1, ArtistRole, FileRole };

  explicit TrackModel(QAbstractListModel *parent=nullptr);
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

private:
  QStringList data_;
};
} // namespace muon

#endif