#include <QDebug>
#include "logwriter.h"


LogWriter::LogWriter() : outfile(NULL) {

}

LogWriter::~LogWriter() {
    delete outfile;
    outfile = NULL;
}

void LogWriter::setFileName(QString &filename) {
    outfile = new QFile(filename);
    outfile->open(QIODevice::WriteOnly);
}

void LogWriter::write(QByteArray buffer) {
    outfile->write(buffer);
}
