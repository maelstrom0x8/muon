#include "muon.h"

muon::AudioInfo *muon::AudioInfo::operator()(const QString &filename) {
  auto str = filename.toLocal8Bit().data();
  _filename = TagLib::FileName(str);
  ref = TagLib::FileRef(_filename);

  return this;
}

QString muon::AudioInfo::getTitle() const {
  if (QString(ref.tag()->title().toCString()).isEmpty())
    return QFileInfo(_filename).fileName();
  else
    return QString(ref.tag()->title().toCString());
}

QString muon::AudioInfo::getArtist() const {
  auto title = QString(ref.tag()->artist().toCString()).toUtf8();
  if(title.isEmpty())
    return "<unknown>";
  return title;
}

QString muon::AudioInfo::getFileName() const { return QString(_filename); }
