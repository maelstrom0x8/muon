#ifndef MUON_H
#define MUON_H

#include <QFileInfo>
#include <taglib/fileref.h>
#include <taglib/taglib.h>

namespace muon {
class AudioInfo {
public:
  AudioInfo *operator()(const QString &filename);

  QString getTitle() const;
  QString getArtist() const;
  QString getFileName() const;

private:
  TagLib::FileRef ref;
  const char *_filename;
};

} // namespace muon

#endif