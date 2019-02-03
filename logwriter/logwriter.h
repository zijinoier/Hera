#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <QFile>
#include <QDataStream>
//#include <QThread>

class LogWriter
{
//    Q_OBJECT
public:
    LogWriter(QString& filename);
    ~LogWriter();

    void write(QByteArray buffer);

private:
    QFile* outfile;
    QIODevice* outdata;
    QString filename;
    QDataStream out;
};

#endif // LOGWRITER_H
