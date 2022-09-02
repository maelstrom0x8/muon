#include "muon.h"

muon::AudioInfo *muon::AudioInfo::operator()(const QString &filename) {
  auto str = filename.toLocal8Bit().data();
  _filename = TagLib::FileName(str);
  ref = TagLib::FileRef(_filename);

  return this;
}

QString muon::AudioInfo::getTitle() const {
  if (QString(ref.tag()->title().toCString()) == "")
    return QFileInfo(_filename).fileName();
  else
    return QString(ref.tag()->title().toCString());
}

QString muon::AudioInfo::getArtist() const {
  return QString(ref.tag()->artist().toCString()).toUtf8();
}

QString muon::AudioInfo::getFileName() const { return QString(_filename); }
