#include <QDataStream>
#include <QDebug>
#include "logwriter.h"

LogWriter::LogWriter(QString &filename)
    : outfile(NULL)
    , outdata(NULL) {
   outfile = new QFile(filename);
   outfile->open(QIODevice::WriteOnly);
   outdata = outfile;
   QDataStream out(outdata);
       qDebug() << out.device();
}

LogWriter::~LogWriter() {
    outdata = NULL;

    delete outfile;
    outfile = NULL;

    outfile->close();
}

void LogWriter::write(QByteArray buffer) {
    out.setDevice(outdata);

    qDebug() << out.device();
    out << buffer.data();
//    qDebug() << "2222222222222";
}
