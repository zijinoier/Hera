#include <QDataStream>
#include <QDebug>
#include "logwriter.h"

//LogWriter::LogWriter(QString &filename)
//    : outfile(NULL)
//    , outdata(NULL) {
//   outfile = new QFile(filename);
//   outfile->open(QIODevice::WriteOnly);
//   outdata = outfile;
//}

//LogWriter::~LogWriter() {
//    outdata = NULL;

//    delete outfile;
//    outfile = NULL;
//}

//void LogWriter::write(QByteArray buffer) {
//    QDataStream out(outdata);

//    qDebug() << out.device();
//    out << buffer.data();
////    qDebug() << "2222222222222";
//}

LogWriter::LogWriter(QString &filename) : outfile(NULL) {
    outfile = new QFile(filename);
    outfile->open(QIODevice::WriteOnly);

}

LogWriter::~LogWriter() {
    delete outfile;
    outfile = NULL;
}

void LogWriter::write(QByteArray buffer) {
    outfile->write(buffer);
}
