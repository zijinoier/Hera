#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <QFile>
#include <QDataStream>

//class LogWriter
//{
//public:
//    LogWriter(QString& filename);
//    ~LogWriter();

//    void write(QByteArray buffer);

//private:
//    QFile* outfile;
//    QIODevice* outdata;
//    QString filename;
//};

class LogWriter
{
public:
    LogWriter(QString &filename);
    ~LogWriter();

    void write(QByteArray buffer);
private:
    QFile* outfile;

};

#endif // LOGWRITER_H
