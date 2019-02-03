#include <QCoreApplication>
#include <logreader/log_slider.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LogSlider ls;
    ls.loadFile("0");

    return a.exec();
}
