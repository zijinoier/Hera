#ifndef LOG_SLIDER_H
#define LOG_SLIDER_H

#include <QString>
#include <iostream>
#include <string>
#include "player.h"

class LogSlider {

  public:
    LogSlider();
    void loadFile(QString filename);

  private:
    Player m_player;
    int m_currentFrame;
    bool m_stopped;

  private slots:
    void updateTime(int frame, double time);
};

#endif // LOG_SLIDER_H
